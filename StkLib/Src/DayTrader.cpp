/*
	Cross Platform Core Code.

	Copyright(R) 2001-2002 Balang Software.
	All rights reserved.

	Using:
		Packet convertor functions;
*/

#include	"StdAfx.h"
#include	"../Include/DayTrader.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

#ifdef	_DEBUG
#define	new	DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
//	CDayTrader

CDayTrader::CDayTrader()
{
}

CDayTrader::~CDayTrader()
{
}

BOOL CDayTrader::SetMaxStocks( int nMaxStocks )
{
	if( nMaxStocks > 0 )
	{
		m_opparam.m_nStoreDiv	=	nMaxStocks;
		return TRUE;
	}
	return FALSE;
}

BOOL CDayTrader::BuyIt( CSPTime tmCur, CTechStock & techstock )
{
	OPRECORD record;
	memset( &record, 0, sizeof(record) );

	record.lOpType	=	STRATEGY_OPTYPE_BUY;

	record.bViewed		=	TRUE;
	record.time			=	tmCur.GetTime();
	record.dwMarket		=	techstock.m_info.GetMarket();
	strncpy( record.szCode, techstock.m_info.GetStockCode(),
			 min(sizeof(record.szCode)-1,strlen(techstock.m_info.GetStockCode())) );

	if( m_opparam.m_nStoreDiv-m_SimuStockOwn.GetSize() <= 0 )	// ��Ʊ�Ѿ������ˣ������������µ���
		return FALSE;
	double	dUseCash	=	m_SimuCurrentCash / (m_opparam.m_nStoreDiv-m_SimuStockOwn.GetSize());	// ��ʹ���ʽ�

	if( m_SimuCurrentCash < dUseCash )
		dUseCash	=	m_SimuCurrentCash;	// �ʽ𲻹������ж����ö���

	double dSharePrice = 0;
	if( !techstock.GetClosePrice( tmCur, &dSharePrice ) )
		return FALSE;
	double	dTemp	=	dSharePrice * ( 1 + m_rate.GetRate( techstock.m_info ) );
	if( fabs(dTemp) < 1e-4 || dUseCash < 1e-4 )
		return FALSE;

	DWORD	dwShare		=	(DWORD)( dUseCash / dTemp );	// �������
	dwShare		=	( dwShare / 100 ) * 100;		// ȡ��
	if( 0 == dwShare )
		return FALSE;

	record.dwShare		=	dwShare;
	record.dSharePrice	=	dSharePrice;
	record.dRateCost	=	record.dwShare * record.dSharePrice * m_rate.GetRate(techstock.m_info);
	return SimuOperate( record );
}

BOOL CDayTrader::SellIt( CSPTime tmCur, CTechStock & techstock )
{
	OPRECORD record;
	memset( &record, 0, sizeof(record) );

	record.lOpType	=	STRATEGY_OPTYPE_SELL;

	record.bViewed		=	TRUE;
	record.time			=	tmCur.GetTime();
	record.dwMarket		=	techstock.m_info.GetMarket();
	strncpy( record.szCode, techstock.m_info.GetStockCode(),
			 min(sizeof(record.szCode)-1,strlen(techstock.m_info.GetStockCode())) );

	double dSharePrice = 0;
	if( !techstock.GetClosePrice( tmCur, &dSharePrice ) )
		return FALSE;

	STOCKOWN	own;
	memset( &own, 0, sizeof(own) );
	if( !m_SimuStockOwn.HasThisStock( techstock.m_info, &own ) )
		return FALSE;
	DWORD	dwShare		=	own.dwShare;	// ��������

	record.dwShare		=	dwShare;
	record.dSharePrice	=	dSharePrice;
	record.dRateCost	=	record.dwShare * record.dSharePrice * m_rate.GetRate(techstock.m_info);
	return SimuOperate( record );
}

BOOL CDayTrader::SimuRun( SIMULATION_CALLBACK fnCallback, void * cookie )
{
	// ׼������
	if( !PrepareData( fnCallback, cookie ) )
		return FALSE;

	if( m_techstocks.GetSize() <= m_opparam.m_nStoreDiv )
	{
		SP_ASSERT( FALSE );
	}

	ClearLastIntensity( );
	
	int nCount = 0;
	int nSeperate = ::GetPrivateProfileInt( "DayTrader", "Seperate", 5, AfxGetProfile().GetWorkDirectory()+"DayTrader.ini" );
	char szGap[128];
	memset( szGap, 0, sizeof(szGap) );
	::GetPrivateProfileString( "DayTrader", "Gap", "5.0", szGap, sizeof(szGap)-2, AfxGetProfile().GetWorkDirectory()+"DayTrader.ini" );
	double dGap = atof(szGap);

	do	{
		CSPTime	tmCur	=	SimuGetCurrentTime();	// ģ�⵱ǰʱ��

		int nMaxDiffPercent = -1;
		double dMaxDiffPercent = -100;	// ����Ƿ�%
		int nMinDiffPercent = -1;
		double dMinDiffPercent = 100;	// ������%

		// Find
		for( int i=0; i<m_techstocks.GetSize(); i++ )	// ÿֻ��Ʊ�����ж�
		{
			CTechStock & techstock	=	m_techstocks.ElementAt(i);

			if( techstock.IsStopTrading(tmCur) )	// ͣ����
				continue;

			// Judge Whether to operate, if yes, save to nextop
			STOCKOWN	own;
			memset( &own, 0, sizeof(own) );
			if( m_SimuStockOwn.HasThisStock( techstock.m_info, &own ) )	// ����Ѿ�����֧��Ʊ���ж��Ƿ�����
			{
				if( m_SimuStockOwn.GetSize() >= m_opparam.m_nStoreDiv )
				{
					double dDiffPercent;
					if( techstock.GetCloseDiffPercent( tmCur, &dDiffPercent )
						&& (dDiffPercent > dMaxDiffPercent || -1 == nMaxDiffPercent) )
					{
						dMaxDiffPercent = dDiffPercent;
						nMaxDiffPercent = i;
					}
				}
			}
			else if( m_SimuStockOwn.GetSize() <= m_opparam.m_nStoreDiv )
			{
				double dDiffPercent;
				if( techstock.GetCloseDiffPercent( tmCur, &dDiffPercent )
					&& (dDiffPercent < dMinDiffPercent || -1 == nMinDiffPercent) )
				{
					dMinDiffPercent = dDiffPercent;
					nMinDiffPercent = i;
				}
			}
		}

		// operate
		if( -1 != nMaxDiffPercent && -1 != nMinDiffPercent )
		{
			double dRate = m_rate.GetRate( m_techstocks.ElementAt(nMaxDiffPercent).m_info )
							+ m_rate.GetRate( m_techstocks.ElementAt(nMinDiffPercent).m_info );
			if( dMaxDiffPercent - dMinDiffPercent <= dGap + dRate * 100 )
			{
				nMaxDiffPercent = nMinDiffPercent = -1;
			}
		}

		nCount ++;
		if( -1 != nMaxDiffPercent && -1 != nMinDiffPercent && nCount >= nSeperate )
		{
			nCount = 0;
			SellIt( tmCur, m_techstocks.ElementAt(nMaxDiffPercent) );
		}
		if( -1 != nMinDiffPercent )
			BuyIt( tmCur, m_techstocks.ElementAt(nMinDiffPercent) );


		// ������ʾ
		DWORD	dwProgress	=	SimuGetCurrentProgress( STRATEGY_MAX_PROGRESS );
		double	dYield		=	SimuGetCurrentYield( );
		if( fnCallback && !fnCallback( SIMULATION_PROGRESS, dwProgress, NULL, cookie ) )
			return FALSE;
		if( fnCallback && !fnCallback( SIMULATION_YIELD, (DWORD)dYield, NULL, cookie ) )
			return FALSE;

	} while( SimuGotoNextTime() );	// ģ�����һ��������

	if( fnCallback )
		fnCallback( SIMULATION_PROGRESS, STRATEGY_MAX_PROGRESS, NULL, cookie );
	return TRUE;
}


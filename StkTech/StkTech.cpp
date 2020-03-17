// StkTech.cpp : Defines the entry point for the DLL application.
//

#include "stdafx.h"
#include "StkTech.h"
#include "Stock.h"
#include "TechUser.h"

BOOL APIENTRY DllMain( HANDLE hModule, 
                       DWORD  ul_reason_for_call, 
                       LPVOID lpReserved
					 )
{
    switch (ul_reason_for_call)
	{
		case DLL_PROCESS_ATTACH:
		case DLL_THREAD_ATTACH:
		case DLL_THREAD_DETACH:
		case DLL_PROCESS_DETACH:
			break;
    }
    return TRUE;
}

/*
 *  ���ܣ�	���ʵ�ֵ����ָ���ܸ���
 *  ����ֵ��ʵ�ֵ����ָ���ܸ���
 */
TECHUSER_API UINT WINAPI GetTechUserCount()
{
	return 1;
}

/*
 *  ���ܣ�	���ָ����Ϣ
 *  nID:	ָ���ʶ������ 0 <= nID < GetTechUserCount()
 *  pInfo:	������Ϣ
 *  ����ֵ��TRUE�ɹ���FALSEʧ��
 */
TECHUSER_API BOOL WINAPI GetTechUserInfo( UINT nID, PTECHUSER_INFO pInfo )
{
	switch( nID )
	{
	case 0:
		strcpy( pInfo->m_szName, "���ָ��" );
		strcpy( pInfo->m_szShortName, "WGZB" );
		pInfo->m_nLineCount	=	1;
		strcpy( pInfo->m_aszLineName[0], "LINE1" );
		pInfo->m_bAutoMA	=	TRUE;
		pInfo->m_nMADays	=	6;
		pInfo->m_itsGoldenFork	=	ITS_BUY;
		pInfo->m_itsDeadFork	=	ITS_SELL;
		return TRUE;
	default:;
	}
	return FALSE;
}

/*
 *  ���ܣ�	����ָ��ֵ
 *  nID:	ָ���ʶ������ 0 <= nID < GetTechUserCount()
 *  pInfo:	�������ݣ������������ؼ�������Ϣ
 *  ����ֵ��TRUE�ɹ���FALSEʧ��
 */
TECHUSER_API BOOL WINAPI Calculate( UINT nID, PCALCULATE_INFO pInfo )
{
	CKData * pKData = pInfo->m_pKData;
	int nIndex = pInfo->m_nIndex;

	switch( nID )
	{
	case 0:
		{	// 10��OSCָ��
			double	dCt = pKData->ElementAt(nIndex).m_fClose;
			double	dMA = 0;
			int	nCount	=	0;
			for( int k=nIndex; k>=0; k-- )
			{
				dMA	+=	pKData->ElementAt(k).m_fClose;

				nCount	++;
				if( nCount == 10 )
				{
					dMA	=	dMA / 10;
					if( dMA < 1e-4 )
						return FALSE;
					pInfo->m_dValue1	=	(dCt/dMA);
					return TRUE;
				}
			}
			return FALSE;
		}		
	default:;
	}
	return FALSE;
}

/*
 *  ���ܣ�	��������ź�
 *  nID:	ָ���ʶ������ 0 <= nID < GetTechUserCount()
 *  pInfo:	�������ݣ������������ؼ�������Ϣ
 *  ����ֵ��TRUE�ɹ���FALSEʧ��
 */
TECHUSER_API BOOL WINAPI GetSignal( UINT nID, PCALCULATE_INFO pInfo )
{
	switch( nID )
	{
	case 0:
		//if( ... )
		//	pInfo->m_nSignal	=	ITS_BUY;
		//if( ... )
		//	pInfo->m_nSignal	=	ITS_SELL;
		pInfo->m_nSignal	=	ITS_NOTHING;
		break;
	default:;
	}
	return TRUE;
}


/*
	Cross Platform Core Code.

	Copyright(R) 2001-2002 Balang Software.
	All rights reserved.

	Using:
		some afx-global-functions
*/

#if	!defined( __STKLIB_AFXCORE_H__ )
#define	__STKLIB_AFXCORE_H__

////////////////////////////////////////////////////////////////////////////////////
// Chinese To English Translation
STKLIB_API	BOOL AfxIsEnglish( const char * sz, int maxlen, float ratio = 0.0 );
STKLIB_API	CSPString AfxFaintlyChsToEnu( const char * szCh );
STKLIB_API	CSPString AfxMakeSpellCode( CSPString & strSrc, int nMode = 0x0001 );

////////////////////////////////////////////////////////////////////////////////////
// global data
STKLIB_API	CStProfile &		AfxGetProfile( );
STKLIB_API	CStockContainer &	AfxGetStockContainer( );
STKLIB_API	CStockContainer &	AfxGetSListStockContainer( );
STKLIB_API	CDomainContainer &	AfxGetDomainContainer( );
STKLIB_API	CDomainContainer &	AfxGetGroupContainer( );
STKLIB_API	CStDatabase &		AfxGetDB();
STKLIB_API	void AfxSetDB(CStDatabase * pdb);
STKLIB_API	CStock &			AfxGetStockMain(DWORD dwMarket=CStock::marketSHSE);

////////////////////////////////////////////////////////////////////////////////////
// database functions
STKLIB_API	BOOL	AfxInitializeDB( LPSTR lpBuf, UINT nMaxSize );
STKLIB_API	BOOL	AfxReleaseDB( );
STKLIB_API	BOOL	AfxReloadStockMain( );
STKLIB_API	BOOL	AfxReloadStock( CStock & stock );
STKLIB_API	BOOL	AfxPrepareStockData( CStDatabase * pDatabase, CStock &stock, int nKType, int nKFormat, int nMaindataType, BOOL bFullFill, BOOL bReload );
STKLIB_API	int		AfxRefreshStockContainerMinute( CStockContainer & container, LONG lStockType, int nSecondsToRead = -1 );

////////////////////////////////////////////////////////////////////////////////////
// usful functions
STKLIB_API	CSPString	AfxGetTimeString( time_t time, LPCTSTR lpszTimeFmt, BOOL bAddWeekDay );
STKLIB_API	CSPString	AfxGetReportTypeString( int reporttype );
STKLIB_API	CSPString	AfxGetFileDirectory( CSPString strPathName, CSPString strDefault );
STKLIB_API	CSPString	AfxGetFilePath( CSPString strDir, CSPString strFileTitle );


////////////////////////////////////////////////////////////////////////////////////
// ���º���ʵ������ Strings.cpp

STKLIB_API	CSPString	AfxGetKTypeString( int ktype );
STKLIB_API	CSPString	AfxGetMaindataTypeString( int type );

STKLIB_API	CSPString	AfxGetSTTName( UINT nTech );		// ��������ָ��Ψһ��ţ��õ�ָ����������
STKLIB_API	CSPString	AfxGetSTTShortName( UINT nTech );	// ��������ָ��Ψһ��ţ��õ�ָ��Ӣ�ļ��
STKLIB_API	CSPString	AfxGetSTTFullName( UINT nTech );	// ��������ָ��Ψһ��ţ��õ�ָ����������+Ӣ�ļ��
STKLIB_API	CSPString	AfxGetSTTClassName( UINT nTech );	// ��������ָ��Ψһ��ţ��õ�ָ���������࣬�磺�����ࡢ������
STKLIB_API	CSPString	AfxGetIntensityString( int nIntensity );	// ���������ź�ֵ���õ�����˵��
STKLIB_API	CSPString	AfxGetIntensityCodeString( UINT nCode );	// ���������ź�����˵��ֵ���õ�����˵��

STKLIB_API	CSPString	AfxGetSLHTitle( UINT nSLH );		// ������Ʊ�б��кţ�����������
STKLIB_API	CSPString	AfxGetSLHDescript( UINT nSLH );		// ������Ʊ�б��кţ�������˵��

STKLIB_API	void	AfxGetAllDistrict( CSPStringArray & astr );	// ������й��Һ͵��������б�

#define		ACCE_MIN	1
#define		ACCE_01		1	// �ȼ�F1
#define		ACCE_02		2	// �ȼ�F2
#define		ACCE_03		3	// �ȼ�F3
#define		ACCE_04		4	// �ȼ�F4
#define		ACCE_05		5	// �ȼ�F5
#define		ACCE_06		6	// �ȼ�F6
#define		ACCE_07		7	// �ȼ�F7
#define		ACCE_08		8	// �ȼ�F8
#define		ACCE_09		9	// �ȼ�F9
#define		ACCE_10		10	// �ȼ�F10
#define		ACCE_1		11	// ��A����
#define		ACCE_2		12	// ��B����
#define		ACCE_3		13	// ��A����
#define		ACCE_4		14	// ��B����
#define		ACCE_5		15	// ��ծ����
#define		ACCE_6		16	// ��ծ����
#define		ACCE_61		17	// ��A�ǵ�
#define		ACCE_62		18	// ��B�ǵ�
#define		ACCE_63		19	// ��A�ǵ�
#define		ACCE_64		20	// ��B�ǵ�
#define		ACCE_65		21	// ��ծ�ǵ�
#define		ACCE_66		22	// ��ծ�ǵ�
#define		ACCE_71		23	// ��֤��Ϣ
#define		ACCE_72		24	// ��֤��Ϣ
#define		ACCE_73		25	// ȯ����Ϣ
#define		ACCE_81		26	// ��A�ۺ�
#define		ACCE_82		27	// ��B�ۺ�
#define		ACCE_83		28	// ��A�ۺ�
#define		ACCE_84		29	// ��B�ۺ�
#define		ACCE_85		30	// ��ծ�ۺ�
#define		ACCE_86		31	// ��ծ�ۺ�
#define		ACCE_LBDK	32	// ��ʾ��ʱ�������ȶ��ָ��
#define		ACCE_MMLD	33	// ��ʾ��ʱ������������ָ��
#define		ACCE_MAX	33
STKLIB_API	CSPString	AfxGetAccelerator( UINT nAcce, int nCharLeft = 8 );	// ������ݼ���ţ����ؿ�ݼ�������������


// End
////////////////////////////////////////////////////////////////////////////////////

#endif // __STKLIB_AFXCORE_H__

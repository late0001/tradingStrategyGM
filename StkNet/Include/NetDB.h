/*
	Cross Platform Core Code.

	Copyright(R) 2001-2002 Balang Software.
	All rights reserved.

	Using:
		class	CCodeTable;
		class	CNetDatabase;
*/

#ifndef	__ND_STKNET_NETDB_H__
#define __ND_STKNET_NETDB_H__

#include "XMLDoc.h"
#include "QSProfile.h"

class	CPackages;

/***
	���ݰ��࣬��ʾһ�����ݰ�
*/
class STKNET_API CPackage : public CXMLNode
{
public:
	CPackage( );
	CPackage( const CPackage &src );
	virtual ~CPackage( );

	enum PackageTypes {
		packageUnknown	=	0x00,
		packageCode		=	0x01,
		packageDay		=	0x02,
		packageMin5		=	0x03,
		packageDR		=	0x04,
		packageBasetext	=	0x05,
		packageBasetable=	0x06,
	};

	// virtual operation
	virtual	BOOL	SetAttribute( CMarkup & markup );

	CPackage & operator = ( const CPackage &src );
	BOOL operator<(CPackage& p) const;

	CString GetURL( CString strBasePath );	// �����ݰ���URL
	BOOL	HasAlternateURL( ) const;		// �����ݰ��Ƿ������URL
	CString	GetAlternateURL( CString strBasePath );		// �����ݰ������URL

	BOOL	HasExpandPackage( ) const;		// �����ݰ��Ƿ�����չ�����ݰ�
	BOOL	ExpandYearPackage( CString strMonthfmt, CString strDayfmt, int nYear );	// �������ݰ���չ��12���·ݷ����ݰ�
	BOOL	ExpandMonthPackage( CString strDayfmt, int nYear, int nMonth );			// �������ݰ���չ���շ����ݰ�
	CPackages * GetExpandPackages( );		// �õ���չ���ݰ�
	void	DeleteExpandPackages( );		// �ͷ���չ���ݰ�
	
	CString		m_strURL;
	CString		m_strAlternateURL;
	int			m_nType;
	CSPTime		m_tmFrom;
	CSPTime		m_tmTo;
	int			m_nLength;
	CString		m_strDescript;
	BOOL		m_bIsZipped;
	BOOL		m_bIsTimefmt;

	// temp data
	BOOL		m_bDownloadOK;
	CString		m_strLocalFilename;
	CPackages * m_pExpandPackages;
};

typedef CArray<CPackage, CPackage &>	CPackageArray;

/***
	���ݰ�����
*/
class STKNET_API CPackages : public CPackageArray
{
public:
	CPackages( );
	virtual ~CPackages( );

	void	Clear( );
	BOOL	IsOK( );
	BOOL	SetRawXMLDocument( CString &strDoc );		// �趨ԭʼXML�ĵ��������������ݰ���Ϣ
	virtual	BOOL	SetAttribute( CMarkup & markup );	// �趨���ݰ�������ۺ���Ϣ
	BOOL	AddSmartAdditional( );		// Ϊûһ�����ݰ��Զ�������չ���ݰ�
	BOOL	ExtractFromXMLDoc( );		// ��ȡ���ݰ���Ϣ
	void	Sort( );					// ���ݰ���ʱ������

	void	AppendPackages( CPackages * psrc );

	BOOL	GetLatestTime( CSPTime &tm, int packagetype );
	virtual	BOOL	GetLastErrorMessage(LPTSTR lpszError, UINT nMaxError);

public:
	BOOL			m_bIsOK;
	CXMLDocument	m_xmlDocument;

	CString			m_strVersion;
	int				m_nDataVersion;
	CString			m_strBasePath;
	CString			m_strYearfmt;
	CString			m_strMonthfmt;
	CString			m_strDayfmt;
	CString			m_strInfo;
	CString			m_strInfourl;
	CString			m_strLatestver;
};

/***
	��Ʒ��������Ϣ�࣬��ʾһ����Ʒ������
*/
class STKNET_API CDownloadServer : public CXMLNode
{
public:
	CDownloadServer( ) { };
	CDownloadServer( const CDownloadServer &src );
	virtual ~CDownloadServer( ) { };

	// virtual operation
	CDownloadServer & operator = ( const CDownloadServer & src );

	virtual	BOOL	SetAttribute( CMarkup & markup );
	BOOL	FromString( CString	string );
	CString	AsString( );

	CString	m_strAddress;
	UINT	m_nPort;
	CString	m_strDescript;
};

typedef	CArray<CDownloadServer, CDownloadServer &>	CDownloadServerArray;

BOOL	AliasSetAttribute( CMarkup & markup, CAlias & alias );
BOOL	QuoteServerSetAttribute( CMarkup & markup, CQuoteServer & qs );

/***
	��Ʒ����������
*/
class STKNET_API CServers
{
public:
	CServers( );
	virtual ~CServers( );

	void	Clear( );
	BOOL	IsOK( );
	BOOL	SetRawXMLDocument( CString &strDoc );
	virtual	BOOL	SetAttribute( CMarkup & markup );
	BOOL	ExtractFromXMLDoc( );

	virtual	BOOL	GetLastErrorMessage(LPTSTR lpszError, UINT nMaxError);
	
	BOOL	SaveToProfile( );

public:
	BOOL			m_bIsOK;
	CXMLDocument	m_xmlDocument;

	CString			m_strVersion;
	
	CDownloadServerArray	m_aDownloadServers;
	CQuoteServerArray		m_aQuoteServers;
	CAliasArray				m_aAliases;
};

#define	ERR_NETDB_HTTPCLIENT	ERR_DB_MAX+1
#define	ERR_NETDB_PACKAGES		ERR_DB_MAX+2
#define	ERR_NETDB_SERVERS		ERR_DB_MAX+3
#define	ERR_NETDB_ZIPDLL		ERR_DB_MAX+4
#define	ERR_NETDB_ZIP			ERR_DB_MAX+5

#define	PROG_HTTPCONNECTTING	PROG_PROGRESS+1
#define	PROG_REQUESTSENT		PROG_PROGRESS+2
#define	PROG_REDIRECTING		PROG_PROGRESS+3
#define	PROG_TRANSFERRING		PROG_PROGRESS+4
#define	PROG_INSTALLPACKAGE		PROG_PROGRESS+5
#define	PROG_EXTRACTZIPFILES	PROG_PROGRESS+6
#define	PROG_ERRORPAC			PROG_PROGRESS+7

#define	PROG_NEWGROUP			PROG_PROGRESS+8
#define	PROG_NEWGROUPMSG		PROG_PROGRESS+9

/***
	���������࣬�ṩ�Դ������ݵĲ����ӿڣ�������Ʊ��Ϣ����������K�����ݣ�����
	���ϣ�ȨϢ���ϵĶ�ȡ�Ͱ�װ��
	
	ʹ�÷������£�
	CStDatabase::CreateSelfDB( "./" );

	CNetDatabase	db;
	db.SetRootPath( "./", IStStore::typeSelfDB );


	CStockContainer container;
	nLen	=	db.LoadCodetable( container );
	db.LoadBasetable( container );
	db.LoadKDataCache( container, NULL, NULL, 0, 0 );

	CStock	stock;
	stock.SetDatabase( &db );
	stock.PrepareData( CStock::dataK, CKData::ktypeDay );
	stock.PrepareData( CStock::dataDR );
	stock.PrepareData( CStock::dataK, m_nCurKType );
	CStockInfo	& info	=	stock.GetStockInfo();
	CKData	& kday	=	stock.GetKDataDay();
	CKData	& kdata	=	stock.GetKData(m_nCurKType);
	kday.SetDRData( stock.GetDRData() );
	kday.ChangeCurFormat( CKData::formatXDRdown, AfxGetProfile().GetAutoResumeDRBegin(), AfxGetProfile().GetAutoResumeDRLimit() );

	ע�⣺�븸��CStDatabase���÷���ͬ
*/
class STKNET_API CNetDatabase : public CStDatabase
{
public:
	CNetDatabase();
	virtual ~CNetDatabase();

	BOOL SetServer( LPCTSTR lpszServer, INTERNET_PORT port = INTERNET_DEFAULT_HTTP_PORT );	// �趨������
	BOOL SetAccessType( int nAccessType, int nProxyType, LPCTSTR lpszProxyAddress, UINT nProxyPort,
								LPCSTR lpszProxyUser, LPCTSTR lpszProxyPasswd );	// �趨����ѡ��
	BOOL Login( LPCTSTR lpszRegCode, LPCTSTR lpszUserName, LPCTSTR lpszPasswd, LPCTSTR lpszVersion );	// ��½������
	BOOL Logout( );		// �˳���½

	BOOL	NetloadPackageInfo( PROGRESS_CALLBACK fnCallback, void *cookie );	// �������������ݰ���Ϣ�ļ�(.xml)
	BOOL	NetloadServerInfo( PROGRESS_CALLBACK fnCallback, void *cookie );	// ���������ط�������Ϣ�ļ�(.xml)
	int		NetloadCodetbl( PROGRESS_CALLBACK fnCallback, void *cookie );		// ���������ع�Ʊ�����
	int		NetloadDayKLine( LPCTSTR lpszStockCode, CSPTime *ptmFrom, CSPTime *ptmTo, PROGRESS_CALLBACK fnCallback, void *cookie );		// ������������K������
	int		Netload5MinKLine( LPCTSTR lpszStockCode, CSPTime *ptmFrom, CSPTime *ptmTo, PROGRESS_CALLBACK fnCallback, void *cookie );	// ����������5����K������
	int		NetloadDRData( LPCTSTR lpszStockCode, CSPTime *ptmFrom, CSPTime *ptmTo, PROGRESS_CALLBACK fnCallback, void *cookie );		// ���������س�Ȩ��Ϣ����
	int		NetloadBasetext( LPCTSTR lpszStockCode, CSPTime *ptmFrom, CSPTime *ptmTo, PROGRESS_CALLBACK fnCallback, void *cookie );		// ����������F10���������ı�
	int		NetloadBasetable( LPCTSTR lpszStockCode, CSPTime *ptmFrom, CSPTime *ptmTo, PROGRESS_CALLBACK fnCallback, void *cookie );		// ���������ز������ϱ�

	int		NetloadPackage( int nPackageType, CSPTime &tmFrom, CSPTime &tmTo, PROGRESS_CALLBACK fnCallback, void *cookie );	// �������ͺ���ֹ���ڴ������������ݰ�

	BOOL	GetLatestTimeNet( CSPTime &tm, int packagetype );		// �õ����������������������

	CServers	& GetServers( );	// �õ����з������б�
	CPackages	& GetPackages( );	// �õ��������ݰ��б�

	// CStDatabase virtual functions
	virtual	BOOL	GetLastErrorMessage(LPTSTR lpszError, UINT nMaxError);	// �õ����������Ϣ

	static	CString	GetProgressMessage(UINT nProgressCode);	// �õ�����˵��
	
	virtual	int	GetMaxStockNumber( );		// �õ���Ʊ����
	virtual	int	LoadCodetable( CStockContainer & container );	// ��ȡ���й�Ʊ����Ϣ
	virtual	int	LoadBaseText( CStock *pstock );					// ��ȡĳһ��Ʊ�Ļ��������ı�
	virtual	int	LoadKData( CStock *pstock, int period );		// ��ȡĳһ��Ʊ��ĳ�����ڵ�K������
	virtual	int	LoadDRData( CStock *pstock );					// ��ȡĳһ��Ʊ�ĳ�Ȩ��Ϣ����

	BOOL	InstallPackageEx( CPackage &pac, const char *zipfilename,
								PROGRESS_CALLBACK fnCallback, void *cookie );	// ��װ���ݰ�
	BOOL	InstallPackagePath( CPackage &pac, const char *path,
								PROGRESS_CALLBACK fnCallback, void *cookie,
								int nTotalCount, int nFinishCount, BOOL bDeleteAfterInstall = TRUE );
	BOOL	InstallPackage( CPackage &pac, const char *filename,
								PROGRESS_CALLBACK fnCallback, void *cookie );

	BOOL	EmptyTempDirectory( LPCTSTR lpszPath = NULL );						// ���ĳ��Ŀ¼
	static	int		GetFileCount( const char * path, BOOL bRecurse = TRUE );	// �õ�ĳ��Ŀ¼�µ��ļ�����

protected:
	BOOL	GetTempFile( CString &rString );
	BOOL	RemoveTempFile( CString sFileName );
	BOOL	OpenTempFile( CFile &file );
	BOOL	CloseAndRemoveTempFile( CFile &file );
	BOOL	GetTempNewDirectory( CString &sTempNewDir );
	BOOL	RemoveTempNewDirectory( CString sTempNewDir );

protected:
	CPackages		m_packages;
	CServers		m_servers;
	CHttpClient		m_httpClient;
};

#endif //__ND_STKNET_NETDB_H__

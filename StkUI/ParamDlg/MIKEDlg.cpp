// MIKEDlg.cpp : implementation file
//

#include "stdafx.h"
#include "MIKEDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CMIKEDlg dialog


CMIKEDlg::CMIKEDlg(CWnd* pParent, CMIKE * pMIKE )
{
	CParamDlg::CParamDlg(CMIKEDlg::IDD, pParent);

	//{{AFX_DATA_INIT(CMIKEDlg)
	m_nDays = 0;
	//}}AFX_DATA_INIT

	m_pMIKE	=	pMIKE;
}


void CMIKEDlg::DoDataExchange(CDataExchange* pDX)
{
	CParamDlg::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CMIKEDlg)
	DDX_Control(pDX, IDC_STATIC_NAME, m_staticName);
	DDX_Text(pDX, IDC_DAYS, m_nDays);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CMIKEDlg, CParamDlg)
	//{{AFX_MSG_MAP(CMIKEDlg)
	ON_BN_CLICKED(IDC_DEFAULT, OnDefault)
	ON_BN_CLICKED(IDC_PARAMHELP, OnHelp)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMIKEDlg message handlers

BOOL CMIKEDlg::OnInitDialog() 
{
	CParamDlg::OnInitDialog();
	
	ASSERT( m_pMIKE );

	// TODO: Add extra initialization here
	RefreshData( FALSE );

	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CMIKEDlg::OnCancel() 
{
}

void CMIKEDlg::OnOK() 
{
	// TODO: Add extra validation here
	if( !RefreshData( TRUE ) )
		m_pMIKE->SetDefaultParameters( );

	CParamDlg::OnOK();
}

void CMIKEDlg::OnDefault() 
{
	// TODO: Add your control notification handler code here
	m_pMIKE->SetDefaultParameters( );
	RefreshData( FALSE );
}

void CMIKEDlg::OnHelp() 
{
	ParamHelp( STT_MIKE );
}

BOOL CMIKEDlg::RefreshData( BOOL bSaveAndValidate )
{
	if( !m_pMIKE->IsValidParameters() )
		m_pMIKE->SetDefaultParameters();

	if( bSaveAndValidate )
	{
		UpdateData( TRUE );
		
		m_pMIKE->m_nDays	=	m_nDays;
		return m_pMIKE->IsValidParameters();
	}
	else
	{
		m_staticName.SetWindowText( AfxGetSTTFullName(STT_MIKE) );

		m_nDays		=	m_pMIKE->m_nDays;
		UpdateData( FALSE );
	}

	return TRUE;
}


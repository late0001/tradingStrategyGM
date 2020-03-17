#if !defined(AFX_DMIDLG_H__0BB26BA5_C279_4BDF_B7D7_729E3B3F0430__INCLUDED_)
#define AFX_DMIDLG_H__0BB26BA5_C279_4BDF_B7D7_729E3B3F0430__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// DMIDlg.h : header file
//
#include "SetParamDlg.h"
/////////////////////////////////////////////////////////////////////////////
// CDMIDlg dialog

class CDMIDlg : public CParamDlg
{
// Construction
public:
	CDMIDlg(CWnd* pParent,CDMI *pDMI);   // standard constructor

	CDMI	*	m_pDMI;
	virtual	BOOL	RefreshData( BOOL bSaveAndValidate );

// Dialog Data
	//{{AFX_DATA(CDMIDlg)
	enum { IDD = IDDP_DMI };
	CStatic	m_staticName;
	long	m_nDays;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDMIDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CDMIDlg)
	virtual BOOL OnInitDialog();
	virtual void OnCancel();
	virtual void OnOK();
	afx_msg void OnDefault();
	afx_msg void OnHelp();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DMIDLG_H__0BB26BA5_C279_4BDF_B7D7_729E3B3F0430__INCLUDED_)

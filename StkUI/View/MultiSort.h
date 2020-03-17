// MultiSort.h : interface of the CMultiSort class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_MULTISORT_H__0A8D66A9_30E0_4AAA_8E17_06B721FC0E97__INCLUDED_)
#define AFX_MULTISORT_H__0A8D66A9_30E0_4AAA_8E17_06B721FC0E97__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/***
	��ͼ�࣬���𻭳��ۺ�����ͼ�е����в���
*/
class CMultiSort
{
public:
	CMultiSort( );
	virtual	~CMultiSort( );
	void		SetParent( CWnd * pParent );

	enum SelectArea {
		areaNone		=	0x00,
		areaRise		=	0x01,
		areaFall		=	0x02,
		areaDiff		=	0x03,
		areaRiseMin5	=	0x04,
		areaFallMin5	=	0x05,
		areaVolRatio	=	0x06,
		areaBSRatioAsc	=	0x07,
		areaBSRatioDesc	=	0x08,
		areaAmount		=	0x09,
	};
	
	void		SetMultiSortClass( LONG type );
	LONG		GetMultiSortClass( );
	BOOL		RecalculateSortID( BOOL bReloadMinute, BOOL bUpdateWindow );
	BOOL		RecalculateSortID( PCOMMPACKET pPacket );
	void		Redraw( CDC * pDC, CRect rectAll );

public:
	// ˢ��ʵʱ��������
	LRESULT		OnStkReceiverData( WPARAM wParam, LPARAM lParam );

	void		OnLButtonDown( UINT nFlags, CPoint point, BOOL bShiftPressed, BOOL bCtrlPressed );
	void		OnLButtonDblClk( UINT nFlags, CPoint point );


protected:
	void		ResetClient( CRect rectAll );

	int			GetClickPos( CRect rect, CPoint point );
	void		DrawSelection( CDC * pDC, int nSelectArea, int nSelectPos, COLORREF clr );

	void		DrawMultiSort( CDC * pDC, CSPDWordArray &adwSortID, CRect rect, UINT nSLH, int nSelectPos );
	void		DrawMultiSort( CDC * pDC, MULTISORT &ms, CRect rect, UINT nSLH, int nSelectPos );
	void		DrawRise( CDC * pDC, CRect rect );
	void		DrawFall( CDC * pDC, CRect rect );
	void		DrawDiff( CDC * pDC, CRect rect );
	void		DrawRiseMin5( CDC * pDC, CRect rect );
	void		DrawFallMin5( CDC * pDC, CRect rect );
	void		DrawVolRatio( CDC * pDC, CRect rect );
	void		DrawBSRatioAsc( CDC * pDC, CRect rect );
	void		DrawBSRatioDesc( CDC * pDC, CRect rect );
	void		DrawAmount( CDC * pDC, CRect rect );
protected:
	CWnd	*	m_pParent;			// ������
	LONG		m_lMultiSortClass;

	CRect		m_rectAll;			// ����Rect

	CRect		m_rectRise;			// �����Ƿ���������
	CRect		m_rectFall;			// ���յ�����������
	CRect		m_rectDiff;			// ���������������
	
	CRect		m_rectRiseMin5;		// 5�����Ƿ���������
	CRect		m_rectFallMin5;		// 5���ӵ�����������
	CRect		m_rectVolRatio;		// 5���������������
	
	CRect		m_rectBSRatioAsc;	// ����ί��ǰ��������
	CRect		m_rectBSRatioDesc;	// ����ί�Ⱥ���������
	CRect		m_rectAmount;		// �����ܽ����������

	CSPDWordArray	m_adwRise;
	CSPDWordArray	m_adwFall;
	CSPDWordArray	m_adwDiff;
	CSPDWordArray	m_adwRiseMin5;
	CSPDWordArray	m_adwFallMin5;
	CSPDWordArray	m_adwVolRatio;
	CSPDWordArray	m_adwBSRatioAsc;
	CSPDWordArray	m_adwBSRatioDesc;
	CSPDWordArray	m_adwAmount;

	int			m_nSelectArea;
	int			m_nSelectPos;

	enum RefreshMode {
		modeSort	=	0x01,
		modeDirect	=	0x02,
	};
	int			m_nRefreshMode;

	MULTISORT	m_msRise;
	MULTISORT	m_msFall;
	MULTISORT	m_msDiff;
	MULTISORT	m_msRiseMin5;
	MULTISORT	m_msFallMin5;
	MULTISORT	m_msVolRatio;
	MULTISORT	m_msBSRatioAsc;
	MULTISORT	m_msBSRatioDesc;
	MULTISORT	m_msAmount;
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MULTISORT_H__0A8D66A9_30E0_4AAA_8E17_06B721FC0E97__INCLUDED_)

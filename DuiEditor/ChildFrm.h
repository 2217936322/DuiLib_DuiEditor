
// ChildFrm.h : CChildFrame ��Ľӿ�
//

#pragma once

class CChildFrame : public CMDIChildWndEx
{
	DECLARE_DYNCREATE(CChildFrame)
public:
	CChildFrame();

// ����
public:
	CMFCToolBar			m_wndToolBar;
	CMFCStatusBar	m_wndStatusBar;
	CRect m_rcView;

	int m_nCurrentView;
// ����
public:

// ��д
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);

// ʵ��
public:
	virtual ~CChildFrame();

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnMDIActivate(BOOL bActivate, CWnd* pActivateWnd, CWnd* pDeactivateWnd);
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnSize(UINT nType, int cx, int cy);
	afx_msg void OnDesignerView();
	afx_msg void OnUpdateDesignerView(CCmdUI *pCmdUI);
	afx_msg void OnDesignerCode();
	afx_msg void OnUpdateDesignerCode(CCmdUI *pCmdUI);
};

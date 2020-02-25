#pragma once



// CImageEditorView ��ͼ

class CImageEditorView : public CScrollView
{
	DECLARE_DYNCREATE(CImageEditorView)

public:
	CImageEditorView();           // ��̬������ʹ�õ��ܱ����Ĺ��캯��
	virtual ~CImageEditorView();

public:
	void SetImage(LPCTSTR strImageInfo, CRect &rcImg);

	CPaintManagerUI *m_pManager;
	TDrawInfo m_drawInfo;

	CRect m_rcImage;
	double m_zoom;
protected:
	virtual void OnDraw(CDC* pDC);      // ��д�Ի��Ƹ���ͼ
	virtual void OnInitialUpdate();     // �����ĵ�һ��

	DECLARE_MESSAGE_MAP()
public:
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
	afx_msg BOOL OnMouseWheel(UINT nFlags, short zDelta, CPoint pt);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	virtual void PostNcDestroy();
};



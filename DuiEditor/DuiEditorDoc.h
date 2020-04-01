
// DuiEditorDoc.h : CDuiEditorDoc ��Ľӿ�
//
#pragma once
#include "DockControlTreeCtrl.h"

class CDuiEditorViewDesign;
class CDuiEditorDoc : public CDocument
{
protected: // �������л�����
	CDuiEditorDoc();
	DECLARE_DYNCREATE(CDuiEditorDoc)

// ����
public:
	pugi::xml_document m_doc;
	BOOL m_bMenuWnd;

// ����
public:
	void FilterDefaultValue(xml_node nodeDoc);	//�����ĵ�Ĭ������
	CDockControlTreeCtrl *GetTreeView() { return m_pTreeView; }
	CDuiEditorViewDesign *GetDesignView() const;
	CView *GetCodeView() const;

	CString GetSkinPath();
	CString GetSkinFileName();

	void InitFileView(CDocument *pDocCurrentClose);
// ��д
public:
	virtual BOOL OnNewDocument();
	virtual BOOL OnNewDocumentFromUiTemplate();
	virtual void Serialize(CArchive& ar);
#ifdef SHARED_HANDLERS
	virtual void InitializeSearchContent();
	virtual void OnDrawThumbnail(CDC& dc, LPRECT lprcBounds);
#endif // SHARED_HANDLERS

// ʵ��
public:
	virtual ~CDuiEditorDoc();

protected:
	CDockControlTreeCtrl *m_pTreeView;
	CString m_strDefaultTitle;
// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()

#ifdef SHARED_HANDLERS
	// ����Ϊ����������������������ݵ� Helper ����
	void SetSearchContent(const CString& value);
#endif // SHARED_HANDLERS
public:
	virtual void OnDocumentEvent(DocumentEvent deEvent);
	virtual BOOL OnOpenDocument(LPCTSTR lpszPathName);
	virtual BOOL DoFileSave();
	virtual BOOL OnSaveDocument(LPCTSTR lpszPathName);
	virtual void OnCloseDocument();
	virtual void SetModifiedFlag(BOOL bModified = TRUE);
	afx_msg void OnFileReopen();
	afx_msg void OnEditXml();
	afx_msg void OnUpdateEditXml(CCmdUI *pCmdUI);
	afx_msg void OnUpdateFileReopen(CCmdUI *pCmdUI);
};

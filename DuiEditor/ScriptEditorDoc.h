#pragma once

// CScriptEditorDoc �ĵ�

class CScriptEditorDoc : public CDocument
{
	DECLARE_DYNCREATE(CScriptEditorDoc)

public:
	CScriptEditorDoc();
	virtual ~CScriptEditorDoc();
#ifndef _WIN32_WCE
	virtual void Serialize(CArchive& ar);   // Ϊ�ĵ� I/O ��д
#endif

protected:
	virtual BOOL OnNewDocument();

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnOpenDocument(LPCTSTR lpszPathName);
	virtual BOOL OnSaveDocument(LPCTSTR lpszPathName);
	virtual void OnCloseDocument();
};

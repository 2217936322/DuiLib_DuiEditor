// ScriptEditorDoc.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "DuiEditor.h"
#include "ScriptEditorDoc.h"


// CScriptEditorDoc

IMPLEMENT_DYNCREATE(CScriptEditorDoc, CDocument)

CScriptEditorDoc::CScriptEditorDoc()
{
}

BOOL CScriptEditorDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;
	return TRUE;
}

CScriptEditorDoc::~CScriptEditorDoc()
{
}


BEGIN_MESSAGE_MAP(CScriptEditorDoc, CDocument)
END_MESSAGE_MAP()

#ifndef _WIN32_WCE
// CScriptEditorDoc ���л�

void CScriptEditorDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: �ڴ����Ӵ洢����
	}
	else
	{
		// TODO: �ڴ����Ӽ��ش���
	}
}
#endif


// CScriptEditorDoc ����


BOOL CScriptEditorDoc::OnOpenDocument(LPCTSTR lpszPathName)
{
	if (!CDocument::OnOpenDocument(lpszPathName))
		return FALSE;

	// TODO:  �ڴ�������ר�õĴ�������

	return TRUE;
}


BOOL CScriptEditorDoc::OnSaveDocument(LPCTSTR lpszPathName)
{
	// TODO: �ڴ�����ר�ô����/����û���

	return CDocument::OnSaveDocument(lpszPathName);
}


void CScriptEditorDoc::OnCloseDocument()
{
	// TODO: �ڴ�����ר�ô����/����û���

	CDocument::OnCloseDocument();
}
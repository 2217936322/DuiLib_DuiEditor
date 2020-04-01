
// DuiEditorDoc.cpp : CDuiEditorDoc ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "DuiEditor.h"
#endif

#include "DuiEditorDoc.h"
#include "DuiEditorViewDesign.h"
#include "DuiEditorViewCode.h"

#include <propkey.h>

#include "MainFrm.h"
#include "DockControlTreeWnd.h"
#include "DockOutputWnd.h"
#include "DlgCreateDuiDocument.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CDuiEditorDoc

IMPLEMENT_DYNCREATE(CDuiEditorDoc, CDocument)

BEGIN_MESSAGE_MAP(CDuiEditorDoc, CDocument)
	ON_COMMAND(ID_FILE_REOPEN, &CDuiEditorDoc::OnFileReopen)
	ON_COMMAND(ID_EDIT_XML, &CDuiEditorDoc::OnEditXml)
	ON_UPDATE_COMMAND_UI(ID_EDIT_XML, &CDuiEditorDoc::OnUpdateEditXml)
	ON_UPDATE_COMMAND_UI(ID_FILE_REOPEN, &CDuiEditorDoc::OnUpdateFileReopen)
END_MESSAGE_MAP()


// CDuiEditorDoc ����/����

CDuiEditorDoc::CDuiEditorDoc()
{
	// TODO: �ڴ����һ���Թ������
	CMainFrame *pMain = (CMainFrame *)AfxGetMainWnd();
	m_pTreeView = pMain->m_wndControl.CreateTreeView();
	m_pTreeView->m_pDoc = this;
	m_bMenuWnd = FALSE;
}

CDuiEditorDoc::~CDuiEditorDoc()
{
	CMainFrame *pMain = (CMainFrame *)AfxGetMainWnd();
	pMain->m_wndControl.RemoveTreeView(m_pTreeView);
	InitFileView(this);
}

BOOL CDuiEditorDoc::OnNewDocument()
{
/*
	CDlgCreateDuiDocument dlg;
	if(dlg.DoModal() == IDOK)
	{
		CString strFile = g_strAppPath + _T("DuiTemplate\\") + dlg.m_strModuleName + _T("\\skin.xml");
		if(!m_doc.load_file(strFile))
		{
			AfxMessageBox(_T("����ģ��ҳʧ��!"));
			xml_node nodeWindow = m_doc.root().append_child(_T("Window"));
			nodeWindow.append_attribute(_T("size")).set_value(_T("400,300"));
			nodeWindow.append_child(_T("VerticalLayout"));
		}
	}
	else
	{
		xml_node nodeWindow = m_doc.child_auto(_T("Window"));
		nodeWindow.append_attribute(_T("size")).set_value(_T("400,300"));
		nodeWindow.append_child(_T("VerticalLayout"));
	}
	*/

	xml_node nodeWindow = m_doc.child_auto(_T("Window"));
	nodeWindow.append_attribute(_T("size")).set_value(_T("400,300"));
	nodeWindow.append_child(_T("VerticalLayout"));

	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: �ڴ�������³�ʼ������
	// (SDI �ĵ������ø��ĵ�)

	GetTreeView()->InitTreeContent();
	m_strDefaultTitle = m_strTitle;
	return TRUE;
}

BOOL CDuiEditorDoc::OnNewDocumentFromUiTemplate()
{
	CDlgCreateDuiDocument dlg;
	if(dlg.DoModal() != IDOK) return FALSE;
	
	CString strFile = g_strAppPath + _T("DuiTemplate\\") + dlg.m_strModuleName + _T("\\skin.xml");
	if(!m_doc.load_file(strFile))
	{
		AfxMessageBox(_T("����ģ��ҳʧ��!"));
		xml_node nodeWindow = m_doc.root().append_child(_T("Window"));
		nodeWindow.append_attribute(_T("size")).set_value(_T("400,300"));
		nodeWindow.append_child(_T("VerticalLayout"));
	}	
	
	GetTreeView()->InitTreeContent();
	m_strDefaultTitle = m_strTitle;
	return TRUE;
}

// CDuiEditorDoc ���л�

void CDuiEditorDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: �ڴ���Ӵ洢����
	}
	else
	{
		// TODO: �ڴ���Ӽ��ش���
	}
}

#ifdef SHARED_HANDLERS

// ����ͼ��֧��
void CDuiEditorDoc::OnDrawThumbnail(CDC& dc, LPRECT lprcBounds)
{
	// �޸Ĵ˴����Ի����ĵ�����
	dc.FillSolidRect(lprcBounds, RGB(255, 255, 255));

	CString strText = _T("TODO: implement thumbnail drawing here");
	LOGFONT lf;

	CFont* pDefaultGUIFont = CFont::FromHandle((HFONT) GetStockObject(DEFAULT_GUI_FONT));
	pDefaultGUIFont->GetLogFont(&lf);
	lf.lfHeight = 36;

	CFont fontDraw;
	fontDraw.CreateFontIndirect(&lf);

	CFont* pOldFont = dc.SelectObject(&fontDraw);
	dc.DrawText(strText, lprcBounds, DT_CENTER | DT_WORDBREAK);
	dc.SelectObject(pOldFont);
}

// ������������֧��
void CDuiEditorDoc::InitializeSearchContent()
{
	CString strSearchContent;
	// ���ĵ����������������ݡ�
	// ���ݲ���Ӧ�ɡ�;���ָ�

	// ����:  strSearchContent = _T("point;rectangle;circle;ole object;")��
	SetSearchContent(strSearchContent);
}

void CDuiEditorDoc::SetSearchContent(const CString& value)
{
	if (value.IsEmpty())
	{
		RemoveChunk(PKEY_Search_Contents.fmtid, PKEY_Search_Contents.pid);
	}
	else
	{
		CMFCFilterChunkValueImpl *pChunk = NULL;
		ATLTRY(pChunk = new CMFCFilterChunkValueImpl);
		if (pChunk != NULL)
		{
			pChunk->SetTextValue(PKEY_Search_Contents, value, CHUNK_TEXT);
			SetChunkValue(pChunk);
		}
	}
}

#endif // SHARED_HANDLERS

// CDuiEditorDoc ����
void CDuiEditorDoc::OnDocumentEvent(DocumentEvent deEvent)
{
	__super::OnDocumentEvent(deEvent);

	switch (deEvent)
	{
	case onAfterNewDocument:
		{
			break;
		}

	case onAfterOpenDocument:
		{
			InitFileView(NULL);
			break;
		}

	case onAfterSaveDocument:
		{
			InitFileView(NULL);
			break;
		}

	case onAfterCloseDocument:
		{
			//InitFileView();
			break;
		}
	}
}

void CDuiEditorDoc::InitFileView(CDocument *pDocCurrentClose)
{
	CDocument *pDoc = NULL;
	int nCount = 0;
	POSITION pos = GetDocTemplate()->GetFirstDocPosition();
	while (pos != NULL)
	{
		CDocument *p = GetDocTemplate()->GetNextDoc(pos);
		if(p != pDocCurrentClose)
		{
			pDoc = p;
			nCount++;
		}
	}

	if(pDoc && nCount == 1)
	{
		CString strPath;
		CString strTemp = pDoc->GetPathName();
		int nPos = strTemp.ReverseFind(_T('\\'));
		if(nPos != -1)
		{
			strPath = strTemp.Left(nPos + 1);
		}

		if(!strPath.IsEmpty())
		{
			((CMainFrame *)AfxGetMainWnd())->m_wndFileView.m_wndFileView.InitFolder(strPath);
		}
	}
}

BOOL CDuiEditorDoc::OnOpenDocument(LPCTSTR lpszPathName)
{
	if (!CDocument::OnOpenDocument(lpszPathName))
		return FALSE;

	// TODO:  �ڴ������ר�õĴ�������
	m_doc.load_file(lpszPathName, XML_PARSER_OPTIONS);

	xml_node root = m_doc.child(_T("Window"));
	if(root)
	{
		xml_node node = root.child(_T("Menu"));
		if(node)
		{
			m_bMenuWnd = TRUE;
		}
	}
	return TRUE;
}


BOOL CDuiEditorDoc::DoFileSave()
{
	if(!__super::DoFileSave())	return FALSE;

	//InsertMsg(_T("CDuiEditorDoc::OnSaveDocument"));

	//����Ĭ������
	xml_node root = m_doc.root().child(_T("Window"));
	FilterDefaultValue(root);

	//����һ������, Ȼ�󱣴濽��
	xml_document doc;
	doc.root().append_copy(root);
	bool bSave = doc.save_file(GetPathName(), PUGIXML_TEXT("\t"), format_default, encoding_utf8);
	if(!bSave)	return FALSE;

	SetModifiedFlag(FALSE);
	return TRUE;
}


BOOL CDuiEditorDoc::OnSaveDocument(LPCTSTR lpszPathName)
{
// 	InsertMsg(_T("CDuiEditorDoc::OnSaveDocument"));
// 
// 	//����Ĭ������
// 	xml_node root = m_doc.root().child(_T("Window"));
// 	FilterDefaultValue(root);
// 
// 	//����һ������, Ȼ�󱣴濽��
// 	xml_document doc;
// 	doc.root().append_copy(root);
// 	bool bSave = doc.save_file(lpszPathName, PUGIXML_TEXT("\t"), format_default, encoding_utf8);
// 	if(!bSave)	return FALSE;
// 
// 	SetModifiedFlag(FALSE);

// 	CString strTemp;
// 	strTemp = lpszPathName;
// 	int nPos = strTemp.ReverseFind(_T('\\'));
// 	if(nPos != -1)
// 	{
// 		m_strSkinDir = strTemp.Left(nPos + 1);
// 		m_strFileName = strTemp.Right(strTemp.GetLength() - nPos - 1);
// 	}

//	GetDesignView()->m_Manager.GetManager()->SetResourcePath(m_strSkinDir);

//	return TRUE;
	return CDocument::OnSaveDocument(lpszPathName);
}


void CDuiEditorDoc::OnCloseDocument()
{
	CDocument::OnCloseDocument();
}

void CDuiEditorDoc::SetModifiedFlag(BOOL bModified)
{
	if(m_bModified != bModified)
	{
		CString strTitle;
		if(GetPathName().IsEmpty())
		{
			strTitle = m_strDefaultTitle;
		}
		else
		{
			LPCTSTR lpszPathName = (LPCTSTR)GetPathName();

			// always capture the complete file name including extension (if present)
			LPTSTR lpszTemp = (LPTSTR)lpszPathName;
			for (LPCTSTR lpsz = lpszPathName; *lpsz != '\0'; lpsz = _tcsinc(lpsz))
			{
				// remember last directory/drive separator
				if (*lpsz == '\\' || *lpsz == '/' || *lpsz == ':')
					lpszTemp = (LPTSTR)_tcsinc(lpsz);
			}

			strTitle = lpszTemp;
		}

		if(bModified)
			SetTitle(strTitle + " *");
		else
			SetTitle(strTitle);
	}

	__super::SetModifiedFlag(bModified);
}

CDuiEditorViewDesign *CDuiEditorDoc::GetDesignView() const
{
	CView *pView;
	for (POSITION pos = GetFirstViewPosition(); pos != NULL;)
	{
		pView = GetNextView(pos);
		if(pView->IsKindOf(RUNTIME_CLASS(CDuiEditorViewDesign)))
			return (CDuiEditorViewDesign *)pView;
	}
	return NULL;
}

CView *CDuiEditorDoc::GetCodeView() const
{
	CView *pView;
	for (POSITION pos = GetFirstViewPosition(); pos != NULL;)
	{
		pView = GetNextView(pos);
		if(pView->IsKindOf(RUNTIME_CLASS(CDuiEditorViewCode)))
			return pView;
	}
	return NULL;
}

CString CDuiEditorDoc::GetSkinPath()
{
	CString strTemp;
	strTemp = GetPathName();
	int nPos = strTemp.ReverseFind(_T('\\'));
	if(nPos != -1)
	{
		return strTemp.Left(nPos + 1);
	}

	return _T("");
}

CString CDuiEditorDoc::GetSkinFileName()
{
	CString strTemp;
	strTemp = GetPathName();
	int nPos = strTemp.ReverseFind(_T('\\'));
	if(nPos != -1)
	{
		return strTemp.Right(strTemp.GetLength() - nPos - 1);
	}

	return _T("");
}

void CDuiEditorDoc::FilterDefaultValue(xml_node nodeDoc)
{
	xml_node nodeDuiProp = g_duiProp.FindControl(nodeDoc.name());
	for (xml_node nodeAttr=nodeDuiProp.first_child(); nodeAttr; nodeAttr=nodeAttr.next_sibling())
	{
		xml_attribute attr = nodeDoc.attribute(nodeAttr.attribute(_T("name")).value());
		if(attr)
		{
			if(attr.value() == '\0' || attr.value() == NULL)
			{
				nodeDoc.remove_attribute(attr);
			}
			else if(CompareString(attr.value(), nodeAttr.attribute(_T("default")).value()))
			{
				nodeDoc.remove_attribute(attr);
			}
		}

	}

	for (pugi::xml_node node = nodeDoc.first_child(); node; node = node.next_sibling())
	{
		FilterDefaultValue(node);
	}
}


void CDuiEditorDoc::OnFileReopen()
{
	if(!SaveModified())
		return;

	CString strFile = GetPathName();// + m_strFileName;
	if(!strFile.IsEmpty())
	{
		AfxGetMainWnd()->SendMessage(WM_REOPEN_FILE, (WPARAM)(LPCTSTR)strFile, (LPARAM)this);
	}

	OnFileClose();
	return;
}

void CDuiEditorDoc::OnUpdateFileReopen(CCmdUI *pCmdUI)
{
	//pCmdUI->Enable(FALSE);
}



void CDuiEditorDoc::OnEditXml()
{
	
}


void CDuiEditorDoc::OnUpdateEditXml(CCmdUI *pCmdUI)
{
	// TODO: �ڴ������������û����洦��������
}


// DlgOptions.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "DuiEditor.h"
#include "DlgOptions.h"
#include "afxdialogex.h"


// CDlgOptions �Ի���

IMPLEMENT_DYNAMIC(CDlgOptions, CDialogEx)

CDlgOptions::CDlgOptions(CWnd* pParent /*=NULL*/)
	: CDialogEx(CDlgOptions::IDD, pParent)
{

	m_nTreeDeep = 0;
	m_strAttachTestCommand = _T("");
}

CDlgOptions::~CDlgOptions()
{
}

void CDlgOptions::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Check(pDX, IDC_CHECK1, m_bUpdateSizeWhenModifyPos);
	DDX_Text(pDX, IDC_EDIT1, m_nTreeDeep);
	DDX_Text(pDX, IDC_EDIT2, m_strAttachTestCommand);
}


BEGIN_MESSAGE_MAP(CDlgOptions, CDialogEx)
	ON_BN_CLICKED(IDOK, &CDlgOptions::OnBnClickedOk)
	ON_BN_CLICKED(IDC_BUTTON1, &CDlgOptions::OnBnClickedButton1)
END_MESSAGE_MAP()


// CDlgOptions ��Ϣ�������


BOOL CDlgOptions::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  �ڴ���Ӷ���ĳ�ʼ��
	CSpinButtonCtrl *pSpin = (CSpinButtonCtrl *)GetDlgItem(IDC_SPIN1);
	pSpin->SetBuddy(GetDlgItem(IDC_EDIT1));
	pSpin->SetRange(9999, 0);

	m_bUpdateSizeWhenModifyPos = TRUE; //AfxGetApp()->GetProfileInt(_T("Options"), _T("UpdateSizeWhenModifyPos"), 1);
	m_nTreeDeep = AfxGetApp()->GetProfileInt(_T("Options"), _T("TreeDeep"), 3);

	m_strAttachTestCommand = g_strAttachTestCommand;

	UpdateData(FALSE);
	return TRUE;  // return TRUE unless you set the focus to a control
	// �쳣: OCX ����ҳӦ���� FALSE
}


void CDlgOptions::OnBnClickedOk()
{
	if(!UpdateData(TRUE))	return;

	AfxGetApp()->WriteProfileInt(_T("Options"), _T("UpdateSizeWhenModifyPos"), m_bUpdateSizeWhenModifyPos);
	AfxGetApp()->WriteProfileInt(_T("Options"), _T("TreeDeep"), m_nTreeDeep);

	if(m_strAttachTestCommand != g_strAttachTestCommand)
	{
		g_strAttachTestCommand = m_strAttachTestCommand;
		AfxGetApp()->WriteProfileString(_T("Options"), _T("TestCommand"), g_strAttachTestCommand);
	}

	CDialogEx::OnOK();
}


void CDlgOptions::OnBnClickedButton1()
{
	static TCHAR BASED_CODE szFilter[] = _T("exe(*.exe)|*.exe|All Files (*.*)|*.*||");
	CFileDialog dlg(TRUE, _T("exe"), NULL, OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT, szFilter);
	if(dlg.DoModal()==IDOK)
	{
		GetDlgItem(IDC_EDIT2)->SetWindowText(dlg.GetPathName());
	}
}

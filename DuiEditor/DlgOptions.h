#pragma once


// CDlgOptions �Ի���

class CDlgOptions : public CDialogEx
{
	DECLARE_DYNAMIC(CDlgOptions)

public:
	CDlgOptions(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CDlgOptions();

// �Ի�������
	enum { IDD = IDD_DLG_OPTIONS };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
	afx_msg void OnBnClickedOk();
	BOOL m_bUpdateSizeWhenModifyPos;
	UINT m_nTreeDeep;
	afx_msg void OnBnClickedButton1();
	CString m_strAttachTestCommand;
};

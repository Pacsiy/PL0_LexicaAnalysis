
// PL0_LexicaAnalysisDlg.h : ͷ�ļ�
//

#pragma once
#include "afxcmn.h"


// CPL0_LexicaAnalysisDlg �Ի���
class CPL0_LexicaAnalysisDlg : public CDialogEx
{
// ����
public:
	CPL0_LexicaAnalysisDlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_PL0_LEXICAANALYSIS_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��


// ʵ��
protected:
	HICON m_hIcon;

	// ���ɵ���Ϣӳ�亯��
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	CListCtrl my_listview;
	afx_msg void OnBnClickedOk();
	afx_msg void OnEnChangeEdit1();
	CString my_inbox;
	afx_msg void OnEnChangeEdit2();
	afx_msg void OnBnClickedButton1();
	CString sys_out;
	CString my_browse;
};


// PL0_LexicaAnalysisDlg.h : 头文件
//

#pragma once
#include "afxcmn.h"


// CPL0_LexicaAnalysisDlg 对话框
class CPL0_LexicaAnalysisDlg : public CDialogEx
{
// 构造
public:
	CPL0_LexicaAnalysisDlg(CWnd* pParent = NULL);	// 标准构造函数

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_PL0_LEXICAANALYSIS_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
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

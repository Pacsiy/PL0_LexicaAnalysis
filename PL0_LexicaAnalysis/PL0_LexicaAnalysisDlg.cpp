
// PL0_LexicaAnalysisDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "PL0_LexicaAnalysis.h"
#include "PL0_LexicaAnalysisDlg.h"
#include "afxdialogex.h"
#include "Compiler.h"
#include "Judge.h"
#include <iostream>
using namespace std;

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 实现
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CPL0_LexicaAnalysisDlg 对话框



CPL0_LexicaAnalysisDlg::CPL0_LexicaAnalysisDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_PL0_LEXICAANALYSIS_DIALOG, pParent)
	, my_inbox(_T(""))
	, sys_out(_T(""))
	, my_browse(_T(""))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CPL0_LexicaAnalysisDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST1, my_listview);
	DDX_Text(pDX, IDC_EDIT2, my_inbox);
	DDV_MaxChars(pDX, my_inbox, 25);
	DDX_Text(pDX, IDC_EDIT1, sys_out);
	DDV_MaxChars(pDX, sys_out, 20);
	DDX_Text(pDX, IDC_MFCEDITBROWSE1, my_browse);
}

BEGIN_MESSAGE_MAP(CPL0_LexicaAnalysisDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDOK, &CPL0_LexicaAnalysisDlg::OnBnClickedOk)
	ON_EN_CHANGE(IDC_EDIT2, &CPL0_LexicaAnalysisDlg::OnEnChangeEdit2)
	ON_BN_CLICKED(IDC_BUTTON1, &CPL0_LexicaAnalysisDlg::OnBnClickedButton1)
END_MESSAGE_MAP()


// CPL0_LexicaAnalysisDlg 消息处理程序

BOOL CPL0_LexicaAnalysisDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 将“关于...”菜单项添加到系统菜单中。

	// IDM_ABOUTBOX 必须在系统命令范围内。
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// 设置此对话框的图标。  当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO: 在此添加额外的初始化代码
	CRect rect;
	my_listview.GetClientRect(&rect);
	my_listview.SetExtendedStyle(my_listview.GetExtendedStyle() | LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES);
	my_listview.InsertColumn(0, _T("NO."), LVCFMT_CENTER, 50, 0);
	my_listview.InsertColumn(1, _T("Word"), LVCFMT_CENTER, 150, 0);
	my_listview.InsertColumn(2, _T("Category"), LVCFMT_CENTER, 130, 0);
	my_listview.InsertColumn(3, _T("Value"), LVCFMT_CENTER, 150, 0);

	CEdit* sys_outptr = (CEdit*)GetDlgItem(IDC_EDIT1);
	sys_outptr->SetWindowText(_T("请将文件放在工程目录下分析！"));

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void CPL0_LexicaAnalysisDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。  对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CPL0_LexicaAnalysisDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CPL0_LexicaAnalysisDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


void CPL0_LexicaAnalysisDlg::OnBnClickedOk()
{
	// TODO: 在此添加控件通知处理程序代码
	string input, output;
	CString selectedPath;
	GetDlgItemText(IDC_MFCEDITBROWSE1, selectedPath);
	USES_CONVERSION;
	char* s_char = W2A(selectedPath);
	string inString = s_char;
	string dir = "";
	for (int i = inString.length() - 1; i >= 0; i--)
	{
		if (inString[i] != '\\') dir = inString[i] + dir;
		else break;
	}
	if (dir.length() > 0){
		input = dir;
		output = "out.txt";
	}

	const char *in = input.c_str();
	const char *out = output.c_str();
	if (freopen(in, "r", stdin) == NULL)
	{
		CEdit* sys_outptr = (CEdit*)GetDlgItem(IDC_EDIT1);
		sys_outptr->SetWindowText(_T("未找到输入文件！"));
	}
	else
	{
		int cnt = 1;
		my_listview.DeleteAllItems();
		Compiler compiler(in, out);
		while (1)
		{
			if (!compiler.nextToken()) break;
			string* onelist = compiler.getTxtOutput();

			my_listview.InsertItem(cnt-1, CString(to_string(cnt).c_str()));
			my_listview.SetItemText(cnt-1, 1, CString(onelist[0].c_str()));
			my_listview.SetItemText(cnt-1, 2, CString(onelist[1].c_str()));
			my_listview.SetItemText(cnt-1, 3, CString(onelist[2].c_str()));
			cnt++;
		}
		CEdit* sys_outptr = (CEdit*)GetDlgItem(IDC_EDIT1);
		sys_outptr->SetWindowText(_T("分析成功并输出至out.txt!"));
	}
}


void CPL0_LexicaAnalysisDlg::OnEnChangeEdit2()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码

}


void CPL0_LexicaAnalysisDlg::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码
	CString sentence;
	GetDlgItemText(IDC_EDIT2, sentence);
	USES_CONVERSION;
	char* s_char = W2A(sentence);
	string inString = s_char;
	if (inString.length() > 0)
	{
		freopen("inTemp.txt", "w", stdout);
		cout << inString;

		int cnt = 1;
		my_listview.DeleteAllItems();
		Compiler compiler("inTemp.txt", "outTemp.txt");
		while (1)
		{
			if (!compiler.nextToken()) break;
			string* onelist = compiler.getTxtOutput();

			my_listview.InsertItem(cnt - 1, CString(to_string(cnt).c_str()));
			my_listview.SetItemText(cnt - 1, 1, CString(onelist[0].c_str()));
			my_listview.SetItemText(cnt - 1, 2, CString(onelist[1].c_str()));
			my_listview.SetItemText(cnt - 1, 3, CString(onelist[2].c_str()));
			cnt++;
		}
		CEdit* sys_outptr = (CEdit*)GetDlgItem(IDC_EDIT1);
		sys_outptr->SetWindowText(_T("分析成功并输出至outTemp.txt！"));
	}
	else
	{
		CEdit* sys_outptr = (CEdit*)GetDlgItem(IDC_EDIT1);
		sys_outptr->SetWindowText(_T("请输入语句！"));
	}
}

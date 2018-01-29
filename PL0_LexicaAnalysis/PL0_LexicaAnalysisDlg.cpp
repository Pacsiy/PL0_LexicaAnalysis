
// PL0_LexicaAnalysisDlg.cpp : ʵ���ļ�
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

// ����Ӧ�ó��򡰹��ڡ��˵���� CAboutDlg �Ի���

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

// ʵ��
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


// CPL0_LexicaAnalysisDlg �Ի���



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


// CPL0_LexicaAnalysisDlg ��Ϣ�������

BOOL CPL0_LexicaAnalysisDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// ��������...���˵�����ӵ�ϵͳ�˵��С�

	// IDM_ABOUTBOX ������ϵͳ���Χ�ڡ�
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

	// ���ô˶Ի����ͼ�ꡣ  ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	// TODO: �ڴ���Ӷ���ĳ�ʼ������
	CRect rect;
	my_listview.GetClientRect(&rect);
	my_listview.SetExtendedStyle(my_listview.GetExtendedStyle() | LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES);
	my_listview.InsertColumn(0, _T("NO."), LVCFMT_CENTER, 50, 0);
	my_listview.InsertColumn(1, _T("Word"), LVCFMT_CENTER, 150, 0);
	my_listview.InsertColumn(2, _T("Category"), LVCFMT_CENTER, 130, 0);
	my_listview.InsertColumn(3, _T("Value"), LVCFMT_CENTER, 150, 0);

	CEdit* sys_outptr = (CEdit*)GetDlgItem(IDC_EDIT1);
	sys_outptr->SetWindowText(_T("�뽫�ļ����ڹ���Ŀ¼�·�����"));

	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
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

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ  ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void CPL0_LexicaAnalysisDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // ���ڻ��Ƶ��豸������

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// ʹͼ���ڹ����������о���
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// ����ͼ��
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//���û��϶���С������ʱϵͳ���ô˺���ȡ�ù��
//��ʾ��
HCURSOR CPL0_LexicaAnalysisDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


void CPL0_LexicaAnalysisDlg::OnBnClickedOk()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
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
		sys_outptr->SetWindowText(_T("δ�ҵ������ļ���"));
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
		sys_outptr->SetWindowText(_T("�����ɹ��������out.txt!"));
	}
}


void CPL0_LexicaAnalysisDlg::OnEnChangeEdit2()
{
	// TODO:  ����ÿؼ��� RICHEDIT �ؼ���������
	// ���ʹ�֪ͨ��������д CDialogEx::OnInitDialog()
	// ���������� CRichEditCtrl().SetEventMask()��
	// ͬʱ�� ENM_CHANGE ��־�������㵽�����С�

	// TODO:  �ڴ���ӿؼ�֪ͨ����������

}


void CPL0_LexicaAnalysisDlg::OnBnClickedButton1()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
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
		sys_outptr->SetWindowText(_T("�����ɹ��������outTemp.txt��"));
	}
	else
	{
		CEdit* sys_outptr = (CEdit*)GetDlgItem(IDC_EDIT1);
		sys_outptr->SetWindowText(_T("��������䣡"));
	}
}

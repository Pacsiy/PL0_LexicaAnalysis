
// PL0_LexicaAnalysis.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CPL0_LexicaAnalysisApp: 
// �йش����ʵ�֣������ PL0_LexicaAnalysis.cpp
//

class CPL0_LexicaAnalysisApp : public CWinApp
{
public:
	CPL0_LexicaAnalysisApp();

// ��д
public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern CPL0_LexicaAnalysisApp theApp;
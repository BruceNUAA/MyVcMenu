
// MyVcMenu.h : MyVcMenu Ӧ�ó������ͷ�ļ�
//
#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"       // ������


// CMyVcMenuApp:
// �йش����ʵ�֣������ MyVcMenu.cpp
//

class CMyVcMenuApp : public CWinApp
{
public:
	CMyVcMenuApp();


// ��д
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// ʵ��
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CMyVcMenuApp theApp;

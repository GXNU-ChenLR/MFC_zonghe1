
// MFC_zonghe1.h : MFC_zonghe1 Ӧ�ó������ͷ�ļ�
//
#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"       // ������


// CMFC_zonghe1App:
// �йش����ʵ�֣������ MFC_zonghe1.cpp
//

class CMFC_zonghe1App : public CWinApp
{
public:
	CMFC_zonghe1App();


// ��д
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// ʵ��
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CMFC_zonghe1App theApp;

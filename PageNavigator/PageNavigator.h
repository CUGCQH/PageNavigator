
// PageNavigator.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CPageNavigatorApp: 
// �йش����ʵ�֣������ PageNavigator.cpp
//

class CPageNavigatorApp : public CWinApp
{
public:
	CPageNavigatorApp();

// ��д
public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern CPageNavigatorApp theApp;
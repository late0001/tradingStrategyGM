// stdafx.h : include file for standard system include files,
//  or project specific include files that are used frequently, but
//      are changed infrequently
//

#if !defined(AFX_STDAFX_H__D3A0CF0B_D151_46BB_BC1E_CCCA47B1D050__INCLUDED_)
#define AFX_STDAFX_H__D3A0CF0B_D151_46BB_BC1E_CCCA47B1D050__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#define VC_EXTRALEAN		// Exclude rarely-used stuff from Windows headers

// ���������ʹ��������ָ����ƽ̨֮ǰ��ƽ̨�����޸�����Ķ��塣
// �йز�ͬƽ̨����Ӧֵ��������Ϣ����ο� MSDN��
#ifndef WINVER				// ����ʹ�� Windows 95 �� Windows NT 4 ����߰汾���ض����ܡ�
#define WINVER 0x0400		//Ϊ Windows98 �� Windows 2000 �����°汾�ı�Ϊ�ʵ���ֵ��
#endif

#define _WIN32_IE 0x0601

#define _ATL_CSTRING_EXPLICIT_CONSTRUCTORS	// ĳЩ CString ���캯��������ʽ��

// �ر� MFC ��ĳЩ��������������ȫ���Եľ�����Ϣ������
#define _AFX_ALL_WARNINGS

#pragma warning( disable : 4996 )	// warning C4996: 'strncpy': This function or variable may be unsafe.

#include <afxwin.h>         // MFC core and standard components
#include <afxext.h>         // MFC extensions

#ifndef _AFX_NO_OLE_SUPPORT
#include <afxole.h>         // MFC OLE classes
#include <afxodlgs.h>       // MFC OLE dialog classes
#include <afxdisp.h>        // MFC Automation classes
#endif // _AFX_NO_OLE_SUPPORT

#ifndef _AFX_NO_DB_SUPPORT
#include <afxdb.h>			// MFC ODBC database classes
#endif // _AFX_NO_DB_SUPPORT

#ifndef _AFX_NO_DAO_SUPPORT
#include <afxdao.h>			// MFC DAO database classes
#endif // _AFX_NO_DAO_SUPPORT

#include <afxdtctl.h>		// MFC support for Internet Explorer 4 Common Controls
#ifndef _AFX_NO_AFXCMN_SUPPORT
#include <afxcmn.h>			// MFC support for Windows Common Controls
#endif // _AFX_NO_AFXCMN_SUPPORT

#include <afxsock.h>		// MFC socket extensions

#include <afxtempl.h>

#include <Afxmt.h>			// CCriticalSection header files

// #pragma comment(lib,"msxmlStatic.lib") 
// #pragma message("Automatically linking with msxmlStatic.lib")
// #pragma comment(lib,"msxml3.lib")
// #pragma message("Automatically linking with msxml3.dll")

// GuiLib
//#include "../../GuiLib/Header/ExtLib.h"

// StkLib
#include "../../StkLib/Include/StkLib.h"

#include <math.h>
#include "Resource.h"
#include <StkNet.h>

HINSTANCE AfxGetModuleHandle();
CString	AfxModuleLoadString(UINT nID);

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_STDAFX_H__D3A0CF0B_D151_46BB_BC1E_CCCA47B1D050__INCLUDED_)

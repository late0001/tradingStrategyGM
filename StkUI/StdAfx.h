// stdafx.h : include file for standard system include files,
//  or project specific include files that are used frequently, but
//      are changed infrequently
//

#if !defined(AFX_STDAFX_H__A20D8132_8317_4482_B56B_7EDBCF089D4F__INCLUDED_)
#define AFX_STDAFX_H__A20D8132_8317_4482_B56B_7EDBCF089D4F__INCLUDED_

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

#pragma warning( disable : 4244 )	// warning C4244: ��=�� : �ӡ�__time64_t��ת������time_t�������ܶ�ʧ����
#pragma warning( disable : 4995 )	// warning C4995: ��CDaoRecordset��: ���Ʊ����Ϊ #pragma deprecated
#pragma warning (disable : 4996)	// warning C4996: ��strncpy��������Ϊ�����

#include <math.h>

#include <afxwin.h>         // MFC core and standard components
#include <afxext.h>         // MFC extensions
#include <afxole.h>         // MFC OLE classes
#include <afxodlgs.h>       // MFC OLE dialog classes
#include <afxpriv.h>
#include <afxtempl.h>
#include <afxcview.h>
#include <afxdisp.h>        // MFC Automation classes
#include <afxdtctl.h>		// MFC support for Internet Explorer 4 Common Controls
#ifndef _AFX_NO_AFXCMN_SUPPORT
#include <afxcmn.h>			// MFC support for Windows Common Controls
#endif // _AFX_NO_AFXCMN_SUPPORT
#include <afxdao.h>			// MFC DaoDatabase
#include <afxdb.h>			// MFC ODBC database classes
#include "htmlhelp/htmlhelp.h"

#include <../src/mfc/afximpl.h>

// GuiLib
//#include	"../GuiLib/Header/ExtLib.h"

// XPFace
// #define	SPFACE_STATIC
#include	"../XPFace/Include/XPFace.h"

// StkLib
// #define	STKLIB_STATIC
#include	"../StkLib/Include/StkLib.h"

// StkNet
// #define	STKNET_STATIC
#include	"../StkNet/Include/StkNet.h"

#include	"Resource.h"
#include	"AfxCore.h"

// ʹ�õ��ĵ�
#ifndef _TSK_MAINFRAME
#define _TSK_MAINFRAME
#endif

#endif // !defined(AFX_STDAFX_H__A20D8132_8317_4482_B56B_7EDBCF089D4F__INCLUDED_)

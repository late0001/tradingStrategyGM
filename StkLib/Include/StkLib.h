//
// Copyright 2001 Balang SoftWare
//
// You are free to use, modify and distribute this source, as long as
// there is no charge, and this HEADER stays intact. This source is
// supplied "AS-IS", without WARRANTY OF ANY KIND.
//
//////////////////////////////////////////////////////////////////////

#if !defined(__STKLIB_STKLIB_H__)
#define __STKLIB_STKLIB_H__

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

#ifndef	STKLIB_DLL
	#if defined(STKLIB_STATIC) 
	  #if defined (_DEBUG) 
		#pragma comment(lib,"StkLib30dStatic.lib") 
		#pragma message("Automatically linking with StkLib30dStatic.lib") 
	  #else 
		#pragma comment(lib,"StkLib30Static.lib") 
		#pragma message("Automatically linking with StkLib30Static.lib") 
	  #endif 
	#elif defined(_DEBUG) 
	  #pragma comment(lib,"StkLib30d.lib") 
	  #pragma message("Automatically linking with StkLib30d.dll") 
	#else 
	  #pragma comment(lib,"StkLib30.lib") 
	  #pragma message("Automatically linking with StkLib30.dll") 
	#endif 
#endif

#if !defined(STKLIB_STATIC)
	#ifdef STKLIB_DLL
	#define STKLIB_API __declspec(dllexport)
	#else
	#define STKLIB_API __declspec(dllimport)
	#endif
#else 
	#define	STKLIB_API
#endif

// #define	CLKLAN_ENGLISH_US		// Ӣ�İ棨������
// #define	CLKLAN_CHINESE_SIM		// �������İ�
// must define one
#if !defined(CLKLAN_ENGLISH_US) && !defined(CLKLAN_CHINESE_SIM)
	#define	CLKLAN_CHINESE_SIM
#endif

/**********************************************************************
 * OEM ����ȥ��#define CLKVER_OEM ǰ��ע�ͣ����޸����³��������±���
 */

// #define	CLKVER_OEM		// OEM��ȥ������ע��

#define	OEM_REGKEY_COMPANY	"Ninebulls-Stock Software"// ע����еĹ�˾����
#define	OEM_REGKEY_APP		"CLKingOEM"				// ע����е��������

#define	OEM_SUPPORT_MAILTO	"support@ninebulls.com"	// ����֧�������ַ
#define	OEM_SERVER_DOMAIN	"www.ninebulls.com"		// ��˾��վ��ַ��
													// ע���������ʷ��������Ҫ�Ӹ���ַ����

#define	OEM_SEED_STD1		"dc./x"					// ��׼��ע�������1
#define	OEM_SEED_STD2		"sfk%c"					// ��׼��ע�������2
#define	OEM_SEED_PROF1		"78cd2"					// רҵ��ע�������1
#define	OEM_SEED_PROF2		"d6$3#"					// רҵ��ע�������2

/*
 * OEM �����
**********************************************************************/

#include	"SpPlat.h"
#include	"SpDefs.h"
#include	"SpAssert.h"
#include	"SpObject.h"
#include	"SpString.h"
#include	"SpTime.h"
#include	"SpFile.h"
#include	"SpArchive.h"
#include	"SpColl.h"
#include	"MathParser.h"
#include	"Stock.h"
#include	"Technique.h"
#include	"Database.h"
#include	"Boyermor.h"
#include	"CommFuns.h"
#include	"Container.h"
#include	"Express.h"
#include	"Alarm.h"
#include	"Profile.h"
#include	"Strategy.h"
#include	"DayTrader.h"
#include	"AfxCore.h"
#include	"Packets.h"


#endif // __STKLIB_STKLIB_H__

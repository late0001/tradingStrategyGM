/*
	Cross Platform Core Code.

	Copyright(R) 2001-2002 Balang Software.
	All rights reserved.

	Using:
		strings;
*/

#include "stdafx.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

#ifdef	CLKLAN_ENGLISH_US

char szErrCancel[]			=	"User canceled";
char szErrUrlFormat[]		=	"Server address error";
char szErrRedirect[]		=	"Error occurs when redirecting to net data source";
char szErrInterrupted[]		=	"Transfer interrupted, please contact software provider";
char szErrDataTransfer[]	=	"Transfer error, please try again.";
char szErrZipDll[]			=	"Decompressing dynamic link library error";
char szErrZip[]				=	"Decompression error, please download it again";
char szErrXMLDefault[]		=	"Error occurs when parsing XML";
char szErrXMLPackageSetting[]	=	"Error occurs when getting package settings";
char szErrXMLPackageData[]		=	"Error occurs when getting package data";
char szErrXMLServerSetting[]	=	"Error occurs when getting server settings";
char szErrXMLServerData[]		=	"Error occurs when getting server data";


char szProgHttpConnectting[]=	"Connecting to server...";
char szProgRequestSent[]	=	"Receiving data...";
char szProgRedirecting[]	=	"Redirecting server address...";
char szProgTransferring[]	=	"Transfering data...";
char szProgInstallPackage[]	=	"Installing package (may take a few minutes)...";
char szProgExtractZipFiles[]=	"Decompressing Files (may take a few minutes)...";
char szProgErrorPac[]		=	"Packages which error: ";

char szFmtYearDescript[]	=	"Year %.4d, Day";
char szFmtMonthDescript[]	=	"Year %.4d, Month %.2dth, Day";
char szFmtDayDescript[]		=	"Year %.4d, Month %.2dth, Day %.2dth, Day";

#else

char szErrCancel[]			=	"�û�ȡ������";
char szErrUrlFormat[]		=	"��������ַ�д���";
char szErrRedirect[]		=	"�ض�����������Դʱ��������";
char szErrInterrupted[]		=	"���紫��������ֹ�����������Ӧ����ϵ";
char szErrDataTransfer[]	=	"���ݴ����������������";
char szErrZipDll[]			=	"��ѹ���ļ�DLL����";
char szErrZip[]				=	"��ѹ���ļ�ʱ���ִ�������������";
char szErrXMLDefault[]		=	"����XML�ļ�ʱ���ִ���";
char szErrXMLPackageSetting[]	=	"��ȡ���ݰ�����ʱ���ִ���";
char szErrXMLPackageData[]		=	"��ȡ���ݰ�����ʱ���ִ���";
char szErrXMLServerSetting[]	=	"��ȡ����������ʱ���ִ���";;
char szErrXMLServerData[]		=	"��ȡ����������ʱ���ִ���";;


char szProgHttpConnectting[]=	"�������ӷ�����...";
char szProgRequestSent[]	=	"����׼����������...";
char szProgRedirecting[]	=	"�ض����������ַ...";
char szProgTransferring[]	=	"���ڴ�������...";
char szProgInstallPackage[]	=	"���ڰ�װ���ݰ���������Ҫ�����ӣ�...";
char szProgExtractZipFiles[]=	"���ڽ�ѹ���ļ���������Ҫ�����ӣ�...";
char szProgErrorPac[]		=	"δ������ݰ���";

char szFmtYearDescript[]	=	"%.4d����������";
char szFmtMonthDescript[]	=	"%.4d��%.2d����������";
char szFmtDayDescript[]		=	"%.4d��%.2d��%.2d����������";

#endif	// CLKLAN_ENGLISH_US

// stdafx.h : ��׼ϵͳ�����ļ��İ����ļ���
// ���Ǿ���ʹ�õ��������ĵ�
// �ض�����Ŀ�İ����ļ�

#pragma once

#ifndef VC_EXTRALEAN
#define VC_EXTRALEAN            // �� Windows ͷ���ų�����ʹ�õ�����
#endif

#include "targetver.h"

#define _ATL_CSTRING_EXPLICIT_CONSTRUCTORS      // ĳЩ CString ���캯��������ʽ��

#include <afxwin.h>         // MFC ��������ͱ�׼���
#include <afxext.h>         // MFC ��չ

#ifndef _AFX_NO_OLE_SUPPORT
#include <afxole.h>         // MFC OLE ��
#include <afxodlgs.h>       // MFC OLE �Ի�����
#include <afxdisp.h>        // MFC �Զ�����
#endif // _AFX_NO_OLE_SUPPORT

/*
#ifndef _AFX_NO_DB_SUPPORT
#include <afxdb.h>                      // MFC ODBC ���ݿ���
#endif // _AFX_NO_DB_SUPPORT

#ifndef _AFX_NO_DAO_SUPPORT
#include <afxdao.h>                     // MFC DAO ���ݿ���
#endif // _AFX_NO_DAO_SUPPORT
*/

#ifndef _AFX_NO_OLE_SUPPORT
#include <afxdtctl.h>           // MFC �� Internet Explorer 4 �����ؼ���֧��
#endif
#ifndef _AFX_NO_AFXCMN_SUPPORT
#include <afxcmn.h>                     // MFC �� Windows �����ؼ���֧��
#endif // _AFX_NO_AFXCMN_SUPPORT

// #include "../../CxImage/ximage.h"
// #ifdef _DEBUG
// #pragma comment(lib, "../../CxImage/imaged.lib")
// #else
// #pragma comment(lib, "../../CxImage/image.lib")
// #endif
// 
// #include "../../MyAdo/MyAdo/Ado.h"
// #include "../../MyAdo/MyAdo/ExcelFile.h"
// #ifdef _DEBUG
// #pragma comment(lib, "../../../Exec/MyAdod.lib")
// #else
// #pragma comment(lib, "../../../Exec/MyAdo.lib")
// #endif


#include "../../ExcelFile/Include/ExcelFile.h"
/*
#ifdef _WIN64
#	ifdef _UNICODE
#		ifdef _DEBUG
#			pragma comment(lib, "../../ExcelFile/Lib/ExcelFileux64d.lib")
#		else
#			pragma comment(lib, "../../ExcelFile/Lib/ExcelFileux64.lib")
#		endif
#	else
#		ifdef _DEBUG
#			pragma comment(lib, "../../ExcelFile/Lib/ExcelFilex64d.lib")
#		else
#			pragma comment(lib, "../../ExcelFile/Lib/ExcelFilex64.lib")
#		endif
#	endif
#else
#	ifdef _UNICODE
#		ifdef _DEBUG
#			pragma comment(lib, "../../ExcelFile/Lib/ExcelFileud.lib")
#		else
#			pragma comment(lib, "../../ExcelFile/Lib/ExcelFileu.lib")
#		endif
#	else
#		ifdef _DEBUG
#			pragma comment(lib, "../../ExcelFile/Lib/ExcelFiled.lib")
#		else
#			pragma comment(lib, "../../ExcelFile/Lib/ExcelFile.lib")
#		endif
#	endif
#endif
*/
//#include "../../pugixml/pugixml.hpp"
#include "TinyXml2/tinyxml2.h"

#define XF_GRIDCONTROL_CTRL __declspec(dllexport)
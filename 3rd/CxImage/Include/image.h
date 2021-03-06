#pragma once

#define USE_LS_CXIMAGE

#define _CRT_SECURE_NO_WARNINGS

#ifndef XF_CXIMAGE_CTRL
#define XF_CXIMAGE_CTRL __declspec(dllimport)
#endif

#include "ximage.h"

#ifndef _LIBPATH_
#define _LIBPATH_(p,f)   p##f
#endif

#ifdef _WIN64
#	ifdef _UNICODE
#		ifdef _DEBUG
#			pragma comment(lib, _LIBPATH_(__FILE__,   "/../../Lib/CxImage64ud.lib"))
#		else
#			pragma comment(lib, _LIBPATH_(__FILE__,   "/../../Lib/CxImage64u.lib"))
#		endif
#	else
#		ifdef _DEBUG
#			pragma comment(lib, _LIBPATH_(__FILE__,   "/../../Lib/CxImage64d.lib"))
#		else
#			pragma comment(lib, _LIBPATH_(__FILE__,   "/../../Lib/CxImage64.lib"))
#		endif
#	endif
#else
#	ifdef _UNICODE
#		ifdef _DEBUG
#			pragma comment(lib, _LIBPATH_(__FILE__,   "/../../Lib/CxImageud.lib"))
#		else
#			pragma comment(lib, _LIBPATH_(__FILE__,   "/../../Lib/CxImageu.lib"))
#		endif
#	else
#		ifdef _DEBUG
#			pragma comment(lib, _LIBPATH_(__FILE__,   "/../../Lib/CxImaged.lib"))
#		else
#			pragma comment(lib, _LIBPATH_(__FILE__,   "/../../Lib/CxImage.lib"))
#		endif
#	endif
#endif
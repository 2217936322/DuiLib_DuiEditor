// DuiScript.cpp : ���� DLL Ӧ�ó���ĵ���������
//

#include "stdafx.h"

#include "ScriptEngine.h"

#include "RegCDuiString.h"
#include "RegCControlUI.h"

//////////////////////////////////////////////////////////////////////////
static asIScriptEngine *engine = NULL;
static void MessageCallback(const asSMessageInfo &msg)
{
	if( msg.type == asMSGTYPE_ERROR )
	{
		CStringA temp;
		temp.Format("row = %d\r\ncol = %d\r\nsection=%s \r\nmessage = %s\r\n", 
			msg.row, msg.col, msg.section, msg.message);
		MessageBoxA(NULL, temp, "complie error", MB_OK);
	}
}

IScriptEngine* __stdcall CreateScriptEngine()
{
	if(engine == NULL) return NULL;

	CScriptEngine *p = new CScriptEngine;
	p->SetEngine(engine);
	return p;
}

void __stdcall DeleteScriptEngine(IScriptEngine *pEngine)
{
	if(engine == NULL) return;
	delete (CScriptEngine *)pEngine;
}


extern "C" __declspec(dllexport) void DuiScriptRegister()
{
	if(engine == NULL)
	{
		//����AngelScript�ű�����
		engine = asCreateScriptEngine();

		int r = 0;

		//��Ϣ�ص�
		r = engine->SetMessageCallback(asFUNCTION(MessageCallback), 0, asCALL_CDECL); assert( r >= 0 );

		//�ű�������ַ�����  0 - ASCII, 1 - UTF8. Default: 1 (UTF8). 
		r = engine->SetEngineProperty(asEP_SCRIPT_SCANNER, 0); assert( r >= 0 );

#ifdef _UNICODE
		//�ű��ڲ��ַ������ַ����� 0 - UTF8/ASCII, 1 - UTF16. Default: 0 (UTF8) 
		r = engine->SetEngineProperty(asEP_STRING_ENCODING, 1); assert( r >= 0 );
#endif

		//CRegCDuiString::Register(engine);
		//CRegCControlUI::Register(engine);
	}

	CPaintManagerUI::RegisterScriptEngine(CreateScriptEngine, DeleteScriptEngine);
}

extern "C" __declspec(dllexport) void DuiScriptUnRegister()
{
	if(engine)
	{
		engine->Release();
	}
}
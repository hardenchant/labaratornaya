// dllmain.cpp: ���������� ����� ����� ��� ���������� DLL.
#include "stdafx.h"
#include "dllmain.h"
#include <iostream>
using namespace std;

BOOL APIENTRY DllMain( HMODULE hModule,
                       DWORD  ul_reason_for_call,
                       LPVOID lpReserved
					 )
{
	switch (ul_reason_for_call)
	{
	case DLL_PROCESS_ATTACH:
	case DLL_THREAD_ATTACH:
	case DLL_THREAD_DETACH:
	case DLL_PROCESS_DETACH:
		break;
	}
	return TRUE;
}
EXPORT int get()
{
	cout << "Called get" << endl;
	return 1;
}

EXPORT int f() { return 1; };
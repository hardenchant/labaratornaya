// ConsoleApplication14.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <windows.h>
#include <iostream>
#include <string>
using namespace std;

typedef int (*getfunc)(void);

int main()
{
	HINSTANCE hMyDll;
	hMyDll = LoadLibraryA("ConsoleApplication13.dll");
	if (hMyDll == NULL) {
		cout << "Not loaded" << endl;
		return 1;
	}
	
	cout << "loaded" << endl;

	getfunc get;
	
	get = (getfunc)GetProcAddress((HMODULE)hMyDll,  "_f");
	if (get)
	{
		cout << "error" << endl;
		return 1;
	}
	get();
	//int iCode = (*get)();
	
	FreeLibrary((HMODULE)hMyDll);

    return 0;
}


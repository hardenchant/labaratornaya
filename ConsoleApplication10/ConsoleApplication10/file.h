#pragma once
#include "folder.h"

class file : public folder {
private:
	//c������ �������� ��� ������� �� folder
public:

	string data;
	

	file();
	file(fullname name, bool readonly, string parentuser, int lvlin, string parentfolder, string data);
	~file();
};

#pragma once
#include "folder.h"

class file : public folder {
private:
	//c������ �������� ��� ������� �� folder
public:

	string data;
	

	file();
	file(file* obj, user *us, folder *parent); //constr copy
	file(fullname name, bool readonly, string parentuser, int lvlin, string parentfolder, string data);
	~file();
};

#pragma once
#include "folder.h"

class file : public folder {
private:
	void list();
	void mkdir(string name);
	void touch(string name);
public:
	bool readonly;
	string data;
	file();
	~file();
};

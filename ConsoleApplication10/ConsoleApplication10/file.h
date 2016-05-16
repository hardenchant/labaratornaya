#pragma once
#include "folder.h"

class file : public folder {
private:
	void list();
	void mkdir(string name);
	void touch(string name);
	folder* cd(string name);
	folder* back();
	void link(fullname name, string path);
public:

	string data;
	

	file();
	~file();
};

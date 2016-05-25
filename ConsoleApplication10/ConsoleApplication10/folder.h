#pragma once
#include "user.h"
#include "fullname.h"

using namespace std;

class folder {
public:
	string parentuser; //parrent user
	fullname name; //name+extension
	//string name; //name
	//string pref; //extension
	folder *parrent; //parrent folder
	string parentfolder;
	vector<folder*> inner;
	bool readonly;
	int lvlin; //уровень вложенности

	folder();
	folder(fullname name, bool readonly, string parentuser, int lvlin, string parentfolder); //для восстановления из файла
	~folder();
	void list(); //show inner
	void mkdir(string name, string parentuser); //make folder
	void touch(string name, string data, string parentuser); //make file
	folder* cd(string name, user *us); //return ptr to cd
	folder* back();
	void del(fullname name, user *us);
	void link(fullname name, string path, user *us);
	void open(fullname name, user *us);
	void tree(int tire); // tire only 0!
	void readonlyswitch(string name, user *us);

	
};
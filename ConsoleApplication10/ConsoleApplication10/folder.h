#pragma once
#include "user.h"
#include "fullname.h"

using namespace std;

class folder {
public:
	user *userparrent; //parrent user
	fullname name; //name+extension
	//string name; //name
	//string pref; //extension
	folder *parrent; //parrent folder
	vector<folder*> inner;

	folder();
	~folder();
	void list(); //show inner
	void mkdir(string name); //make folder
	void touch(string name, string data); //make file
	folder* cd(string name); //return ptr to cd
	folder* back();
	void del(fullname delname);
	void link(fullname name, string path);
};
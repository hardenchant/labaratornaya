#pragma once
#include "user.h"

using namespace std;

class folder {
public:
	user *userparrent; //parrent user

	string name; //name
	string pref; //extension
	folder *parrent; //parrent folder
	vector<folder*> inner;

	folder();
	~folder();
	void list(); //show inner
	void mkdir(string name); //make folder
	void touch(string name, string data); //make file
	//void del(string name);
};
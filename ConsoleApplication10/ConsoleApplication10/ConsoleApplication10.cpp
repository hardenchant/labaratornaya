// ConsoleApplication10.cpp: îïğåäåëÿåò òî÷êó âõîäà äëÿ êîíñîëüíîãî ïğèëîæåíèÿ.
//

#include "stdafx.h"
#include <string>
#include <iostream>
#include <vector>
#include <memory>

using namespace std;

class user {
public:
	string name;
	bool rootaccess;
	user(string name);
	void getroot();
};
user::user(string name) {
	this->name = name;
	rootaccess = 0;
}
void user::getroot() {
	rootaccess = 1;
}

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
};

folder::folder() //for root-folder only?
{ 
	pref = "";
	parrent = nullptr;
} 
folder::~folder() {
	for (int i = 0; i < inner.size(); i++)
	{
		delete &inner[i-1];
	}
}
void folder::list() {
	for (int i = 0; i < inner.size(); i++)
	{
		cout << "|" << inner[i]->name << inner[i]->pref << endl;
	}
}
void folder::mkdir(string name) {
	folder *temp = new folder();
	temp->name = name;
	temp->parrent = this;
	inner.push_back(temp);
}
folder* cd(folder *f, string name) {
	for (int i = 0; i < f->inner.size(); i++)
	{
		if (f->inner[i]->name == name && f->inner[i]->pref == "")
		{
			return (f->inner[i]);
		}
	}
}

class file : public folder {
public:
	bool readonly;
	string data;
	file();
};
file::file() {
	pref = ".f";
}

int main()
{
	folder *root = new folder();
	
	//×ÒÎ ÒÎ ÍÅ ÒÀÊ Ñ ÕÎÇßÅÂÀÌÈ ÏÀÏÎÊ, ÄÎÄÅËÀÒÜ, ÂÛÄÀÅÒ ÎØÈÁÊÓ ËÈÑÒ ÍÀ ĞÓÒ
	
	string temple;
	string command;
	
	while (temple != "end")
	{
		cin >> temple;

		if (temple == "list") root->list();
		if (temple == "cd")
		{
			cin >> command;
			root = cd(root, command);
		}
		if (temple == "mkdir")
		{
			cin >> command;
			root->mkdir(command);
		}

		/*if (temple == "touch")
		{
			cin >> command;
			root.createfile(command);
		}*/
		if (temple == "cd..")
		{
			root = root->parrent;
		}
	}



    return 0;
}


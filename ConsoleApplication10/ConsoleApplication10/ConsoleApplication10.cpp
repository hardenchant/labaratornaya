// ConsoleApplication10.cpp: îïğåäåëÿåò òî÷êó âõîäà äëÿ êîíñîëüíîãî ïğèëîæåíèÿ.
//

#include "stdafx.h"
#include <string>
#include <iostream>
#include <vector>
#include <memory>

using namespace std;

class folder {
public:
	string name;
	string pref;
	folder *parrent;
	vector<folder*> inner;
	folder();
	~folder();
	void list();
	void mkdir(string name);
};

folder::folder() {
	pref = "";
	parrent = nullptr;
}
folder::~folder() {
	for (int i = 0; i < inner.size(); i++)
	{
		delete &inner[i];
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
			cout << "hui" << endl;
			return (f->inner[i]);
		}
	}
}

class file : public folder {
public:
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

	root->mkdir("123");
	root->mkdir("ggg");
	cd(root, "ggg");
	root->mkdir("test");
	cd(root, "test");
	folder *temp = root;
	root->list();
	//root->inner._Pop_back_n(3);
	
	
	
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


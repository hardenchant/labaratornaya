// ConsoleApplication10.cpp: îïğåäåëÿåò òî÷êó âõîäà äëÿ êîíñîëüíîãî ïğèëîæåíèÿ.
//

#include "stdafx.h"
#include "folder.h"
#include "file.h"

using namespace std;


folder* cd(folder *f, string name) //subsidiary method for cd, searching and return (tipa dopilit' i poisk)
{
	for (int i = 0; i < f->inner.size(); i++)
	{
		if (f->inner[i]->name == name && f->inner[i]->pref == "")
		{
			return (f->inner[i]);
		}
	}
}



ostream& operator<<(ostream& os, const folder* ff) //subsidiary method for out-info
{
	os << "Name: " << ff->name << " Pref: " << ff->pref << " Parrent: " << ff->parrent->name << endl;
	if (ff->pref != "")
	{
		file* temp;
		temp = (file*)ff;
		os << "Data: "<< temp->data << endl;
	}
	return os;
}

int main()
{

	folder *root = new folder();
	root->name = "root";

	//test
	root->mkdir("123");
	root->mkdir("folderaa");
	root->mkdir("folderbb");
	root->mkdir("foldercc");
	root->mkdir("999");
	root = cd(root, "123");
	root->touch("FirstFile", "Abcsdoasdk");
	cout << root->inner[0]->inner[0];
	//test
	cout << root->inner[0];
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

		if (temple == "touch")
		{
			cin >> command; // name
			cout << "Please enter the data: "<< endl;
			string data;
			getline(cin, data);
			root->touch(command, data);
		}
		if (temple == "cd.." && root->parrent!=nullptr)
		{
			root = root->parrent;
		}
	}



    return 0;
}


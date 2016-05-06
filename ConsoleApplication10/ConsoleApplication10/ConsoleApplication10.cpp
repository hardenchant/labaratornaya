// ConsoleApplication10.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "folder.h"
#include "file.h"

using namespace std;


ostream& operator<<(ostream& os, const folder* ff) //subsidiary method for out-info
{
	os << "Name: " << ff->name.name << " Pref: " << ff->name.pref<< " Parrent: " << ff->parrent->name.name << endl;
	if (ff->name.pref != "")
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
	root->name.name = "root";

	//test
	root->mkdir("123");
	root->mkdir("folderaa");
	root->mkdir("folderbb");
	root->mkdir("foldercc");
	root->mkdir("999");
	root = root->cd("123");
	root->touch("FirstFile", "Abcsdoasdk");
	root = root->back();
	cout << root->inner[0]->inner[0];
	//test
	cout << root->inner[0];
	
	string temple;
	string command;
	
	while (temple != "end")
	{
		cin >> temple;

		if (temple == "list") root->list();
		if (temple == "cd")
		{
			cin >> command;
			root = root->cd(command);
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
			root = root->back();
		}
		if (temple == "del")
		{
			cin >> command;
			root->del(command);
		}
	}



    return 0;
}


// ConsoleApplication10.cpp: определ€ет точку входа дл€ консольного приложени€.
//

#include "stdafx.h"
#include "folder.h"
#include "file.h"
#include "fullname.h"

using namespace std;


ostream& operator<<(ostream& os, const file* ff) //перегрузка вывода дл€ записи в файл
{
	os << ff->name.name << ff->name.pref << " " << ff->readonly << " " << ff->parentuser << " " << ff->parrent->name.name <<" "<< ff->lvlin << endl << ff->data;
	return os;
}
ostream& operator<<(ostream& os, const folder* ff) //перегрузка вывода дл€ записи в файл
{
	os << ff->name.name << ff->name.pref <<  " " << ff->readonly << " " << ff->parentuser << " "<< ff->lvlin <<" ";
	if (ff->parrent == nullptr) {
		os << "root";
	}
	else
	{
		os << ff->parrent->name.name;
	}
	if (ff->name.pref != "") {
		file *ftemp = (file*)ff;
		os << endl << ftemp->data;
	}
	for (int i = 0; i < ff->inner.size(); i++)
	{
		os << endl << ff->inner[i];
	}

	return os;
}
folder *loadsys(string filename)
{
	folder *root;
	vector<folder*> buff;
	fullname name;
	string names, line, parentuser, parentfolder, data;
	bool readonly;
	int lvlin;

	ifstream fin(filename);
	while (!fin.eof())
	{
		fin >> names;
		fin >> readonly;
		fin >> parentuser;
		fin >> lvlin;
		fin >> parentfolder;
		name = names;
		if (name.pref == "") {
			 folder *buffold = new folder(names, readonly, parentuser, lvlin, parentfolder);
			buff.push_back(buffold);
			getline(fin, line);
		}
		else
		{
			getline(fin, line);
			getline(fin, data);
			 file *buffold = new file(names, readonly, parentuser, lvlin, parentfolder, data);
			buff.push_back(buffold);
		}
	}
	fin.close();
	//ѕ»Ћ»»»»»»»»»»»»»»»»»»“№
	root = buff[0];
	buff.erase(buff.begin());
	for (int j = 0; j < buff.size(); j++)
	{
		if (buff[j]->lvlin != 1) {
			for (int k = 0; k < buff.size(); k++)
			{
				if (buff[j]->parentfolder == buff[k]->name.name && buff[k]->lvlin == (buff[j]->lvlin - 1))
				{
					buff[k]->inner.push_back(buff[j]);
				}
			}
		}
		else
		{
			root->inner.push_back(buff[j]);
		}
	}
	cout << "System is loaded!" << endl;
	return root;
}


int main()
{
	user *us = new user();

	folder *root = new folder();
	root->name.name = "root";

	string temple;
	string command;

	cout << "Add user or load system" << endl;
	cin >> command;
	while (command != "adduser") {
		if (command == "loadsys")
		{
			cout << "File: ";
			cin >> command;
			root = loadsys(command);
			break;
		}
		if (command == "adduser") 
		{
			cin >> command;
			us->adduser(command);
			break;
		}
		cin >> command;
		cout << "Add user or load system" << endl;
	}
	/*while (command != "adduser" || command != "login") {
		cout << "Login or add user and login please" << endl;
		cin >> command;
		if (command == "adduser")
		{
			cin >> command;
			us->adduser(command);
			break;
		}
		if (command == "login")
		{
			cin >> command;
			us->login(command);
			break;
		}
	}*/
	while (command != "login")
	{
		cout << "Login please" << endl;
		cin >> command;
	}
	cin >> command;
	us->login(command);


	////test
	//root->mkdir("123",us->loguser);
	//root->mkdir("folderaa", us->loguser);
	//root->mkdir("folderbb", us->loguser);
	//root->mkdir("foldercc", us->loguser);
	//root->mkdir("999", us->loguser);
	//root->mkdir("a", us->loguser);
	//root->mkdir("b", us->loguser);
	//root->mkdir("c", us->loguser);
	//root->mkdir("asd", us->loguser);
	//root->mkdir("se3", us->loguser);
	//root->mkdir("sad14", us->loguser);
	//root->mkdir("ftwrrgw", us->loguser);
	//root->mkdir("ererwr", us->loguser);
	//root->mkdir("w34", us->loguser);
	//root->mkdir("t5ys", us->loguser);
	//root = root->cd("123", us);
	//root->mkdir("b", us->loguser);
	//root->mkdir("c", us->loguser);
	//root->mkdir("asd", us->loguser);
	//root->mkdir("se3", us->loguser);
	//root->mkdir("sad14", us->loguser);
	//root->mkdir("ftwrrgw", us->loguser);
	//root->mkdir("ererwr", us->loguser);
	//root->touch("FirstFile", "Abcsdoasdk", us->loguser);
	//root = root->back();
	//root = root->cd("999", us);
	//root->touch("FirstFile", "Abcsdoasdk", us->loguser);
	//root->touch("2", "Abcsdoa3211232131sdk", us->loguser);
	//root->touch("asdas", "Abcsdoas123213dk", us->loguser);
	//root->touch("34", "Abcsdo32432432rere34343434344sffsdfsdasdk", us->loguser);
	//root->touch("asddq2", "Abc434ddfdfdfsdoasdk", us->loguser);
	//root->mkdir("w34", us->loguser);
	//root->mkdir("t5ys", us->loguser);
	////root = root->cd("123");
	//root->mkdir("b", us->loguser);
	//root->mkdir("c", us->loguser);
	//root->mkdir("asd", us->loguser);
	//root->mkdir("se3", us->loguser);
	//root->mkdir("sad14", us->loguser);
	//root = root->cd("sad14", us);
	//root->mkdir("b", us->loguser);
	//root->mkdir("c", us->loguser);
	//root->mkdir("asd", us->loguser);
	//root->mkdir("se3", us->loguser);
	//root = root->back();
	//root = root->back();


	//cout << root;
	////test
	

	
	while (temple != "end")
	{
		cin >> temple;

		if (temple == "list") root->list();
		if (temple == "cd")
		{
			cin >> command;
			root = root->cd(command, us);
		}
		if (temple == "mkdir")
		{
			cin >> command;
			root->mkdir(command, us->loguser);
		}

		if (temple == "touch")
		{
			cin >> command; // name
			cout << "Please enter the data: " << endl;
			string data;
			cin.clear();
			while (cin.get() != '\n');
			getline(cin, data);
			root->touch(command, data, us->loguser);
		}
		if (temple == "cd.." && root->parrent!=nullptr)
		{
			root = root->back();
		}
		if (temple == "del")
		{
			cin >> command;
			root->del(command, us);
		}
		if (temple == "link")
		{
			cin >> command;
			cin >> temple;
			root->link(command, temple, us);
		}
		if (temple == "open")
		{
			cin >> command;
			root->open(command, us);
		}
		if (temple == "tree")
		{
			root->tree(0);
		}
		if (temple == "savesys")
		{
			cout << "File name: ";
			cin >> temple;
			temple += ".ini";
			ofstream fout(temple); 
			fout << root;
			
			fout.close();
		}
		/*if (temple == "loadsys")
		{
			cout << "File name: ";
			cin >> temple;
			temple += ".txt";
			ifstream fin(temple);
			fin >> temple;
			cout << temple;
			fin >> temple;
			cout << temple;
			fin >> temple;
			cout << temple;
			fin.close();
		}*/
		if (temple == "readonly")
		{
			cin >> temple;
			root->readonlyswitch(temple,us);
		}
		if (temple == "logout")
		{
			us->logout();
		}
		if (temple == "login")
		{
			cin >> temple;
			us->login(temple);
		}
		if (temple == "root")
		{
			us->getroot();
		}
		if (temple == "adduser") {
			cin >> command;
			us->adduser(command);
		}

	}



    return 0;
}


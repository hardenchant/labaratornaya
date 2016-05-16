// ConsoleApplication10.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "folder.h"
#include "file.h"

using namespace std;


ostream& operator<<(ostream& os, const file* ff) //перегрузка вывода для записи в файл
{
	os << ff->name.name << ff->name.pref << " " << ff->readonly << " " << ff->parentuser << " " << ff->parrent->name.name <<" "<< ff->lvlin << endl << ff->data << endl;
	return os;
}
ostream& operator<<(ostream& os, const folder* ff) //перегрузка вывода для записи в файл
{
	os << ff->name.name <<  " " << ff->readonly << " " << ff->parentuser << " "<< ff->lvlin <<" ";
	if (ff->parrent == nullptr) {
		os << "root" << endl;
	}
	else
	{
		os << ff->parrent->name.name << endl;
	}
	for (int i = 0; i < ff->inner.size(); i++)
	{
		os << ff->inner[i];
	}

	return os;
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
		cout << "Add user or load system" << endl;
		cin >> command;
	}
	if (command == "adduser") {
		cin >> command;
		us->adduser(command);
	}
	else
	{
		//загрузка системы из файла
	}
	cout << "Login please" << endl;
	cin >> command;
	while (command != "login")
	{
		cout << "Login please" << endl;
		cin >> command;
	}
	cin >> command;
	us->login(command);


	//test
	root->mkdir("123",us->loguser);
	root->mkdir("folderaa", us->loguser);
	root->mkdir("folderbb", us->loguser);
	root->mkdir("foldercc", us->loguser);
	root->mkdir("999", us->loguser);
	root->mkdir("a", us->loguser);
	root->mkdir("b", us->loguser);
	root->mkdir("c", us->loguser);
	root->mkdir("asd", us->loguser);
	root->mkdir("se3", us->loguser);
	root->mkdir("sad14", us->loguser);
	root->mkdir("ftwrrgw", us->loguser);
	root->mkdir("ererwr", us->loguser);
	root->mkdir("w34", us->loguser);
	root->mkdir("t5ys", us->loguser);
	root = root->cd("123", us->loguser);
	root->mkdir("b", us->loguser);
	root->mkdir("c", us->loguser);
	root->mkdir("asd", us->loguser);
	root->mkdir("se3", us->loguser);
	root->mkdir("sad14", us->loguser);
	root->mkdir("ftwrrgw", us->loguser);
	root->mkdir("ererwr", us->loguser);
	root->touch("FirstFile", "Abcsdoasdk", us->loguser);
	root = root->back();
	root = root->cd("999", us->loguser);
	root->touch("FirstFile", "Abcsdoasdk", us->loguser);
	root->touch("2", "Abcsdoa3211232131sdk", us->loguser);
	root->touch("asdas", "Abcsdoas123213dk", us->loguser);
	root->touch("34", "Abcsdo32432432rere34343434344sffsdfsdasdk", us->loguser);
	root->touch("asddq2", "Abc434ddfdfdfsdoasdk", us->loguser);
	root->mkdir("w34", us->loguser);
	root->mkdir("t5ys", us->loguser);
	//root = root->cd("123");
	root->mkdir("b", us->loguser);
	root->mkdir("c", us->loguser);
	root->mkdir("asd", us->loguser);
	root->mkdir("se3", us->loguser);
	root->mkdir("sad14", us->loguser);
	root = root->cd("sad14", us->loguser);
	root->mkdir("b", us->loguser);
	root->mkdir("c", us->loguser);
	root->mkdir("asd", us->loguser);
	root->mkdir("se3", us->loguser);
	root = root->back();
	root = root->back();


	cout << root;
	//test
	

	
	while (temple != "end")
	{
		cin >> temple;

		if (temple == "list") root->list();
		if (temple == "cd")
		{
			cin >> command;
			root = root->cd(command, us->loguser);
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
			temple += ".txt";
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

	}



    return 0;
}


#include "stdafx.h"
#include "user.h"

user::user() {
	rootaccess = false;
	loguser = "";
}
void user::getroot() {
	if (rootaccess == false) {
		rootaccess = true;
		cout << "Root accessed!" << endl;
	}
	else
	{
		rootaccess = false;
		cout << "Root denied!" << endl;
	}
}
void user::adduser(string name) {
	users.push_back(name);
	cout << "User added" << endl;
}
void user::login(string name) {
	if (loguser == "") 
	{
		for (int i = 0; i < users.size(); i++) {
			if (users[i] == name)
			{
				loguser = users[i];
				cout << "Hello " << users[i] << "!" << endl;
				return;
			}
		}
		cout << "User " << name << " not founded, please add user." << endl;
	}
	else
	{
		cout << "At first, logout pls, " << loguser << "!" << endl;
	}
}
void user::logout() {
	cout << "See you later, " << loguser << "!" << endl;
	loguser = "";
	string temp;
	cout << "Login please or add user and login" << endl;
	cin >> temp;
	if (temp == "adduser")
	{
		cin >> temp;
		adduser(temp);
	}
	while (temp != "login")
	{
		cin >> temp;
		if (temp == "adduser")
		{
			cin >> temp;
			adduser(temp);
		}
		cout << "Login please or add user and login" << endl;
	}
	cin >> temp;
	login(temp);
}
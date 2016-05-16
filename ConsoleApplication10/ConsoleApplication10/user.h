#pragma once

using namespace std;

class user {
public:
	vector<string> users;
	string loguser;
	bool rootaccess;
	user();
	void getroot();
	void adduser(string name);
	void login(string name);
	void logout();
};
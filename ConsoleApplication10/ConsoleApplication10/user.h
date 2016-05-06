#pragma once

using namespace std;

class user {
public:
	string name;
	bool rootaccess;
	user(string name);
	void getroot();
};
#pragma once

#include <string>
using namespace std;

class list {
private:
	string info;
	list *next;
public:
	list();
	void add(int i, string data);
	void get(int i);
	void del(int i);
};

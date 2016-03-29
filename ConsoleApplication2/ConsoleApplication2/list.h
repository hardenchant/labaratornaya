#pragma once

#include <string>
using namespace std;


class elements {
private:
	string data;
	elements *next;
public:
	elements();
	friend class list;
};

class list {
private:
	elements *e;
public:
	list();
	~list();
	void add(int i, string data);
	string get(int i);
	void del(int i);
};

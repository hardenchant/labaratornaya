// main.cpp: определяет точку входа для консольного приложения.
//
#include "stdafx.h"
#include "list.h"
#include <string>
#include <iostream>

using namespace std;

class stack {
private:
	string info;
	stack *next;
public:
	stack();
	void add(string data);
	string get();
	void del();
};

stack::stack()
{
	info = "";
	next = nullptr;
}
void stack::add(string data)
{
	info = data;
	stack *t;
	t = this;
	t = new stack();
	t->next = this;
}
string stack::get()
{
	return(info);
}
void stack::del()
{
	if (next = nullptr) cout << "All obj have been deleted" << endl;
	stack *p = this;
	stack *n;
	n = next;
	p->next = nullptr;
	p->info = "";
	delete p;
	p = n;
}


int main()
{
	int N;
	string command;
	cout << "Choose mode (stack, list, queue): ";
	cin >> command;
	cout << "Count of command: ";
	cin >> N;
	if (command == "list") {
		list spisok;
		int j;
		for (int i = 0; i < N; i++)
		{
			cin >> command;
			if (command == "add")
			{
				cin >> j;
				cin >> command;
				spisok.add(j, command);
			}
			if (command == "get")
			{
				cin >> j;
				cout << spisok.get(j) << endl;
			}
			if (command == "del")
			{
				cin >> j;
				spisok.del(j);
			}
		}
	}
	else if (command == "stack")
	{
		stack st;
		for (int i = 0; i < N; i++)
		{
			cin >> command;
			if (command == "add")
			{
				cin >> command;
				st.add(command);
			}
			if (command == "get")
			{
				cout << st.get() << endl;
			}
			if (command == "del")
			{
				st.del();
			}
		}
	}
	else
	{
		return 0;
	}

    return 0;
}


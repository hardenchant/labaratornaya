// lab5.16(timp).cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<int> dtree;

void add(int arg) {
	int i;
	if (dtree.size() == 0) {
		dtree.insert(dtree.begin(), arg);
	}
	else {
		for (i = 0; i < dtree.size(); i++) {
			if (arg <= dtree[i]) {
				dtree.insert(dtree.begin() + i, arg);
				break;
			}
		}
		if (i == dtree.size())
			dtree.push_back(arg);
	}
}

int main()
{
	string command;
	int n;
	int arg;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> command;
		if (command == "add")
		{
			cin >> arg;
			add(arg);
		}
		if (command == "get")
		{
			cout << dtree[0] << endl;
		}
		if (command == "del")
		{
			dtree.erase(dtree.begin());
		}
	}
	return 0;
}
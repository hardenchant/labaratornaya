#include "stdafx.h"
#include "search.h"

int searchf(fullname name, folder *fold) {
	
	for (int i = 0; i < fold->inner[0].size(); i++)
	{
		if (fold->inner[0][i]->name.name == name.name && fold->inner[0][i]->name.pref == name.pref)
		{
			return i;
		}
	}
	return -1; //if not founded
}

vector<fullname> parsepath(string path) {
	vector<fullname> tempvect;   //path parsing
	string tempstr = "";
	fullname *tempfn;
	for (int i = 1; i < path.length(); i++)
	{
		if (path[i] == '/')
		{
			tempfn = new fullname(tempstr);
			tempvect.push_back(*tempfn);
			tempstr = "";
		}
		else
		{
			tempstr = tempstr + path[i];
		}
	}
	tempfn = new fullname(tempstr);
	tempvect.push_back(*tempfn);	//end path parsing
	return tempvect;
}
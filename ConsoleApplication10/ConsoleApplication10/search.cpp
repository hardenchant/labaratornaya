#include "stdafx.h"
#include "search.h"

int search(fullname name, folder *fold) {
	
	for (int i = 0; i < fold->inner.size(); i++)
	{
		if (fold->inner[i]->name.name == name.name && fold->inner[i]->name.pref == name.pref)
		{
			return i;
		}
	}
	return -1; //if not founded
}
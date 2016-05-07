#include "stdafx.h"
#include "fullname.h"

fullname::fullname() {
	name = "";
	pref = "";
}

fullname::fullname(string fullname) {

	name = "";
	pref = "";
	for (int i = 0; i < fullname.size(); i++)
	{
		if (fullname[i] == '.')
		{
			for (int j = i; j < fullname.size(); j++)
			{
				pref = pref + fullname[j];
			}
			break;
		}
		else
		{
			name = name + fullname[i];
		}
	}
}

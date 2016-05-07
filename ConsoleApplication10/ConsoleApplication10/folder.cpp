#include "stdafx.h"
#include "folder.h"
#include "file.h"

using namespace std;



folder::folder() //for root-folder only?
{
	name.pref = "";
	parrent = nullptr;
}
folder::~folder() {
	for (int i = 0; i < inner.size(); i++)
	{
		delete &inner[i - 1];
	}
}
void folder::list() {
	for (int i = 0; i < inner.size(); i++)
	{
		cout << "|" << inner[i]->name.name << inner[i]->name.pref << endl;
	}
}
void folder::mkdir(string name) {
	folder *temp = new folder();
	temp->name.name = name;
	temp->parrent = this;
	inner.push_back(temp);
}
void folder::touch(string name, string data) {
	file *temp = new file();
	temp->name.name = name;
	temp->parrent = this;
	temp->data = data;
	inner.push_back(temp);
}
folder* folder::cd(string name) {
	for (int i = 0; i < this->inner.size(); i++)
	{
		if (this->inner[i]->name.name == name && this->inner[i]->name.pref == "")
		{
			return (this->inner[i]);
		}
	}
}
folder* folder::back() {
	return (this->parrent);
}
void folder::del(fullname delname) {

	for (int i = 0; i < this->inner.size(); i++)
	{
		if (this->inner[i]->name.name == delname.name && this->inner[i]->name.pref == delname.pref)
		{
			delete this->inner[i];
			this->inner.erase(this->inner.begin() + i);
		}
	}
}


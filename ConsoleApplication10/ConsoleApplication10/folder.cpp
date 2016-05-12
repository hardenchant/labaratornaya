#include "stdafx.h"
#include "folder.h"
#include "file.h"
#include "search.h"

using namespace std;



folder::folder() //for root-folder only?
{
	name.pref = "";
	parrent = nullptr;
}
folder::~folder() {
	for (int i = 0; i < inner.size(); i++)
	{
		delete inner[i];
	}
}
void folder::list() {
	if (inner.size() == 0)
	{
		cout << "|" << endl;
		return;
	}
	for (int i = 0; i < inner.size(); i++)
	{
		cout << "|" << inner[i]->name.name << inner[i]->name.pref << endl;
	}
}
void folder::mkdir(string name) {
	if (search(name, this)==-1)
	{
		folder *temp = new folder();
		temp->name = name;
		temp->parrent = this;
		inner.push_back(temp);
		return;
	}
		cout << "Name is required" << endl;
}
void folder::touch(string name, string data) {
	file *temp = new file();
	temp->name.name = name;
	temp->parrent = this;
	temp->data = data;
	inner.push_back(temp);
}
folder* folder::cd(string name) {
	if (search(name, this) == -1) {
		cout << "Folder not founded" << endl;
		return this;
	}
	return this->inner[search(name, this)];
}
folder* folder::back() {
	return (this->parrent);
}
void folder::del(string name) {
	int num = search(name, this);
	delete this->inner[num];
	this->inner.erase(this->inner.begin() + num);
}
void folder::link(fullname name, string path) {
	//poka 4to ne rabotaet
	// /file.f        /123/file.f      /123/333/213
	//parse '/' -> get ptr -> adde ptr for link -> added text in brackets (link) -> 
	vector<fullname> tempvect;
	string tempstr = "";
	fullname *tempfn;
	folder *root = this;
	while (root->parrent != nullptr) {
		root = root->parrent;
	}
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
	tempvect.push_back(*tempfn);
	//parse '/'

	for (int k = 0; k < tempvect.size(); k++)
	{
		for (int i = 0; i < root->inner.size(); i++)
		{
			if (root->inner[i]->name.name == tempvect[k].name && root->inner[i]->name.pref == tempvect[k].pref)
			{
				root = root->inner[i];
				//ololo
			}
		}
	}
	cout << root->name.name << root->name.pref << endl;
	
	if (root->name.pref == "") {
		folder *temp = root;
		temp->name = name;
	}
	else
	{

	}

}
void folder::open(fullname name) {
	folder *tempf = this->inner[search(name, this)];
	file *temp = (file*)tempf;
	cout << temp->data << endl;
	//дописать
}
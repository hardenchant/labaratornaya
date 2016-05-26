#include "stdafx.h"
#include "folder.h"
#include "file.h"
#include "search.h"


using namespace std;

folder::folder() //for root-folder only?
{
	name.pref = "";
	parrent = nullptr;
	readonly = false;
	lvlin = 0;
	parentuser = "root";
}
folder::folder(fullname name, bool readonly, string parentuser, int lvlin, string parentfolder) {
	this->name = name;
	this->readonly = readonly;
	this->parentuser = parentuser;
	this->lvlin = lvlin;
	this->parentfolder = parentfolder;
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
void folder::mkdir(string name, string parentuser) {
	if (searchf(name, this)==-1)
	{
		
		folder *temp = new folder();
		temp->name = name;
		temp->parrent = this;
		temp->parentuser = parentuser;
		temp->parentfolder = this->name.name;

		folder *lvl = temp;					//set the level in
		int lvlint = 0;
		while (lvl->parrent != nullptr)
		{
			lvlint++;
			lvl = lvl->parrent;
		}
		temp->lvlin = lvlint;

		inner.push_back(temp);
		return;
	}
		cout << "Name is required" << endl;
}
void folder::touch(string name, string data, string parentuser) {
	file *temp = new file();
	temp->name.name = name;

	if (searchf(temp->name, this) != -1)
	{
		delete temp;
		cout << "Name is required" << endl;
		return;
	}

	temp->parrent = this;
	temp->parentuser = parentuser;
	temp->data = "//   ";
	temp->data += data;
	temp->data += "   //";

	folder *lvl = temp;
	int lvlint = 0;
	while (lvl->parrent != nullptr)
	{
		lvlint++;
		lvl = lvl->parrent;
	}
	temp->lvlin = lvlint;

	inner.push_back(temp);
}
folder* folder::cd(string name, user *us) {
	if (searchf(name, this) == -1) {
		cout << "Folder "<< name <<" not founded" << endl;
		return this;
	}
	if ((inner[searchf(name, this)]->parentuser == us->loguser)&&(us->rootaccess!=true)) {
		return this->inner[searchf(name, this)];
	}
	else
	{
		cout << "No access!" << endl;
		return this;
	}
}
folder* folder::back() {
	if (this->parrent == nullptr) return this;
	return (this->parrent);
}
void folder::del(fullname name, user *us) {
	int num = searchf(name, this);
	if (num == -1)return; //if not founded
	if ((this->inner[num]->parentuser != us->loguser) && (us->rootaccess != true))
	{
		cout << "No access!" << endl;
		return;
	}
	if (this->inner[num]->readonly == true)
	{
		cout << "This folder/file is read-only." << endl;
		return;
	}
	if(this->inner[num]->name.pref!= ".link") delete this->inner[num];
	this->inner.erase(this->inner.begin() + num);
}
void folder::link(fullname name, string path, user *us) {
	vector<fullname> tempvect(parsepath(path));
	folder *root = this;
	while (root->parrent != nullptr) {	//go to root
		root = root->parrent;
	}


	for (int k = 0; k < tempvect.size(); k++)			//go to path
	{
		if (searchf(tempvect[k], root) == -1) return;
		root = root->inner[searchf(tempvect[k], root)];
	}

	if ((root->parentuser != us->loguser)&&(us->rootaccess!=true))
	{
		cout << "No access!" << endl;
		return;
	}
	
	if (root->name.pref != "") {
		cout << "File-link not supported))))" << endl;
		return;
	}
	folder *temp = new folder();
	temp->parrent = this;
	temp->inner = root->inner;
	temp->name = name;
	temp->name.pref = ".link";
	temp->parentuser = us->loguser;
	this->inner.push_back(temp);

}
void folder::open(fullname name, user *us) {
	if (searchf(name, this) == -1) return;
	file *temp = (file*)this->inner[searchf(name, this)];
	if ((temp->parentuser != us->loguser) && (us->rootaccess != true))
	{
		cout << "No access!" << endl;
		return;
	}
	cout << temp->data << endl;

	string temps;
	cin >> temps;
	while (temps!="close")
	{
		cout << "Close file, that continue. (Command: ""close"")" << endl;
		cin >> temps;
	}
}
void folder::tree(int tire) {
	if (inner.size() == 0)
	{
		return;
	}
	for (int i = 0; i < this->inner.size(); i++)
	{
		for (int g = 0; g < tire; g++)
		{
			cout << "  ";
		}
		
		cout << "|" << inner[i]->name.name << inner[i]->name.pref << endl;

		if (inner[i]->name.pref == "")
		{
			inner[i]->tree(tire + 1);
		}
		
	}
}
void folder::readonlyswitch(string name, user *us) {
	folder *temp = inner[searchf(name, this)];
	if ((temp->parentuser != us->loguser) && (us->rootaccess != true))
	{
		cout << "No access!" << endl;
		return;
	}
	if (temp->readonly == false)
	{
		temp->readonly = true;
		cout << temp->name.name << temp->name.pref << " is read-only" << endl;
	}
	else
	{
		temp->readonly = false;
		cout << temp->name.name << temp->name.pref << " isn't read-only" << endl;
	}
}

void folder::copy(string path_1, string path_2) {
	vector<fullname> path1(parsepath(path_1));
	vector<fullname> path2(parsepath(path_2));

}
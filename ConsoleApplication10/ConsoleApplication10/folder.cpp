#include "stdafx.h"
#include "folder.h"
#include "file.h"
#include "search.h"


using namespace std;

folder::folder() //for root-folder only?
{
	inner = new vector<folder*>;
	name.pref = "";
	parrent = nullptr;
	readonly = false;
	lvlin = 0;
	parentuser = "root";
}
folder::folder(fullname name, bool readonly, string parentuser, int lvlin, string parentfolder) {
	inner = new vector<folder*>;
	this->name = name;
	this->readonly = readonly;
	this->parentuser = parentuser;
	this->lvlin = lvlin;
	this->parentfolder = parentfolder;
}
folder::~folder() {
	for (int i = 0; i < inner[0].size(); i++)
	{
		delete inner[0][i];
	}
}
void folder::list() {
	if (inner->size() == 0)
	{
		cout << "|" << endl;
		return;
	}
	for (int i = 0; i < inner[0].size(); i++)
	{
		
		cout << "|" << inner[0][i]->name.name << inner[0][i]->name.pref << endl;
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

		inner[0].push_back(temp);
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

	inner[0].push_back(temp);
}
folder* folder::cd(string name, user *us) {
	if (searchf(name, this) == -1) {
		cout << "Folder "<< name <<" not founded" << endl;
		return this;
	}
	if ((inner[0][searchf(name, this)]->parentuser == us->loguser)&&(us->rootaccess!=true)) {
		return this->inner[0][searchf(name, this)];
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
	if ((this->inner[0][num]->parentuser != us->loguser) && (us->rootaccess != true))
	{
		cout << "No access!" << endl;
		return;
	}
	if (this->inner[0][num]->readonly == true)
	{
		cout << "This folder/file is read-only." << endl;
		return;
	}
	if(this->inner[0][num]->name.pref!= ".link") delete this->inner[0][num];
	this->inner[0].erase(this->inner[0].begin() + num);
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
		root = root->inner[0][searchf(tempvect[k], root)];
	}

	if ((root->parentuser != us->loguser)&&(us->rootaccess!=true))
	{
		cout << "No access!" << endl;
		return;
	}
	
	if (root->name.pref != "") {
		file *temp = new file();
		file *tempf = (file*)root;
		temp->parrent = this;
		temp->name = name;
		temp->name.pref = ".link";
		temp->parentuser = us->loguser;
		temp->data = tempf->data;
		this->inner[0].push_back(temp);
	}
	else
	{
		folder *temp = new folder();
		temp->parrent = this;
		temp->inner = root->inner;
		temp->name = name;
		temp->name.pref = ".link";
		temp->parentuser = us->loguser;
		this->inner[0].push_back(temp);
	}

}
void folder::open(fullname name, user *us) {
	if (searchf(name, this) == -1) return;
	file *temp = (file*)this->inner[0][searchf(name, this)];
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
	if (inner[0].size() == 0)
	{
		return;
	}
	for (int i = 0; i < this->inner[0].size(); i++)
	{
		for (int g = 0; g < tire; g++)
		{
			cout << "  ";
		}
		
		cout << "|" << inner[0][i]->name.name << inner[0][i]->name.pref << endl;

		if (inner[0][i]->name.pref == "")
		{
			inner[0][i]->tree(tire + 1);
		}
		
	}
}
void folder::readonlyswitch(string name, user *us) {
	folder *temp = inner[0][searchf(name, this)];
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

void folder::copy(string path_1, string path_2, user *us) {
	vector<fullname> path1_names(parsepath(path_1));
	vector<fullname> path2_names(parsepath(path_2));

	folder *path1 = this;
	while (path1->parrent != nullptr) {	//go to root
		path1 = path1->parrent;
	}
	for (int k = 0; k < path1_names.size(); k++)			//go to path 1
	{
		if (searchf(path1_names[k], path1) == -1) return;
		path1 = path1->inner[0][searchf(path1_names[k], path1)];
	}

	folder *path2 = this;
	while (path2->parrent != nullptr) {	//go to root
		path2 = path2->parrent;
	}
	for (int k = 0; k < path2_names.size(); k++)			//go to path 2
	{
		if (searchf(path2_names[k], path2) == -1) return;
		path2= path2->inner[0][searchf(path2_names[k], path2)];
	}

	if (path1->name.pref != "") {
		//copy file
		file *tempf = (file*)path1;
		file *temp = new file(tempf, us, path2);
		path2->inner[0].push_back(temp);
	}
	else
	{
		folder *temp = new folder(path1->name, path1->readonly, us->loguser, path1->lvlin, path2->name.name);
		path2->inner[0].push_back(temp);
		if (path1->inner[0].size() != 0) {
			for (int i = 0; i < path1->inner[0].size(); i++) {
				path1->copy(path_1 + "/" + path1->inner[0][i]->name.name + path1->inner[0][i]->name.pref, path_2 + "/" + temp->name.name, us);
			}
		}
	}
}

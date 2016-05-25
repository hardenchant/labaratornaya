#include "stdafx.h"
#include "file.h"
#include "search.h"
#include "fullname.h"

////for non-used methods
//void file::list() {}
//void file::mkdir(string name) {}
//void file::touch(string name) {}
//folder* file::cd(string name) { return nullptr; }
//folder* file::back() { return nullptr; }
//void file::link(fullname name, string path) {}

file::file() {
	name.pref = ".f";
	readonly = 0;
}
file::file(fullname name, bool readonly, string parentuser, int lvlin, string parentfolder, string data) :folder(name, readonly, parentuser, lvlin, parentfolder) {
	this->data = data;
}
file::~file() {
	data = "";
}
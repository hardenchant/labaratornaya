#include "stdafx.h"
#include "file.h"
#include "search.h"


//for non-used methods
void file::list() {}
void file::mkdir(string name) {}
void file::touch(string name) {}
folder* file::cd(string name) { return nullptr; }
folder* file::back() { return nullptr; }
void file::link(fullname name, string path) {}

file::file() {
	name.pref = ".f";
	readonly = 0;
}
file::~file() {
	data = "";
}
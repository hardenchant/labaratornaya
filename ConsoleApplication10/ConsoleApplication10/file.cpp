#include "stdafx.h"
#include "file.h"


//for non-used methods
void file::list() {}
void file::mkdir(string name) {}
void file::touch(string name) {}

file::file() {
	name.pref = ".f";
	readonly = 0;
}
file::~file() {
	data = "";
}
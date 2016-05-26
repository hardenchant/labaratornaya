#pragma once
#include "fullname.h"
#include "folder.h"

int searchf(fullname name, folder *fold); //search in folder folders or files function

vector<fullname> parsepath(string path); //parsing of path /.../.../...
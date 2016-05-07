#include "stdafx.h"
#include "user.h"

user::user(string name) {
	this->name = name;
	rootaccess = 0;
}
void user::getroot() {
	rootaccess = 1;
}
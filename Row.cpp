#include "Row.h"
using namespace std;

int Row::getID() {
	return id;
}

string Row::getType() {
	return type;
}

string Row::getName() {
	return name;
}

string Row::getBatter() {
	return batter;
}

string Row::getTopping() {
	return topping;
}

void Row::setID(int newid) {
	id = newid;
}

void Row::setType(string newtype) {
	type = newtype;
}

void Row::setName(string newname) {
	name = newname;
}

void Row::setBatter(string newbatter) {
	batter = newbatter;
}

void Row::setTopping(string newtopping) {
	topping = newtopping;
}















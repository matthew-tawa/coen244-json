// MATTHEW TAWA	  :: 40058819
// VICTOR TUDORAN :: 40057660

#include "Row.h"
using namespace std;

int Row::getID() const{
	return id;
}

string Row::getType() const{
	return type;
}

string Row::getName() const{
	return name;
}

string Row::getBatter() const{
	return batter;
}

string Row::getTopping() const{
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

void Row::print() {
	cout << setfill('0') << setw(4) << id << setfill(' ')
		 << setw(12) << type
		 << setw(12) << name
		 << setw(15) << batter
		 << setw(28) << topping << endl;
}














#include "item.h"
using namespace std;

// a vector that contains all of the possible batters
//
vector<string> item::AVAILbatters = {"Regular","Chocolate","Blueberry","Devil's Food"};

// a vector that contains all of the possible toppings
// the id of a topping is its position in this vector
vector<string> item::AVAILtoppings = {"None","Glazed","Sugar","Powdered Sugar","Chocolate with Sprinkles","Chocolate","Maple"};



int item::getID() {
	return id;
}

string item::getType() {
	return type;
}

string item::getName() {
	return name;
}

float item::getPPU() {
	return ppu;
}

// TODO get batters

// TODO get toppings

void item::setID(int newid) {
	id = newid;
}

void item::setType(string newtype) {
	type = newtype;
}

void item::setName(string newname) {
	name = newname;
}

void item::setPPU(float newppu) {
	ppu = newppu;
}

void item::addBatter(int newid) {
	vector<int>::iterator it;
	it = batters.begin();

	// iterating through 'batters', placing the new id in increasing order
	for (size_t i = 0; i < batters.size(); i++) {
		if (batters[i] > newid) {
			break;
		}
		it++;
	}

	batters.insert(it,newid);
}

void item::addTopping(int newid) {
	vector<int>::iterator it;
	it = toppings.begin();

	// iterating through 'batters', placing the new id in increasing order
	for (size_t i = 0; i < toppings.size(); i++) {
		if (toppings[i] > newid) {
			break;
		}
		it++;
	}

	toppings.insert(it,newid);
}

void item::removeBatter(int removeid) {
	int size = batters.size();

	for (int i = 0; i < size; i++) {
		if (batters[i] == removeid) {
			for (int j = i; j < size - 1; j++) {
				batters[j] = batters[j + 1];
			}
		}
	}
}

void item::removeTopping(int removeid) {
	int size = toppings.size();

	for (int i = 0; i < size; i++) {
		if (toppings[i] == removeid) {
			for (int j = i; j < size - 1; j++) {
				toppings[j] = toppings[j + 1];
			}
		}
	}
}














item::~item() {
	// TODO Auto-generated destructor stub
}


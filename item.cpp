// MATTHEW TAWA	  :: 40058819
// VICTOR TUDORAN :: 40057660

#include "Item.h"
using namespace std;

// a vector that contains all of the possible batters
//
vector<string> Item::AVAILbatters = {"Regular","Chocolate","Blueberry","Devil's Food"};

// a vector that contains all of the possible toppings
// the id of a topping is its position in this vector
vector<string> Item::AVAILtoppings = {"None","Glazed","Sugar","Powdered Sugar","Chocolate with Sprinkles","Chocolate","Maple"};



int Item::getID() const {
	return id;
}

string Item::getType() const {
	return type;
}

string Item::getName() const {
	return name;
}

float Item::getPPU() const {
	return ppu;
}

int Item::getBatterSize() const {
	return batters.size();
}

int Item::getToppingSize() const {
	return toppings.size();
}

string Item::getBatterString(int batterid) const {
	return AVAILbatters[batterid];
}

string Item::getToppingString(int toppingid) const {
	return AVAILtoppings[toppingid];
}

void Item::setID(int newid) {
	id = newid;
}

void Item::setType(string newtype) {
	type = newtype;
}

void Item::setName(string newname) {
	name = newname;
}

void Item::setPPU(float newppu) {
	ppu = newppu;
}

void Item::addBatter(int newid) {
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

void Item::addTopping(int newid) {
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

void Item::removeBatter(int removeid) {
	int size = batters.size();

	for (int i = 0; i < size; i++) {
		if (batters[i] == removeid) {
			for (int j = i; j < size - 1; j++) {
				batters[j] = batters[j + 1];
			}
		}
	}
}

void Item::removeTopping(int removeid) {
	int size = toppings.size();

	for (int i = 0; i < size; i++) {
		if (toppings[i] == removeid) {
			for (int j = i; j < size - 1; j++) {
				toppings[j] = toppings[j + 1];
			}
		}
	}
}












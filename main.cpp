#include "main.h"
using namespace std;



int main (int argc, const char * argv[]) {

	// parsing the file with jsoncpp
	// 'root' is the root of the tree that has all the json files information
	Json::CharReaderBuilder builder;
	Json::Value root;
	JSONCPP_STRING errs;
	bool ok = Json::parseFromStream(builder, cin, &root, &errs);

	// 'items' will be the c++ representation of all the items in the json file
	vector<item> items;
	int numitems = root["items"]["item"].size();
	items.resize(numitems);

	// for each item in the array of items, we want to create an item in our vector 'items'
	// that represents it
	for (int i = 0; i < numitems; i++) {

		int tempint;	// temporary variables simply to increase clarity
		float tempflt;
		string tempstr;

		// properly setting the 'id' of item[i]
		tempint = stoi(root["items"]["item"][i]["id"].asString());
		items[i].setID(tempint);

		// properly setting the 'type' of item[i]
		tempstr = root["items"]["item"][i]["type"].asString();
		items[i].setType(tempstr);

		// properly setting the 'name' of item[i]
		tempstr = root["items"]["item"][i]["name"].asString();
		items[i].setName(tempstr);

		// properly setting the 'ppu' of item[i]
		tempflt = root["items"]["item"][i]["ppu"].asFloat();
		items[i].setPPU(tempflt);

		// properly setting the 'batters' of item[i]
		int bsize = root["items"]["item"][i]["batters"]["batter"].size();
		for (int j = 0; j < bsize; j++) {
			// getting the batters name
			string batter = root["items"]["item"][i]["batters"]["batter"][j]["type"].asString();
			// using the batters name to get the batters id
			int batterid = getBatterID(batter);

			if (batterid < 0) {	// if the 'batterid' is less than 0, the batter was not found in the list of available batters
				// TODO: error count? different types of errors?
			} else {	// if the 'batterid' is valid, then add it to the array of batters for the given item
				items[i].addBatter(batterid);
			}

		}


		// properly setting the 'toppings' of item[i]
		int tsize = root["items"]["item"][i]["topping"].size();
		for (int k = 0; k < tsize; k++) {
			// getting the batters name
			string topping = root["items"]["item"][i]["topping"][k]["type"].asString();
			// using the batters name to get the batters id
			int toppingid = getToppingID(topping);

			if (toppingid < 0) {	// if the 'batterid' is less than 0, the batter was not found in the list of available batters
				// TODO: error count? different types of errors?
			} else {	// if the 'batterid' is valid, then add it to the array of batters for the given item
				items[i].addTopping(toppingid);
			}

		}


	}

	cout << items[1].getID() << endl << items[1].getType() << endl << items[1].getName() << endl;





	//string two = root["two"][1]["id"].asString();
// adding a new member to the object:
//	root["four"] = true;
//	two = root["four"].asString();

	cout << numitems << endl;

	return 0;
}






// gets the batter id of a given batter
// returns -1 if not in 'AVAILbatters'
int getBatterID(string btype) {
	for (size_t i = 0; i < item::AVAILbatters.size(); i++) {
		if (btype == item::AVAILbatters[i]) {
			return i;
		}
	}
	return -1;
}

// gets the topping id of a given topping
// returns -1 if not in 'AVAILtoppings'
int getToppingID(string ttype) {
	for (size_t i = 0; i < item::AVAILtoppings.size(); i++) {
		if (ttype == item::AVAILtoppings[i]) {
			return i;
		}
	}
	return -1;
}










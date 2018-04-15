// MATTHEW TAWA	  :: 40058819
// VICTOR TUDORAN :: 40057660

#include "main.h"
using namespace std;

// ----- INSTRUCTIONS TO CALL PROGRAM {
// 			in the command prompt, the program should be called as such:
//
//			FILE_EXE_PATH Field_to_sort <INPUT_FILE.txt >OUTPUT_FILE.txt
//
//			include the 'less than' and 'greater than' operators. they are used to redirect the
//			standard input/output of the file.
// ----- }

int main (int argc, const char * argv[]) {

	// checking to make sure the right number of arguments was used
	if (argc > 2) {
		cout << "Invalid number of arguments. Call in the following format:" << endl
			 << "FILE_EXE_PATH Field_to_sort < INPUT_FILE.txt > OUTPUT_FILE.txt" << endl << endl
			 << "NOTE: if no field to sort is specified, the default sort is by ID." << endl;
		exit(1);
	}


	// parsing the file with jsoncpp
	// 'root' is the root of the tree that has all the json files information
	Json::CharReaderBuilder builder;
	Json::Value root;
	JSONCPP_STRING errs;
	bool ok = Json::parseFromStream(builder, cin, &root, &errs);

	if (!ok) {	// if the file was not parsed correctly, exit
		cout << "ERROR: File could not be parsed. Please check JSON file and try again." << endl;
		exit(1);
	}



	// 'items' will be the c++ representation of all the items in the json file
	vector<Item> items;
	int numitems = root["items"]["item"].size();
	items.resize(numitems);



	// counts the number of errors encountered when creating the items array
	// these errors are due to invalid topping/batter names given in the json
	int battererrors = 0;
	int toppingerrors = 0;

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
			string batter = root["items"]["item"][i]["batters"]["batter"][j]["type"].asString(); // getting the batters name

			int batterid = getBatterID(batter);	// using the batters name to get the batters id

			if (batterid < 0) {	// if the 'batterid' is less than 0, the batter was not found in the list of available batters
				battererrors++;
			} else {	// if the 'batterid' is valid, then add it to the array of batters for the given item
				items[i].addBatter(batterid);
			}
		}

		// properly setting the 'toppings' of item[i]
		int tsize = root["items"]["item"][i]["topping"].size();
		for (int k = 0; k < tsize; k++) {
			string topping = root["items"]["item"][i]["topping"][k]["type"].asString(); // getting the batters name

			int toppingid = getToppingID(topping); // using the batters name to get the batters id

			if (toppingid < 0) {	// if the 'batterid' is less than 0, the batter was not found in the list of available batters
				toppingerrors++;
			} else {	// if the 'batterid' is valid, then add it to the array of batters for the given item
				items[i].addTopping(toppingid);
			}
		}
	}



	// after this for loop, we now have a vector 'items' that contains all of the items
	// that are described in the json file input to the program
	// the next step is to construct a table of all the combinations possible
	// once the table is made, then the users sorting can be performed

	Table table;	// the table where the info will be sorted

	// this loop will add all of the possible combinations to the table
	for (int i = 0; i < numitems; i++) {
		int v = items[i].getID();		// item id
		string w = items[i].getType();	// item type
		string x = items[i].getName();	// item name
		string y;	// will be used for batters
		string z;	// will be used for toppings

		for (int j = 0; j < items[i].getBatterSize(); j++) {	// for each batter
			for (int k = 0; k < items[i].getToppingSize(); k++) {	// for each topping, create a row
				y = items[i].getBatterString(j);	// getting a batter
				z = items[i].getToppingString(k);	// getting a topping

				Row* r = new Row(v,w,x,y,z);	// creating a new row
				table.addRow(*r);	// adding the new row to the table
			}
		}
	}



	// now that the table is created, it must be sorted according to the users input
	// if the user does not input a field, it is sorted by 'id' by default
	// otherwise it is sorted according to the users choice
	switch (argc) {
	case 1:	// no arguments -> sort by id
		table.sort("id");
		break;
	case 2:	// 1 argument   -> sort by given field
		string sortfield = argv[1];
		table.sort(sortfield);
		break;
	}



	// now that the table is sorted, it can be printed
	table.print();

	// and then the errors can be printed
	if (battererrors > 0 || toppingerrors > 0) {
		cout << endl << endl
			 << "Some errors were encountered when parsing." << endl
			 << setw(20) << "Number of invalid" << endl;
		if (battererrors > 0) {
			cout << setw(23) << "batters found:   " << battererrors << endl;
		}
		if (toppingerrors > 0) {
			cout << setw(23) << "toppings found:   " << toppingerrors << endl;
		}
	}

	return 0;
}



// gets the batter id of a given batter
// returns -1 if not in 'AVAILbatters'
int getBatterID(string btype) {
	for (size_t i = 0; i < Item::AVAILbatters.size(); i++) {
		if (btype == Item::AVAILbatters[i]) {
			return i;
		}
	}
	return -1;
}

// gets the topping id of a given topping
// returns -1 if not in 'AVAILtoppings'
int getToppingID(string ttype) {
	for (size_t i = 0; i < Item::AVAILtoppings.size(); i++) {
		if (ttype == Item::AVAILtoppings[i]) {
			return i;
		}
	}
	return -1;
}



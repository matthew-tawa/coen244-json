// MATTHEW TAWA	  :: 40058819
// VICTOR TUDORAN :: 40057660

#include "Table.h"
using namespace std;

int Table::getNumRows() {
	return rows.size();
}

void Table::setNumRows(int numrows) {
	rows.resize(numrows);
}

void Table::addRow(const Row& newrow) {
	rows.push_back(newrow);
}

void Table::sort(string field) {

	if (field == "id") {
		std::sort(rows.begin(), rows.end(), compareID);
	} else if (field == "type") {
		std::sort(rows.begin(), rows.end(), compareType);
	} else if (field == "name") {
		std::sort(rows.begin(), rows.end(), compareName);
	} else if (field == "batter") {
		std::sort(rows.begin(), rows.end(), compareBatter);
	} else if (field == "topping") {
		std::sort(rows.begin(), rows.end(), compareTopping);
	}
}

bool Table::compareID(const Row& a, const Row& b) {
	return a.getID() < b.getID();
}

bool Table::compareType(const Row& a, const Row& b) {
	return a.getType() < b.getType();
}

bool Table::compareName(const Row& a, const Row& b) {
	return a.getName() < b.getName();
}

bool Table::compareBatter(const Row& a, const Row& b) {
	return a.getBatter() < b.getBatter();
}

bool Table::compareTopping(const Row& a, const Row& b) {
	return a.getTopping() < b.getTopping();
}

void Table::print() {
	cout << setw(4) << "id"
		 << setw(12) << "type"
		 << setw(12) << "name"
		 << setw(15) << "batter"
		 << setw(28) << "topping" << endl

		 << setw(4) << "--"
		 << setw(12) << "----"
		 << setw(12) << "----"
		 << setw(15) << "------"
		 << setw(28) << "-------" << endl;


	for (size_t i = 0; i < rows.size(); i++) {
		rows[i].print();
	}
}





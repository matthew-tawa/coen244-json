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





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

void print() {

}





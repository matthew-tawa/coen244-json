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





// MATTHEW TAWA	  :: 40058819
// VICTOR TUDORAN :: 40057660

#ifndef TABLE_H_
#define TABLE_H_

// includes
#include <vector>
#include <algorithm>
#include "Row.h"
//

class Table {

public:
	// constructors & destructor {
	Table() {}
	virtual ~Table() {}
	// }

	// misc {
	int getNumRows();
	void setNumRows(int numrows);
	void addRow(const Row& newrow);

	void sort(std::string field);

	void print();
	// }



private:
	// members {
	std::vector<Row> rows;
	// }

	// methods {
	static bool compareID(const Row& a, const Row& b);
	static bool compareType(const Row& a, const Row& b);
	static bool compareName(const Row& a, const Row& b);
	static bool compareBatter(const Row& a, const Row& b);
	static bool compareTopping(const Row& a, const Row& b);
	// }
};

#endif /* TABLE_H_ */

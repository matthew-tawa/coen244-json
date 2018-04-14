#ifndef TABLE_H_
#define TABLE_H_

// includes
#include <vector>
#include "Row.h"
//

class Table {

public:
	// constructors & destructor {
	Table() {}
	virtual ~Table() {}
	// }

	// misc
	void sort(std::string field);
	//



private:
	// members {
	std::vector<Row> rows;
	// }

	// methods {
	// all the private sorting methods
	// }
};

#endif /* TABLE_H_ */

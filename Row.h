#ifndef ROW_H_
#define ROW_H_

// includes
#include <iostream>
#include <string>
//

class Row {

public:
	// constructors & destructor {
	Row() : id(0),type(""),name(""),batter(""),topping("") {}
	virtual ~Row() {}
	// }

	// get {
	int getID();
	std::string getType();
	std::string getName();
	std::string getBatter();
	std::string getTopping();
	// }

	// set {
	void setID(int newid);
	void setType(std::string newtype);
	void setName(std::string newname);
	void setBatter(std::string newbatter);
	void setTopping(std::string newtopping);
	// }

private:
	int id;
	std::string type;
	std::string name;
	std::string batter;
	std::string topping;

};

#endif /* ROW_H_ */

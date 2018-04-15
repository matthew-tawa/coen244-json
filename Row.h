// MATTHEW TAWA	  :: 40058819
// VICTOR TUDORAN :: 40057660

#ifndef ROW_H_
#define ROW_H_

// includes
#include <iostream>
#include <iomanip>
#include <string>
//

class Row {

public:
	// constructors & destructor {
	Row() : id(0),type(""),name(""),batter(""),topping("") {}
	Row(int _id,std::string _type,std::string _name,std::string _batter,std::string _topping) : id(_id),type(_type),name(_name),batter(_batter),topping(_topping) {}
	virtual ~Row() {}
	// }

	// get {
	int getID() const;
	std::string getType() const;
	std::string getName() const;
	std::string getBatter() const;
	std::string getTopping() const;
	// }

	// set {
	void setID(int newid);
	void setType(std::string newtype);
	void setName(std::string newname);
	void setBatter(std::string newbatter);
	void setTopping(std::string newtopping);
	// }

	// misc {
	void print();
	// }

private:
	int id;
	std::string type;
	std::string name;
	std::string batter;
	std::string topping;

};

#endif /* ROW_H_ */

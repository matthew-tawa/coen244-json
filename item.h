// MATTHEW TAWA	  :: 40058819
// VICTOR TUDORAN :: 40057660

#ifndef ITEM_H_
#define ITEM_H_

// includes
#include <iostream>
#include <vector>
//

class Item {

public:
	// constructors & destructor {
	Item() : id(0), type(""), name(""), ppu(0) {}
	Item(int _id, std::string _type,std::string _name,float _ppu,std::vector<int> _batters,std::vector<int> _toppings) : id(_id), type(_type), name(_name), ppu(_ppu), batters(_batters), toppings(_toppings) {}
	virtual ~Item() {}
	// }

	// get functions {
	int getID() const;
	std::string getType() const;
	std::string getName() const;
	float getPPU() const;
	int getBatterSize() const;
	int getToppingSize() const;

	std::string getBatterString(int batterid) const;
	std::string getToppingString(int toppingid) const;
	// }


	// set functions {
	void setID(int newid);
	void setType(std::string newtype);
	void setName(std::string newname);
	void setPPU(float newppu);
	void addBatter(int newid);
	void addTopping(int newid);
	void removeBatter(int removeid);
	void removeTopping(int removeid);
	// }

	// misc {
	friend int getBatterID(std::string btype);
	friend int getToppingID(std::string ttype);
	// }


private:
	int id;
	std::string type;
	std::string name;
	float ppu;
	std::vector<int> batters;
	std::vector<int> toppings;

	static std::vector<std::string> AVAILbatters;
	static std::vector<std::string> AVAILtoppings;
};

#endif /* ITEM_H_ */

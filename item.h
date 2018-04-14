#ifndef ITEM_H_
#define ITEM_H_

// includes
#include <iostream>
#include <vector>
//

class item {

public:
	// constructors & destructor {
	item() : id(0), type(""), name(""), ppu(0) {}
	item(int _id, std::string _type,std::string _name,float _ppu,std::vector<int> _batters,std::vector<int> _toppings) : id(_id), type(_type), name(_name), ppu(_ppu), batters(_batters), toppings(_toppings) {}
	virtual ~item();
	// }

	// get functions {
	int getID();
	std::string getType();
	std::string getName();
	float getPPU();
	// TODO get batters?
	// TODO get toppings?
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

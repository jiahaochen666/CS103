// Add include guards
#include "Vehicle.hpp"

class Airplane : public Vehicle
{
public:
	// Constructor, Airplanes can hold 250% more weight than
	// specified and double the size specified
	// ie. if w = 100, sz = 100, then 250 and 200 will be stored
	Airplane(std::string n, double sp, double w, int sz);


	// Airplanes only count 50% of a Fruit's weight
	// ie. if fruit.weight = 10, only 5 is added
	bool load(Fruit fruit);


	// If there is enough in cargo, Planes MUST unload five(5) Fruit 
	// at a time and return true, otherwise return false;
	// if there are < 5 Fruit, return false
	bool unload();


	// Subtract 20% of this Airplane's total current weight from its speed 
	// and add it to position
	void travel();


	// Destructor, what should be done here?
	~Airplane();
};

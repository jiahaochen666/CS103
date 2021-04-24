// Add include guards
#include "Automobile.hpp"

class Truck: public Automobile
{
public:
	// Constructor, Trucks have 50% more capacity than specified
	// ie. if sze = 20, 30 will be stored
	Truck(std::string n, double sp, double w, int sz);

	
	// Trucks only count 80% of a fruit's weight
	// ie. if fruit.weight = 10, only 8 is added
	bool load(Fruit fruit);


	// If not empty, Trucks unload two(2) Fruit at a time and
	// return true; if there is only one(1) Fruit, remove it and
	// return true, otherwise, return false
	bool unload();

	
	// Trucks are slower Vehicles. Subtract 15% of this Truck's
	// total current weight from its speed and add it to position
	void travel();


	//  Destructor, what should be done here?
	~Truck();
};



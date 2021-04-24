// Add include guards
#include "Vehicle.hpp"

class Automobile: public Vehicle
{
public:
	// Constructor, same as Vehicle
	Automobile(std::string n, double sp, double w, int sz);

	// Destructor, nothing needs to be done here
	~Automobile();
};


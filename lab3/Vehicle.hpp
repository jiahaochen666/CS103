// Add include guards
#include "Fruit.hpp"
#include <iomanip>

#ifndef __VEHICLE__HPP__
#define __VEHICLE__HPP__

class Vehicle
{
public:
	// Name of this vehicle
	std::string name;

	// Constructor takes a name, speed, max_weight, and max_size
	Vehicle(std::string n, double sp, double w, int sz);

	// Default constructor, nothing needs to be done here
	Vehicle();
	
	// If there is free space AND weight, add Fruit to cargo and 
	// return true; otherwise, return false
	virtual bool load(Fruit fruit);

	// If not empty, remove most recently added fruit from cargo and
	// return true; otherwise, return false
	virtual bool unload();

	// Adds speed to position
	virtual void travel();

	// Outputs information about this Vehicle to stdout
	virtual void peek();

	// Destructor, should clean up allocated memory
	virtual ~Vehicle();

protected: // Only derived classes can see data members
	// Current position, intially 0.0
	double pos;

	// Speed, initialized by constructor
	double speed;

	// Current total cargo weight, initially 0.0
	double current_weight;

	// Max total cargo weight, intialized by constructor
	double max_weight;

	// Current number of Fruit in cargo, initially 0
	int current_size;

	// Max Fruit in cargo, initialized by constructor
	int max_size;

	// Array of max_size Fruit, allcoated/initialized by constructor
	Fruit* cargo;
};

#endif
// Add include guards
#include "Airplane.hpp"
#include "Truck.hpp"
#include <vector>

class Garage
{
public:
	// Default constructor, nothing needs to be done here
	Garage();


	// Allocate a new Vehicle of the specified type and properties;
	// store it in the garage
	void park(char type, std::string name, double speed, double weight, int size);


	// Makes all Vehicles in this Garage travel
	void travel();


	// Peeks at all Vehicles in this Garage
	void view();


	// Destructor, what shoud be done here?
	~Garage();


	// Index operator, returns reference to Vehicle at specified
	// index; no error checking required
	Vehicle&  operator[](int i);

private:
	// Vector of Vehicle pointers
	std::vector<Vehicle*> vehicles;
};


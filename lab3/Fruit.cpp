#include "Fruit.hpp"



Fruit::Fruit(std::string n, double w)
	:name(n), weight(w) {}


Fruit::Fruit() {}


Fruit Fruit::operator = (const Fruit& fruit) {
	name = fruit.name;
	weight = fruit.weight;
	return *this;
}


Fruit::~Fruit() {}


std::ostream& operator << (std::ostream& out, const Fruit& fruit) {
	out << fruit.name;
	return out;
}
 

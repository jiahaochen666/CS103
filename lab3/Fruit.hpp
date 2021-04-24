#ifndef FRUIT_HPP
#define FRUIT_HPP

#include <iostream>
#include <string>


class Fruit
{
private:
	std::string name;

public:
	double weight;

	Fruit(std::string n, double w);

	Fruit();

	Fruit operator = (const Fruit& fruit);

	~Fruit();
	
	friend std::ostream& operator << (std::ostream& out, const Fruit& fruit);
};


#endif


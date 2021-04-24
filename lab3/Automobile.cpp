#include "Automobile.hpp"

Automobile::Automobile(std::string n, double sp, double w, int sz): Vehicle(std::move(n), sp, w, sz){}

Automobile::~Automobile(){}
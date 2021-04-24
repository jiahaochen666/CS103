#include "Garage.hpp"

Garage::Garage() = default;

void Garage::park(char type, std::string name, double speed, double weight, int size){
    Vehicle* automobile;
    switch (type)
    {
    case 'c':
        automobile = new Automobile(name, speed, weight, size);
        break;
    case 't':
        automobile = new Truck(name, speed, weight, size);
        break;
    default:
        automobile = new Airplane(name, speed, weight, size);
        break;
    }
    this->vehicles.push_back(automobile);
}

void Garage::travel(){
    for (auto* vehicle: this->vehicles){
        vehicle->travel();
    }
}

void Garage::view(){
    for (auto* vehicle: this->vehicles){
        vehicle->peek();
    }
}

Vehicle& Garage::operator[](int i){
    return *this->vehicles[i];
}

Garage::~Garage(){
    for (auto* vehicle: this->vehicles){
        delete vehicle;
    }
}
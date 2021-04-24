#include "Vehicle.hpp"

Vehicle::Vehicle(std::string n, double sp, double w, int sz){
    this->name = n;
    this->speed = sp;
    this->max_weight = w;
    this->max_size = sz;
    this->current_size = 0;
    this->current_weight = 0.0;
    this->pos = 0.0;
    this->cargo = new Fruit[this->max_size];
}

Vehicle::Vehicle() = default;

bool Vehicle::load(Fruit fruit){
    if (this->current_size < this->max_size && this->current_size <= this->max_weight){
        this->cargo[this->current_size] = fruit;
        this->current_size++;
        this->current_weight += fruit.weight;
        return true;
    }
    return false;
}

bool Vehicle::unload(){
    if (this->current_size > 0){
        this->current_size--;
        this->current_weight -= this->cargo[this->current_size].weight;
        return true;
    }
    return false;
}

void Vehicle::travel(){
    this->pos += this->speed;
}

void Vehicle::peek(){
    std::cout << std::fixed <<std::setprecision(2) <<this->name << " [" << this->current_size << "/" << this->max_size <<
        "] [" << this->current_weight << "/" << this->max_weight << "] [" << this->pos << "] (";
    if (this->current_size > 0){
        for (int i = 0; i < this->current_size - 1; i++){
            std::cout << this->cargo[i] << ",";
        }
        std::cout << this->cargo[this->current_size - 1];
    } 
    std::cout << ")" << std::endl;
}

Vehicle::~Vehicle(){
    delete[] this->cargo;
}
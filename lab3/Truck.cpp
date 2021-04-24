#include "Truck.hpp"

Truck::Truck(std::string n, double sp, double w, int sz): Automobile(std::move(n), sp, w, 1.5 * sz){}

bool Truck::load(Fruit fruit){
    if (this->current_size < this->max_size && this->current_size <= this->max_weight){
        this->cargo[this->current_size] = fruit;
        this->current_size++;
        this->current_weight += fruit.weight * 0.8;
        return true;
    }
    return false;
}

bool Truck::unload(){
    if (this->current_size > 1){
        this->current_size--;
        this->current_weight -= this->cargo[this->current_size].weight * 0.8;
        this->current_size--;
        this->current_weight -= this->cargo[this->current_size].weight * 0.8;
        return true;
    }
    else if(this->current_size > 0){
        this->current_size--;
        this->current_weight -= this->cargo[this->current_size].weight * 0.8;
        return true;
    }
    return false;
}

void Truck::travel(){
    this->pos += this->speed - 0.15 * this->current_weight;
}

Truck::~Truck(){}
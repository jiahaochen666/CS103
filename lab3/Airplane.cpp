#include "Airplane.hpp"

Airplane::Airplane(std::string n, double sp, double w, int sz) : Vehicle(n, sp, 2.5 * w, 2 * sz){}


bool Airplane::load(Fruit fruit){
    if (this->current_size < this->max_size && this->current_size <= this->max_weight){
        this->cargo[this->current_size] = fruit;
        this->current_size++;
        this->current_weight += 0.5 * fruit.weight;
        return true;
    }
    return false;
}

bool Airplane::unload(){
    if (this->current_size >= 5){
        int i = 0;
        while (i < 5){
            this->current_size--;
            this->current_weight -= this->cargo[this->current_size].weight * 0.5;
            i++;
        }
        return true;
    }
    return false;
}

void Airplane::travel(){
    this->pos += this->speed - 0.2 * this->current_weight;
}

Airplane::~Airplane(){}
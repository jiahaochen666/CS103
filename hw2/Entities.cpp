#include "Entities.hpp"
#include <iostream>

Item::Item(const std::string &name) {
    this->name = name;
}


Armor::Armor(const std::string &name, int defense) : Item(name){
    this->defense = defense;
}


Weapon::Weapon(const std::string &name, int damage) : Item(name){
    this->damage = damage;
}


Health::Health(int hitpoints) {
    this->hitpoints = hitpoints;
    this->total_hitpoints = hitpoints;
}


Enemy::Enemy(const std::string &name, int hitpoints, int damage) {
    this->name = name;
    this->health = Health(hitpoints);
    this->damage = damage;
}


Encounter::Encounter(const Enemy &enemy, Item *loot) {
    this->enemy = enemy;
    this->loot = loot;
}


void Backpack::add_item(Item *item) {
    this->items.push_back(item);
}


void Character::equip(Armor *armor) {
    this->armor = armor;
}

void Character::equip(Weapon *weapon) {
    this->weapon = weapon;
}
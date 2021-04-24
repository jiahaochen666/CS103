#include "Modes.hpp"
#include <algorithm>
#include <iostream>
#include <string>

using namespace std;

const ModeType ExplorationMode::T = ModeType::Exploration;
const ModeType InventoryMode::T = ModeType::Inventory;
const ModeType FightingMode::T = ModeType::Fighting;

CommandResult Mode::base_command(std::string s, ModeType mode)
{
    if (s == "exit")
        return CommandResult::Quit;
    else if (s == "help")
    {
        cout << "Available commands: ";
        if (mode == ModeType::Exploration)
            cout << "exit, explore, health, help, inventory" << endl;
        else if (mode == ModeType::Inventory)
            cout << "close, equip, exit, health, help, inventory, list" << endl;
        else
            cout << "attack, exit, health, help, info, inventory" << endl;
    }
    else if (s == "health")
        cout << "Health: " << state_->character.health.hitpoints << " / " << state_->character.health.total_hitpoints
             << "." << endl;
    else
    {
        cout << "Opened inventory." << endl;
        return CommandResult::Switch_In;
    }
    return CommandResult::Success;
}

CommandResult ExplorationMode::handle_command()
{
    string input;
    cin >> input;
    if (input == "explore")
    {
        cout << "You wander through the wilderness until you suddenly encounter an enemy." << endl;
        return CommandResult::Switch_Fi;
    }
    return Mode::base_command(input, ModeType::Exploration);
}

CommandResult InventoryMode::handle_command()
{
    string input;
    cin >> input;
    if (input == "list")
    {
        int counter = 1;
        for (Item *i : this->state_->character.backpack.items)
        {
            cout << "Item " << counter++ << ": " << i->name << ", ";
            if (i->get_type() == 1)
                cout << "Weapon, "
                     << "damage " << i->get_int() << endl;
            else
                cout << "Armor, "
                     << "defense " << i->get_int() << endl;
        }
        return CommandResult::Success;
    }
    else if (input == "equip")
    {
        int num;
        cout << "Enter item number:\n";
        cin >> num;
        if (this->state_->character.backpack.items[num - 1]->get_type() == 0)
        {
            Armor *temp = std::move(this->state_->character.armor);
            this->state_->character.equip(std::move((Armor *)this->state_->character.backpack.items[num - 1]));
            this->state_->character.backpack.items[num - 1] = std::move(temp);
        }
        else
        {
            Weapon *temp = std::move(this->state_->character.weapon);
            this->state_->character.equip(std::move((Weapon *)this->state_->character.backpack.items[num - 1]));
            this->state_->character.backpack.items[num - 1] = std::move(temp);
        }
        cout << "Item equipped." << endl;
        return CommandResult::Success;
    }
    else if (input == "close")
    {
        cout << "Closed inventory." << endl;
        return CommandResult::Switch_Ex;
    }
    return Mode::base_command(input, ModeType::Inventory);
}

CommandResult FightingMode::handle_command()
{
    string input;
    cin >> input;
    if (input == "info")
    {
        cout << "Enemy health: " << this->state_->encounters.front().enemy.health.hitpoints << " / "
             << this->state_->encounters.front().enemy.health.total_hitpoints << endl;
        return CommandResult::Success;
    }
    else if (input == "attack")
    {
        this->state_->encounters.front().enemy.health.hitpoints -= this->state_->character.weapon->damage;
        int damage_receive;
        if (this->state_->encounters.front().enemy.damage - this->state_->character.armor->defense > 0)
        {
            damage_receive = this->state_->encounters.front().enemy.damage - this->state_->character.armor->defense;
            this->state_->character.health.hitpoints -= damage_receive;
        }
        else
            damage_receive = 0;
        if (this->state_->encounters.front().enemy.health.hitpoints <= 0)
        {
            if (this->state_->encounters.front().loot)
                this->state_->character.backpack.add_item(this->state_->encounters.front().loot);
            this->state_->encounters.pop();
            if (this->state_->encounters.empty())
            {
                cout << "You won!" << endl;
                return CommandResult::Quit;
            }
            else
            {
                cout << "You defeated the enemy!" << endl;
                return CommandResult::Switch_Ex;
            }
        }
        if (this->state_->character.health.hitpoints <= 0)
        {
            cout << "You died!" << endl;
            return CommandResult::Quit;
        }
        else
        {
            cout << "You both attack. You dealt " << this->state_->character.weapon->damage << " damage and received "
                 << this->state_->encounters.front().enemy.damage << "-" << this->state_->character.armor->defense
                 << "=" << damage_receive
                 << " damage." << endl;
            return CommandResult::Success;
        }
    }
    return Mode::base_command(input, ModeType::Fighting);
}

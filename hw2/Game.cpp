#include "Game.hpp"
#include <iostream>
#include <string>

Game::Game(State &&state) {
    this->state_ = std::move(state);
}

void Game::run() {
    ExplorationMode ex; InventoryMode in; FightingMode fi;
    std::string name;
    std::cout << "Please enter a name:\n";
    std::cin >> name;
    std::cout << "Let the adventure begin, " << name << "!" << std::endl;
    this->state_.character.name = name;
    std::cout << "\nEnter command (or help):\n";
    Mode * mode = &ex;
    while (true){
        mode->connect_state(&this->state_);
        CommandResult rs = mode->handle_command();
        if (rs == CommandResult::Quit)
            break;
        else if(rs == CommandResult::Switch_Ex)
            mode = &ex;
        else if (rs == CommandResult::Switch_In)
            mode = &in;
        else if (rs == CommandResult::Switch_Fi)
            mode = &fi;
        std::cout << "\nEnter command (or help):\n";
    }
}

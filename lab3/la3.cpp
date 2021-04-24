#include "Garage.hpp"

int main() {
    Garage g{};
    char cmd;
    while (std::cin >> cmd) {
        if(cmd == 'v'){
            std::string name = "";
            char type;
            double speed, weight;
            int size;
            std::cin >> type >> name >> speed >> weight >> size;
            g.park(type, name, speed, weight, size);
            std::cout << "parked " << name << std::endl;
        }
        else if (cmd == 'l'){
            int index;
            std::string name;
            double weight;
            std::cin >> index >> name >> weight;
            if (g[index].load(Fruit(name, weight))){
                std::cout << "loaded " << name << " onto " << g[index].name << std::endl;
            }
            else
                std::cout << "load failed" << std::endl;
        }
        else if (cmd == 'u'){
            int index;
            std::cin >> index;
            if (g[index].unload()){
                std::cout << "unloaded from " << g[index].name << std::endl;
            }
            else
                std::cout << "unload failed" << std::endl;
        }
        else if (cmd == 't'){
            g.travel();
            std::cout << "traveled" << std::endl;
        }
        else if (cmd == 'p'){
            g.view();
        }
		else
			std::cin.ignore(255, '\n');
    }
    return 0;
}


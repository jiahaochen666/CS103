//
// Created by jiaha on 5/4/2021.
//

#include "Scene.h"

Scene::Scene(std::string path) {
    this->file.open(path);
    std::string line;
    while (std::getline(this->file, line)){
        std::istringstream ss{line};
        std::string type;
        ss >> type;
        if (type == "camera"){
            ss.ignore(2);

        }
    }
}

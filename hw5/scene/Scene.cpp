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
            std::vector<double> vector = get_three(ss);
            Point pos = {vector[0], vector[1], vector[2]};
            ss.ignore(2);
            vector = get_three(ss);
            Point view = {vector[0], vector[1], vector[2]};
            ss.ignore(1);
            int w, h;
            ss >> w;
            ss.ignore(1);
            ss >> h;
            this->camera = Camera(pos, view, h, w);
        }
        else if (type == "sphere"){
            ss.ignore(2);
            std::vector<double> vector = get_three(ss);
            Point center = {vector[0], vector[1], vector[2]};
            ss.ignore(1);
            int r;
            ss >> r;
            Primitive* s = new Sphere{center, r};
            this->objects.push_back(s);
        }
        else if(type == "plane"){
            ss.ignore(2);
            std::vector<double> vector = get_three(ss);
            Point pos = {vector[0], vector[1], vector[2]};
            ss.ignore(2);
            vector = get_three(ss);
            Vector view = {vector[0], vector[1], vector[2]};
            Primitive* s = new Plane{pos, view};
            this->objects.push_back(s);
        }
    }
}

std::vector<double> Scene::get_three(std::istringstream &ss) {
    std::vector<double> out;
    for(int i = 0; i < 3; i++){
        double num;
        ss >> num;
        ss.ignore();
        out.push_back(num);
    }
    return out;
}

Scene::~Scene() {
    for(int i = 0; i < this->objects.size(); i++){
        delete this->objects[i];
    }
}

std::vector<Intersection> Scene::find_intersection(Ray& ray) {
    double distance = std::numeric_limits<double>::max();
    Intersection closest{};
    int check = 0;
    for(auto* object: this->objects){
        std::vector<Intersection> temp = object->intersections(ray);
        if(!temp.empty()){
            for(auto inter: temp){
                if (distance > inter.distance){
                    distance = inter.distance;
                    closest = inter;
                }
            }
        }
        else
            check++;
    }
    //std::cout << distance << "\n";
    return check != this->objects.size() ?  std::vector<Intersection>{closest} : std::vector<Intersection>{};
}



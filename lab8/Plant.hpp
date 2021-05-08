#ifndef LA8_PLANT_HPP
#define LA8_PLANT_HPP

#include <string>
#include <ostream>

struct Plant {
    std::string name;
    int start, end;

    Plant(std::string n, int s, int e): name(n), start(s), end(e) {}

    Plant& operator=(const Plant& p) {
        name = p.name;
        end = p.end;
        start = p.start;
        return *this;
    }


    friend std::ostream &operator<<(std::ostream &os, const Plant &plant) {
        os << plant.name;
        return os;
    }
	
	// Add more methods here

	bool operator>(Plant& other) const {
        return this->start > other.start;
    }

    bool operator<(Plant& other) const {
        return this->start < other.start;
    }

};

#endif //LA8_PLANT_HPP

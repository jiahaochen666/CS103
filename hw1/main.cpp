#include <iostream>
#include "LinkedList.hpp"
#include "HashMap.hpp"

int main() {
    std::string word = "";
    HashMap h{};
    while (std::cin >> word){
        h[word]++;
        }
    for (HashMap::Iterator iter = h.begin(); iter != h.end(); ++iter) {
        std::cout << iter->first << "  -  " << iter->second << std::endl;
    }
    return 0;
}

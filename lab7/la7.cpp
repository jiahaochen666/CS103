#include <iostream>
#include <map>
#include <string>

// For this learning activity, you are encouraged to
// use ONLY for(auto) loops (no low-level C loops)
// and std::map (no other data structures).


// Returns true if s is an anagram of word
bool anagram(std::string word, std::string s) {
    std::map<char, int> map_1, map_2;
    if (word.length() != s.length())
        return false;
    for (auto& c: word){
        if (map_1.find(c) == map_1.end())
            map_1.insert(std::pair<char, int>{c, 1});
        else
            map_1[c]++;
    }
    for (auto& c: s){
        if (map_2.find(c) == map_2.end())
            map_2.insert(std::pair<char, int>{c, 1});
        else
            map_2[c]++;
    }
    for (auto & p: map_1){
        if(map_2.find(p.first) == map_2.end())
            return false;
        else if (map_2[p.first] != p.second)
            return false;
    }
    return true;
}


int main(int argc, char* argv[]) {
    if(argc != 2) {
        return -1;
    }

    std::string word = argv[1];
    std::string s;
    while(std::cin >> s) {
        std::cout << anagram(word, s) << std::endl;
    }


    return 0;
}

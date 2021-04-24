#ifndef LA4_STREETNODE_HPP
#define LA4_STREETNODE_HPP

#include <iostream>


struct StreetNode {
    int id;
    StreetNode *left, *right, *next;

    StreetNode(int i, StreetNode* l, StreetNode* r, StreetNode* n);
    StreetNode(const StreetNode& node);

    friend std::ostream& operator<<(std::ostream& out, const StreetNode& node);

    ~StreetNode()=default;
};


#endif //LA4_STREETNODE_HPP

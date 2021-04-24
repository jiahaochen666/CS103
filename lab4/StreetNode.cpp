#include "StreetNode.hpp"

StreetNode::StreetNode(int i, StreetNode *l, StreetNode *r, StreetNode *n)
{
    id = i;
    left = l;
    right = r;
    next = n;
}

StreetNode::StreetNode(const StreetNode &node)
{
    id = node.id;
    left = node.left;
    right = node.right;
    next = node.next;
}

std::ostream &operator<<(std::ostream &out, const StreetNode &node)
{
    out << node.id;
    return out;
}

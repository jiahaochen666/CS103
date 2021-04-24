#include "StreetMap.hpp"

StreetMap::StreetMap() {
    this->head = nullptr;
    this->curr = nullptr;
}

StreetMap::StreetMap(const StreetMap &map) {
    this->head = StreetMap::copy_streets(map.head);
    this->curr = this->head;
}

void StreetMap::insert(int i) {
    StreetNode *temp = new StreetNode{i, nullptr, nullptr, this->head};
    this->head = temp;
}

void StreetMap::connect_left(int a, int b) {
    StreetNode* a1 = get_street(this->head, a);
    StreetNode* b1 = get_street(this->head, b);
    a1->left = b1;
}

void StreetMap::connect_right(int a, int b) {
    StreetNode* a1 = get_street(this->head, a);
    StreetNode* b1 = get_street(this->head, b);
    a1->right = b1;
}

void StreetMap::restart() {
    this->curr = this->head;
}

void StreetMap::walk() {
    if (this->curr)
        this->curr = this->curr->next;
}

void StreetMap::turn_left() {
    if (this->curr)
        this->curr = this->curr->left;
}

void StreetMap::turn_right() {
    if (this->curr)
        this->curr = this->curr->right;
}

StreetMap &StreetMap::operator=(const StreetMap &map) {
    this->head = StreetMap::copy_streets(map.head);
    this->curr = this->head;
    return *this;
}

std::ostream &operator<<(std::ostream &out, const StreetMap &map) {
    if (map.curr)
        out << "(" << map.curr->id << "," << map.curr->left ->id<< "," << map.curr->right->id << ")";
    else
        out << "-";
    return out;
}

StreetMap::~StreetMap() {
    StreetMap::delete_streets(this->head);
}

StreetNode *StreetMap::get_street(StreetNode *head, int i) {
    StreetNode* cur = head;
    int counter = 0;
    while (counter < i) {
        cur = cur->next;
        counter++;
    }
    return cur;
}

StreetNode *StreetMap::copy_streets(StreetNode *head) {
    StreetNode *temp = new StreetNode{*head};
    while (temp->next) {
        StreetNode *next = new StreetNode(*temp->next);
        temp->next = next;
        temp = temp->next;
    }
    return head;
}

void StreetMap::delete_streets(StreetNode *head) {
    if (head)
        return;
    StreetNode* next = head->next;
    StreetNode* left = head->left;
    StreetNode* right = head->right;
    delete head;
    delete_streets(left);
    delete_streets(right);
    delete_streets(next);
}



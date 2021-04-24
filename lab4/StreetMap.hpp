// Add include guards
#include "StreetNode.hpp"


class StreetMap {
public:
    // Default Constructor, inits pointers to nullptr
    StreetMap();

    // Copy Constructor
    StreetMap(const StreetMap &map);

    // Inserts a new StreetNode with id i at head
    void insert(int i);

    // Connects left of StreetNode at index a
    // to StreetNode at index b
    void connect_left(int a, int b);

    // Connects left of StreetNode at index a
    // to StreetNode at index b
    void connect_right(int a, int b);

    // Resets curr to point at head
    void restart();

    // Moves curr to next StreetNode
    void walk();

    // Moves curr to left StreetNode
    void turn_left();

    // Moves curr to right StreetNode
    void turn_right();

    // Assignment operator
    StreetMap& operator=(const StreetMap& map);

    // Prints out relevant ids of curr StreetNode in form:
    // (id, id of left, id of right)
    friend std::ostream& operator<<(std::ostream& out, const StreetMap& map);

    // Destructor
    ~StreetMap();

private:
    StreetNode *head, *curr;

    // Helper to return StreetNode at index i
    static StreetNode* get_street(StreetNode* head, int i);

    // Helper to copy linked list of StreetNodes
    // Challenge: Can you do it in O(n) time?
    static StreetNode* copy_streets(StreetNode* head);

    // Helper to delete linked list of StreetNodes
    static void delete_streets(StreetNode* head);
};

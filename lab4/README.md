# Instructions

* The starter code contains a mostly completed class StreetNode. Each street node represents a street, with an identifier and connections for a left turn and right turn. It can also connect to another street as a linked list via next. Assume that the left and right pointers of a given StreetNode may only point at other StreetNodes in the same linked list.
![image](https://user-images.githubusercontent.com/59080187/115944022-51bfa400-a468-11eb-9d0d-ea76e1781436.png)
* Implement the functions declared for class StreetMap. A StreetMap is implemented as a linked list of StreetNodes. 
  * A few static helper functions are declared as guidelines.
  * Pay particular attention to the copy constructor and assignment operator (there are some clever things you can accomplish with the pointers).
* Read the comments carefully! 
* A partially completed main function is provided that declares an array of three (3) StreetMaps. It takes one int argument (n), inserts n StreetNodes into the first StreetMap, and (pseudo) randomly connects the left and right pointers of each StreetNode. In the section labeled YOUR CODE HERE, complete the main function so your program will recognize the following commands:
* Your code will be tested with n = 10, 50, 100, 500
* If a node is unavailable, print just a dash ' - '.

Command | Description | Expected Output
| :--- | :--- | :---
L | <li>walk on maps[0]</li> <li>turn left on maps[1]</li> <li>turn right on maps[2]</li> | <li>( id, id of left, id of right )  // For maps[0]</li> <li>( id, id of left, id of right )  // For maps[1]</li> <li>( id, id of left, id of right )  // For maps[2]</li>
R | <li>walk on maps[0]</li> <li>turn right on maps[1]</li> <li>turn left on maps[2]</li> | <li>( id, id of left, id of right )  // For maps[0]</li> <li>( id, id of left, id of right )  // For maps[1]</li> <li>( id, id of left, id of right )  // For maps[2]</li>
Z | Resets all StreetMaps back to the beginning | <li>( id, id of left, id of right )  // For maps[0]</li> <li>( id, id of left, id of right )  // For maps[1]</li> <li>( id, id of left, id of right )  // For maps[2]</li>

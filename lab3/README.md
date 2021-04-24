# PART I: Classes

* Implement the functions declared for the following classes: Vehicle, Automobile, Truck, Airplane
* Read the comments carefully! 
* The class hierarchy is as follows:
  * Vehicle is the base class
  * Automobile is derived from Vehicle
  * Airplane is derived from Vehicle
  * Truck is derived from Automobile
* Pay particular attention to constructors, destructors, and memory management.
* For the method peek( ), the Vehicle information should be printed as follows:
Name  [current_size/max_size]  [current_weight/max_weight]  [pos]  (list of Fruit in cargo, comma-delimited)
ie.  Lamborghini  [5/50]  [4.62/55.55]  [0.00]  (apple,apple,apple,orange,orange)


# PART II: Simple Shell

Implement the functions declared for class Garage. This will serve as a container for Vehicles.
Your program should be able to recognize the following commands:
Command Format | Description | Expected Output
| :---: | :---: | :---:
v [type] [Vehicle_name] [speed] [weight] [size] | Parks a new Vehicle in the garage with the specified characteristics; Vehicle types are c(Automobile), t(Truck), p(Airplane) | parked [name]
l [index] [Fruit_name] [weight]	| Loads Fruit with specified name and weight onto Vehicle located at specified index in Garage | loaded [Fruit_name] onto [Vehicle_name] OR load failed
u [index]	| Unload from Vehicle located at specified index in Garage | unloaded from [Vehicle_name] OR unload failed 
t | Makes all Vehicles in the Garage travel | traveled
p | Peeks at (outputs) all Vehicles in the Garage | Vehicle_name  [current_size/max_size]  [current_weight/max_weight]  [pos]  (list of Fruit in cargo, comma-delimited)...

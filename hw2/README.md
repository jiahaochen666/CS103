## A Simple RPG Game with Text
In this homework you will write a primitive text-based RPG. The player can control a character to manage their inventory and fight enemies in a turn-based manner. The player controls the character by issuing commands. Depending on in what context you are in, different commands are available. This context is determined by the current mode. There are three modes: exploration, inventory and fighting. There are also some commands that are always available, like checking the players health, listing available commands or exiting the game.

To win the game, the player must defeat enemies in a series of encounters. Every encounter presents one enemy and the possibility of acquiring some new equipment upon defeating the enemy. If the player's hit points fall to zero, the game is over.

In order for us to be able to grade reliably, there won't be any randomness in the game. The starter code contains some initial state and encounters that our tests are based on. Please do not modify them or restore them before submitting.

Start by downloading and inspecting the starter code

# The entities
In Entities.hpp you will find already all the entities for this project declared. These entities are objects that together represent the state of the game. Note that Item is an an abstract class, so we need to use it as a pointer everywhere in the code. You need to implement the constructors that are already defined in order for main to be able to initialize the game. You can add any helper methods to the entities you need in order to implement the game logic.

# The state
The State class contains the current game state. That is, it contains the character, all encounters including enemies and all items. Note that we store items as unique_ptr, so they are automatically deallocated when the game ends. We are not trying to delete items once they are not used anymore to reduce the complexity of memory management in our game. It also contains a queue for the encounters that the player faces. You can add any variables and helper function you need to that class.

# The modes
Depending on the context, the player can issue only a certain set of commands. These different contexts are called modes in our game. Think of vim: vim has different modes, like normal mode, which is the default mode to navigate an manipulate text, insert mode to write text or visual mode to select text visually. Our game slightly builds on this idea: the exploration mode is to explore the world, inventory mode to manipulate the inventory contents and equip weapons and armor and the fighting mode to attack and view infos about enemies during encounters.

All these modes derive from a base class Mode, which implements common functionality and some commands, that are always available. A Mode executes one command at a time by reading the next command from standard input. After processing the command, it returns a status, whether command execution was successful, whether to switch to a different mode (e.g. opening inventory/entering fight) or end the program. You can define a struct containing that information (you could use an enum with the values success (do nothing), switch (switch mode), quit (quit game) and use the ModeType enum to indicate to which mode you want to switch). The Game class evaluates the result (see below).

To implement the modes, you need to add a pure virtual function in the base class (i.e. something like virtual CommandResult handle_command() = 0;, where CommandResult is the result struct discussed in the previous paragraph), which handles the next command. Then in each derived mode class, you need to overwrite this method. In this method, you read the next command from cin (which is always a single word) into a string and execute it by calling an appropriate private method. If the command does not exist, you can call a method in the base class Mode which tries to handle the inventory, help, health and exit commands. If it is none of those commands, print the error message.

Alternative with using std::function: you could add a map in Mode from the name of the command (which is a string) to std::function<CommandResult>, where CommandResult is the result struct discussed in the previous paragraph). Then in each derived mode class, you need to add handlers to this map for every command. In mode you can then read the next command from cin, look it up in the map and execute it, if it exists.

# Base mode commands
The commands are always available:

* health: prints player health
* inventory: switches to inventory mode
* help: prints currently available commands
* exit: exits the game
#Exploration mode commands
This is the default mode after starting the game.

* explore: navigates to the next encounter and switches into fighting mode
# Inventory mode commands
* list: list items in inventory
* equip: equips a weapon or armor item from the inventory. If the character is already wearing a weapon or armor, put it in the inventory before equipping the new item.
* close: return to explore mode
# Fighting mode commands
* info: view enemy health
* attack: attacks the enemy. This reduces the enemy's hitpoints by the damage of your weapon. The character's hitpoints get reduced by the damage of the enemy minus the defense of the currently worn armor (this can't be negative of course). If the character's hitpoints go below zero, you loose. If the enemy's hitpoints go below zero, you win this encounter and are rewarded with the loot. If this was the last encounter, you win the game and the game ends.
# The game
The Game class is the core class that essentially keeps track of the current mode. It constructs all three modes and stores them in a map (with ModeType as a key). You probably need to pass State as a pointer to each mode.

The run method of the game first asks for the players name and then enters exploration mode. Then it'll keep asking the current mode to handle the next command and evaluates the result (i.e. it checks whether you need to switch to a different mode or whether to exit the game, otherwise just handle the next command).

# Where do I start?
In the tests folder of the start code are many tests that describe the input and output of the game. Start with the small tests.

Start with implementing Game first, so you can actually run and test the game. Then do first the exit, help and health commands to cover basic functionality. Then inventory (and close in inventory mode) and explore (in exploration mode) to switch to the different modes. And finally you do list and equip for the inventory, and attack and info for the fighting mode.

You are free to make any modifications to the starter code and add any helper functions you need. The autograder does only input/output tests.

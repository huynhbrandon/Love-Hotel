#include "Game.hpp"
#include<iostream>
#include "Space.hpp"
#include "Alex.hpp"
#include "Jess.hpp"
#include "Morgan.hpp"
#include "Pat.hpp"
#include "Robin.hpp"
#include "lobby.hpp"
using std::cout;
using std::endl;

Game::Game(){}

/***********************************
 * ~Game() : deallocate memory of spaces
 * *********************************/
Game::~Game(){
	delete main;
	delete room1;
	delete room2;
	delete room3;
	delete room4;
	delete room5;
	
}

/*********************************************
 * setPeople(): sets up the hotel by allocating memory of the pointers to space, set the names of the rooms, sets the items in each room, sets the hobbies of each character in each room, and connects each room in a linked list of pointers
 * *******************************************/
void Game::setPeople(){
	//create rooms
	main = new Lobby;
	room1 = new Alex;
	room2 = new Jess;
	room3 = new Morgan;
	room4 = new Pat;
	room5 = new Robin;

	//Set names of rooms
	main->setName("Lobby");
	room1->setName("Alex");
	room2->setName("Jess");
	room3->setName("Morgan");
	room4->setName("Pat");
	room5->setName("Robin");
	
	//Add hobby to each person
	room1->setHobby1("Manga");
	room1->setHobby2("Cast iron skillet");

	room2->setHobby1("Basketball");
	room2->setHobby2("Tent");
	
	room3->setHobby1("Shakespeare");
	room3->setHobby2("Hiking boots");
	
	room4->setHobby1("Speedo");
	room4->setHobby2("Camera");

	room5->setHobby1("Ballet shoes");
	room5->setHobby2("Bear");


	//Add items to each room
	room1->setItem1("Basketball");
	room1->setItem2("Hiking boots");
	
	room2->setItem1("Manga");
	room2->setItem2("Camera");
	
	room3->setItem1("Cast iron skillet");
	room3->setItem2("Tent");

	room4->setItem1("Ballet shoes");
	room4->setItem2("Bear");

	room5->setItem1("Shakespeare");
	room5->setItem2("Speedo");

	//Connect rooms
	main->setUpLeft(room5);
	main->setUpRight(room1);
	main->setLeft(room4);
	main->setRight(room2);
	main->setDown(room3);

	//room1->
	room1->setLeft(main);
	room1->setDown(room2);
	
	//room2
	room2->setLeft(main);
	room2->setDown(room3);
	room2->setUp(room1);
	
	//room3
	room3->setUp(main);
	room3->setRight(room2);
	room3->setLeft(room4);

	//room4
	room4->setRight(main);
	room4->setUp(room5);
	room4->setDown(room3);

	//room5
	room5->setRight(main);
	room5->setDown(room4);
}	


/************************************
 * run(): runs the game by initializing game with 10 health, depleting as each room is visited, allowing user to see kisses received and bag contents, and updates current spaces to call derived action methods
 * ***********************************/
void Game::run(){
	Player player;
	setPeople();
	Space* current = main;

	int health = 20;
	
	
	while(health != 0){
		display(current);

		
		cout << "\nCurrent health: " << health << endl;
		cout << "Kisses received: " << player.getKisses() << endl;
		cout << "Bag: ";
		player.displayBag();
		
		cout << "\nBag size: " << player.getSize() << "\n" << endl;

		//room action initiate
		current->action(current, player);


		Space* nextRoom = current->menu(current);
		current = nextRoom; // set next room to do stuff
		health--;

		if(player.getKisses() ==  3){
			cout << "Winner! Please enjoy a paid stay here at the Love Hotel!" << endl;
			break;
		}
	}
	//loser with not enough kisses
        if(player.getKisses() != 3){
		cout << "You have fainted from lack of kisses." << endl;
		cout << "Better luck next time!" << endl;
		cout << "Get out." << endl;

	}

	
	
}

/*****************************************************
 * display(): displays the hotel in the beginning to show users
 * ****************************************************/
void Game::display(){
	cout << endl;
	cout << "       |----------|                       |----------|	\n";
	cout << "       |     5    |                       |     1    |	\n";
	cout << "      /|  Robin   |\\                     /|   Alex   |\\	\n";
	cout << "     / |          | \\                   / |          | \\	\n";
	cout << "    /  |----------|  \\                 /  |----------|  \\      \n";
	cout << "   |                  \\               /                  |  \n";
	cout << "   |                   \\ ___________ /                   |    \n";
	cout << "    \\  |----------|     |           |     |----------|  /        \n";
	cout << "     \\ |    4     |     |           |     |    2     | /         \n";
        cout << "      \\|   Pat    |-----|   Lobby   |-----|   Jess   |/         \n";
	cout << "       |          |     |           |     |          |         \n";
	cout << "       |----------|     |___________|     |----------|                   \n";
	cout << "          \\                   |                   /             \n"; 
	cout << "            \\                 |                 /              \n";
	cout << "              \\         ______|______         /               \n";
	cout << "                \\       |     3     |       /                   \n";
	cout << "                  \\     |           |     /                     \n";
	cout << "                    \\   |  Morgan   |   /                      \n";
	cout << "                      \\ |           | /                         \n";
	cout << "                        |-----------|                          \n";
}

/*******************************************
 * display(Space*) : overloaded display method that displays position in the hotel based off of Space argument given
 * ******************************************/
void Game::display(Space* current){

	if(current->getName() == "Lobby"){
	cout << endl;
	cout << "       |----------|                       |----------|	\n";
	cout << "       |    5     |                       |    1     |	\n";
	cout << "      /|  Robin   |\\                     /|  Alex    |\\	\n";
	cout << "     / |          | \\                   / |          | \\	\n";
	cout << "    /  |----------|  \\                 /  |----------|  \\      \n";
	cout << "   |                  \\               /                  |  \n";
	cout << "   |                   \\ ___________ /                   |    \n";
	cout << "    \\  |----------|     |           |     |----------|  /        \n";
	cout << "     \\ |    4     |     |           |     |    2     | /         \n";
        cout << "      \\|   Pat    |-----|   (*__*)  |-----|  Jess    |/         \n";
	cout << "       |          |     |           |     |          |         \n";
	cout << "       |----------|     |___________|     |----------|                   \n";
	cout << "          \\                   |                   /             \n"; 
	cout << "            \\                 |                 /              \n";
	cout << "              \\         ______|______         /               \n";
	cout << "                \\       |     3     |       /                   \n";
	cout << "                  \\     |           |     /                     \n";
	cout << "                    \\   |   Morgan  |   /                      \n";
	cout << "                      \\ |           | /                         \n";
	cout << "                        |-----------|                          \n";
	}else if(current->getName() == "Alex"){
	cout << endl;
	cout << "       |----------|                       |----------|	\n";
	cout << "       |    5     |                       |          |	\n";
	cout << "      /|  Robin   |\\                     /| (*__*)   |\\	\n";
	cout << "     / |          | \\                   / |          | \\	\n";
	cout << "    /  |----------|  \\                 /  |----------|  \\      \n";
	cout << "   |                  \\               /                  |  \n";
	cout << "   |                   \\ ___________ /                   |    \n";
	cout << "    \\  |----------|     |           |     |----------|  /        \n";
	cout << "     \\ |    4     |     |           |     |    2     | /         \n";
        cout << "      \\|   Pat    |-----|   Lobby   |-----|  Jess    |/         \n";
	cout << "       |          |     |           |     |          |         \n";
	cout << "       |----------|     |___________|     |----------|                   \n";
	cout << "          \\                   |                   /             \n"; 
	cout << "            \\                 |                 /              \n";
	cout << "              \\         ______|______         /               \n";
	cout << "                \\       |     3     |       /                   \n";
	cout << "                  \\     |           |     /                     \n";
	cout << "                    \\   |   Morgan  |   /                      \n";
	cout << "                      \\ |           | /                         \n";
	cout << "                        |-----------|                          \n";
	}else if(current->getName() == "Jess"){
	cout << endl;
	cout << "       |----------|                       |----------|	\n";
	cout << "       |    5     |                       |    1     |	\n";
	cout << "      /|  Robin   |\\                     /|  Alex    |\\	\n";
	cout << "     / |          | \\                   / |          | \\	\n";
	cout << "    /  |----------|  \\                 /  |----------|  \\      \n";
	cout << "   |                  \\               /                  |  \n";
	cout << "   |                   \\ ___________ /                   |    \n";
	cout << "    \\  |----------|     |           |     |----------|  /        \n";
	cout << "     \\ |    4     |     |           |     |          | /         \n";
        cout << "      \\|   Pat    |-----|   Lobby   |-----| (*__*)   |/         \n";
	cout << "       |          |     |           |     |          |         \n";
	cout << "       |----------|     |___________|     |----------|                   \n";
	cout << "          \\                   |                   /             \n"; 
	cout << "            \\                 |                 /              \n";
	cout << "              \\         ______|______         /               \n";
	cout << "                \\       |     3     |       /                   \n";
	cout << "                  \\     |           |     /                     \n";
	cout << "                    \\   |   Morgan  |   /                      \n";
	cout << "                      \\ |           | /                         \n";
	cout << "                        |-----------|                          \n";
	}else if(current->getName() == "Morgan"){
	cout << endl;
	cout << "       |----------|                       |----------|	\n";
	cout << "       |    5     |                       |     1    |	\n";
	cout << "      /|  Robin   |\\                     /|   Alex   |\\	\n";
	cout << "     / |          | \\                   / |          | \\	\n";
	cout << "    /  |----------|  \\                 /  |----------|  \\      \n";
	cout << "   |                  \\               /                  |  \n";
	cout << "   |                   \\ ___________ /                   |    \n";
	cout << "    \\  |----------|     |           |     |----------|  /        \n";
	cout << "     \\ |    4     |     |           |     |    2     | /         \n";
        cout << "      \\|   Pat    |-----|   Lobby   |-----|  Jess    |/         \n";
	cout << "       |          |     |           |     |          |         \n";
	cout << "       |----------|     |___________|     |----------|                   \n";
	cout << "          \\                   |                   /             \n"; 
	cout << "            \\                 |                 /              \n";
	cout << "              \\         ______|______         /               \n";
	cout << "                \\       |           |       /                   \n";
	cout << "                  \\     |           |     /                     \n";
	cout << "                    \\   |   (*__*)  |   /                      \n";
	cout << "                      \\ |           | /                         \n";
	cout << "                        |-----------|                          \n";
	}else if(current->getName() == "Pat"){
	cout << endl;
	cout << "       |----------|                       |----------|	\n";
	cout << "       |    5     |                       |     1    |	\n";
	cout << "      /|  Robin   |\\                     /|   Alex   |\\	\n";
	cout << "     / |          | \\                   / |          | \\	\n";
	cout << "    /  |----------|  \\                 /  |----------|  \\      \n";
	cout << "   |                  \\               /                  |  \n";
	cout << "   |                   \\ ___________ /                   |    \n";
	cout << "    \\  |----------|     |           |     |----------|  /        \n";
	cout << "     \\ |          |     |           |     |    2     | /         \n";
        cout << "      \\|  (*__*)  |-----|   Lobby   |-----|  Jess    |/         \n";
	cout << "       |          |     |           |     |          |         \n";
	cout << "       |----------|     |___________|     |----------|                   \n";
	cout << "          \\                   |                   /             \n"; 
	cout << "            \\                 |                 /              \n";
	cout << "              \\         ______|______         /               \n";
	cout << "                \\       |     3     |       /                   \n";
	cout << "                  \\     |           |     /                     \n";
	cout << "                    \\   |  Morgan   |   /                      \n";
	cout << "                      \\ |           | /                         \n";
	cout << "                        |-----------|                          \n";

	}else if(current->getName() == "Robin"){
	cout << endl;
	cout << "       |----------|                       |----------|	\n";
	cout << "       |          |                       |    1     |	\n";
	cout << "      /| (*__*)   |\\                     /|  Alex    |\\	\n";
	cout << "     / |          | \\                   / |          | \\	\n";
	cout << "    /  |----------|  \\                 /  |----------|  \\      \n";
	cout << "   |                  \\               /                  |  \n";
	cout << "   |                   \\ ___________ /                   |    \n";
	cout << "    \\  |----------|     |           |     |----------|  /        \n";
	cout << "     \\ |    4     |     |           |     |    2     | /         \n";
	cout << "      \\|   Pat    |-----|   Lobby   |-----|  Jess    |/         \n";
	cout << "       |          |     |           |     |          |         \n";
	cout << "       |----------|     |___________|     |----------|                   \n";
	cout << "          \\                   |                   /             \n"; 
	cout << "            \\                 |                 /              \n";
	cout << "              \\         ______|______         /               \n";
	cout << "                \\       |     3     |       /                   \n";
	cout << "                  \\     |           |     /                     \n";
	cout << "                    \\   |  Morgan   |   /                      \n";
	cout << "                      \\ |           | /                         \n";
	cout << "                        |-----------|                          \n";
	}
}

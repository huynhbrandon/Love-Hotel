/******************
* Program Name: Love Hotel
* Author: Brandon Huynh
* Date: December 4, 2018
* Description: A game that allows users to navigate the Love Hotel, looking for items in different rooms to gift to its inhabitants in exchange for some SMOOCHES!
**********************/

#include "Game.hpp"
#include <iostream>
#include <string>
using std::cout;
using std::endl;

int main(){
	std::string enter;
	Game love;

	cout << "*********************************************************************" << endl;
	cout << "* Welcome to the Love Hotel!                                        *" << endl;
	cout << "* Try your hand at getting three kisses from our inhabitants to win *" << endl;
	cout << "* an all expense paid stay at our luxurious hotel!                  *" << endl;
	cout << "*						                     *" << endl;			
	cout << "* Rules & How to Win:                                               *" << endl;
	cout << "* 1. You start out with 20 health. It depletes everytime you enter  *" << endl;
	cout << "*    a room.                                                        *" << endl;
	cout << "* 2. Go into the inhabitants rooms to find out what they like! Use  *" << endl;
	cout << "*    this information to find items that can woo them!              *" << endl;
	cout << "* 3. Items are scattered across the rooms.                          *" << endl;
	cout << "* 4. After giving two gifts to an inhabitant, you will get a kiss!  *" << endl;
	cout << "* 5. 3 kisses = WINNER!                                             *" << endl;
	cout << "* 6. You can hold 6 items in your bag. If full, you must give items *" << endl;
	cout << "*    away!                                                          *" << endl;
	cout << "* 7. Try to keep track of what people are interested in!            *" << endl;                                                               
	cout << "* 8. Once you have 3 kisses, head to the lobby!                     *" << endl;
	cout << "* 9. Interact with the inhabitants to give them items!              *" << endl;
	cout << "*                                                                   *" << endl;
	cout << "* Created by Brandon Huynh                                          *" << endl;
	cout << "*********************************************************************" << endl;

	love.display();

	cout << "Hit ENTER to continue..." << endl;
	std::getline(std::cin, enter);

	love.run();

	return 0;
}

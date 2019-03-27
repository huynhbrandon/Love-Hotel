#include "Space.hpp"
#include <iostream>
#include <string>
#include "menu.hpp"
#include "inputVal.hpp"

/******************************************
 * Space(): Space constructor setting all member pointers to null
 * ****************************************/
Space::Space(){
	setUp(nullptr);
	setDown(nullptr);
	setLeft(nullptr);
	setRight(nullptr);
	setUpRight(nullptr);
	setUpLeft(nullptr);
}

/*********************************
 * ~Space() : destructor
 * ****************************/
Space::~Space(){}


/*****************************************************
 * Menu(Space*): function that displays the available rooms to navigate between. returns the address to be used by Game.run() to set the new current room

 * *****************************************************/
Space* Space::menu(Space* current){
	int choice;
	// IN LOBBY
	if(current->getName() == "Lobby"){
		Menu lobbyMenu;
		lobbyMenu.addOption("1. Go to Room 1");
		lobbyMenu.addOption("2. Go to Room 2");
		lobbyMenu.addOption("3. Go to Room 3");
		lobbyMenu.addOption("4. Go to Room 4");
		lobbyMenu.addOption("5. Go to Room 5");
		lobbyMenu.display();

		checkInt(choice, 1,5);
		switch(choice){
			case 1:
				return current->getUpRight();
			case 2:
				return current->getRight();
			case 3: 
				return current->getDown();
			case 4: 
				return current->getLeft();
			case 5:
				return current->getUpLeft();
			default:
				std::cout << "Invalid. Try Again." << std::endl;
		} 
	//ALEX'S ROOM
	}else if(current->getName() == "Alex"){
		
		Menu menu1;
		menu1.addOption("1. Go to Lobby");
		menu1.addOption("2. Go to Room2");
		menu1.display();

		checkInt(choice, 1,2);
		switch(choice){
			case 1:
				return current->getLeft();
			case 2:
				return current->getDown();
			default:
				std::cout << "Invalid. Try again." << std::endl;
		}
	//JESS'S ROOM
	}else if(current->getName() == "Jess"){

		Menu menu2;
		menu2.addOption("1. Go to Lobby");
		menu2.addOption("2. Go to Room 1");
		menu2.addOption("3. Go to Room 3");
		menu2.display();

		checkInt(choice,1,3);
		switch(choice){
			case 1:
				return current->getLeft();
			case 2:
				return current->getUp();
			case 3:
				return current->getDown();
			default:
				std::cout << "Invalid. Try again." << std::endl;
		}
	//MORGANS ROOM
	}else if(current->getName() == "Morgan"){

		Menu menu3;
		menu3.addOption("1. Go to Lobby");
		menu3.addOption("2. Go to Room 2");
		menu3.addOption("3. Go to Room 4");
		menu3.display();
		
		checkInt(choice,1,3);
		switch(choice){
			case 1:
				return current->getUp();
			case 2:
				return current->getRight();
			case 3:
				return current->getLeft();
			default:
				std::cout << "Invalid. Try again." << std::endl;
		}
	//PATS ROOM
	}else if(current->getName() == "Pat"){
	
		Menu menu4;
		menu4.addOption("1. Go to Lobby");
		menu4.addOption("2. Go to Room 3");
		menu4.addOption("3. Go to Room 5");
		menu4.display();
		
		checkInt(choice,1,3);
		switch(choice){
			case 1:
				return current->getRight();
			case 2:
				return current->getDown();
			case 3:
				return current->getUp();
			default:
				std::cout << "Invalid. Try again." << std::endl;
		}
	//ROBINS ROOM
	}else if(current->getName() == "Robin"){

		Menu menu5;
		menu5.addOption("1. Go to Lobby");
		menu5.addOption("2. Go to Room 4");
		menu5.display();

		checkInt(choice,1,2);
		switch(choice){
			case 1:
				return current->getRight();
			case 2:
				return current->getDown();
			default:
				std::cout << "Invalid. try again." << std::endl;
		}
	}

}	


std::string Space::getItem1(){
	return item1;
}

std::string Space::getItem2(){
	return item2;
}

void Space::setItem1(std::string itemIn){
	item1 = itemIn;
}

void Space::setItem2(std::string itemIn){
	item2 = itemIn;
}

void Space::setName(std::string nameIn){
	name = nameIn;
}

std::string Space::getName(){
	return name;
}

void Space::setHobby1(std::string hobby1In){
	hobby1 = hobby1In;
}

void Space::setHobby2(std::string hobby2In){
	hobby2 = hobby2In;
}

std::string Space::getHobby1(){
	return hobby1;
}

std::string Space::getHobby2(){
	return hobby2;
}

void Space::setUp(Space* upIn){
	up = upIn;
}

void Space::setDown(Space * downIn){
	down = downIn;
}

void Space::setLeft(Space* leftIn){
	left = leftIn;
}

void Space::setRight(Space* rightIn){
	right = rightIn;
}

void Space::setUpLeft(Space* upLeftIn){
	upLeft = upLeftIn;
}

void Space::setUpRight(Space* upRightIn){
	upRight = upRightIn;
}


	

Space* Space::getUp(){
	return up;
}

Space* Space::getDown(){
	return down;
}

Space* Space::getLeft(){
	return left;
}

Space* Space::getRight(){
	return right;
}

Space* Space::getUpLeft(){
	return upLeft;
}

Space* Space::getUpRight(){
	return upRight;
}



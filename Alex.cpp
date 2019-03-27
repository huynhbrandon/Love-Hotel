#include "Alex.hpp"
#include <iostream>
#include <algorithm>
#include "Player.hpp"
#include <string>

/********************************************
 * Alex(): constructor that sets space name to Alex
 * **********************************************/
Alex::Alex(){
	setName("Alex");
}

/*************************************************************
 * action(): space action that takes in the current space and the player and allows them to either pick up items in the room, interact with the inhabitant or move to another room.
 * **********************************************************/
void Alex::action(Space* current, Player &player){
	int choice = 0;
	if(visited == 0){ //first time visiting
		std::cout << "Alex: Greetings. Welcome to my humble abode. Oh that? That's just my wall of anime paraphernalia. I have prepared a 10-course meal for us. It took a little longer than usual because my kitchenware is a little worn out, but hey, dig in!" << std::endl;
		visited = 1;
	}else if(satisfaction == 2){ //kiss received
		std::cout << "Alex: Thank you for the manga and skillet!" << std::endl;
	
	}else{ //visiting multiple times
		
		std::cout << "Alex: Quit looking at my anime shrine and join me in these delicacies I whipped up for us!" << std::endl;
	}
	
	while(choice != 4){
		//menu
		std::cout << "\n1. Check the ball pit." << std::endl;
		std::cout << "2. Check the shoe rack." << std::endl;
		std::cout << "3. Interact with Alex." << std::endl;
		std::cout << "4. Go to another room." << std::endl;
		checkInt(choice, 1,4);


		if(choice == 1 && !player.bagFull()){
			if(basketball == 1){
				std::cout << "There is nothing here." << std::endl;
			}else{
				std::cout << "You acquired a basketball!" << std::endl;
				player.add(current->getItem1());
				basketball = 1;
			}
		}else if(choice == 2 && !player.bagFull()){
			if(boots == 1){
				std::cout << "There is nothing here." << std::endl;
			}else{
				std::cout << "You got a pair of hiking boots!" << std::endl;
				player.add(current->getItem2());
				boots = 1;
			}
		}else if(choice ==3){
			std::string hobby1 = getHobby1();
			std::string hobby2 = getHobby2();

			//if kiss received
			if(satisfaction == 2){
				std::cout << "Alex: I hope you enjoyed the food!" << std::endl;
			}else if(player.find(hobby1)){ //if bag contains the object

				//remove manga
				player.remove("Manga");

				std::cout << "Alex: I love manga! *GEEKS OUT*" << std::endl;
				
				satisfaction++;
				if(satisfaction == 2){
					player.gainKiss();
				}	

			}else if(player.find(hobby2)){
				//remove skillet
				player.remove("Cast iron skillet");
				std::cout << "Alex: How did you know I needed a new skillet?!" << std::endl;
				satisfaction++;
				if(satisfaction == 2){
					player.gainKiss();
				}
			}else{
				std::cout << "Alex: Food is getting cold! Also, have you ever heard of Pokemon?" << std::endl;
			}	
		}

	}
}

	

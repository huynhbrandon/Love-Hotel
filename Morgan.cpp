#include "Morgan.hpp"
#include <iostream>

/*************************************
 * Morgan(): constructor that sets space name to Morgan
 * ************************************/
Morgan::Morgan() : Space(){
	setName("Morgan");
}
	

/*************************************************************
 * action(): space action that takes in the current space and the player and allows them to either pick up items in the room, interact with the inhabitant or move to another room.
 * **********************************************************/
void Morgan::action(Space* current, Player &player){
	int choice = 0;
	if(visited == 0){ //first visit
		std::cout << "Morgan: Hi. Romeo and Juliet. Walking up hill. Beautiful." << std::endl;
		visited = 1;
	}else if(satisfaction == 2){ //kiss received
		std::cout << "Morgan: Good." << std::endl;
	}else{ //next visits
		std::cout << "Morgan: Romeo and Juliet. Walking up hill. What." << std::endl;
	}
	
	while(choice != 4){
		std::cout << "\n1. Check the kitchen." << std::endl;
		std::cout << "2. Check the garage." << std::endl;
		std::cout << "3. Interact with Morgan." << std::endl;
		std::cout << "4. Go to another room." << std::endl;
		checkInt(choice, 1,4);

		if(choice == 1 && !player.bagFull()){ //bag not full
			if(skillet == 1){
				std::cout << "There is nothing here." << std::endl;
			}else{
				std::cout << "You acquired a cast iron skillet!" << std::endl;
				player.add(current->getItem1());
				skillet = 1;
			}
		}else if(choice == 2 && !player.bagFull()){
			if(tent == 1){
				std::cout << "There is nothing here." << std::endl;
			}else{
				std::cout << "You acquired a tent!" << std::endl;
				player.add(current->getItem2());
				tent = 1;
			}
		}else if(choice ==3){
			std::string hobby1 = getHobby1();
			std::string hobby2 = getHobby2();

			//if kiss received
			if(satisfaction == 2){
				std::cout << "Morgan: I am hiking thespian." << std::endl;
			}else if(player.find(hobby1)){ //if bag contains the object

				//remove Shakespeare to give
				player.remove("Shakespeare");

				std::cout << "Morgan: Exquisite." << std::endl;
				
				satisfaction++;
				if(satisfaction == 2){
					std::cout << "Morgan: *...kiss...*" << std::endl;
					player.gainKiss();
				}	

			}else if(player.find(hobby2)){
				//remove boots to give
				player.remove("Hiking boots");
				std::cout << "Morgan: Traction. Excellent." << std::endl;
				satisfaction++;
				if(satisfaction == 2){
					std::cout << "Morgan: *...kiss...*" << std::endl;
					player.gainKiss();
				}
			}else{
				std::cout << "Morgan: Hi." << std::endl;
			}	
		}
	}
}

#include "Jess.hpp"
#include <iostream>

/***************************************
 * Jess(): constructor setting space name to Jess
 * **************************************/
Jess::Jess(){
	setName("Jess");
}

/*************************************************************
 * action(): space action that takes in the current space and the player and allows them to either pick up items in the room, interact with the inhabitant or move to another room.
 * **********************************************************/
void Jess::action(Space* current, Player &player){
	int choice = 0;
	if(visited == 0){ //first visit
		std::cout << "Jess: What's the haps?! You like basketball?! I DO!! You can't beat me!! Check out those mountains!! So pristine!!" << std::endl;
		visited = 1;
	}else if(satisfaction == 2){ //kiss received
		std::cout << "Jess: See you on the courts or in the mountains!" << std::endl;
	}else{ //multiple visits
		std::cout << "Jess: What's up, now!? Check out those mountains!! And those courts!!" << std::endl;
	}
	
	while(choice != 4){
		std::cout << "\n1. Check the bookshelf." << std::endl;
		std::cout << "2. Check the drawers." << std::endl;
		std::cout << "3. Interact with Jess." << std::endl;
		std::cout << "4. Go to another room." << std::endl;
		checkInt(choice, 1,4);

		if(choice == 1 && !player.bagFull()){ //if bag not full
			if(manga == 1){
				std::cout << "There is nothing here." << std::endl;
			}else{
				std::cout << "You acquired a manga!" << std::endl;
				player.add(current->getItem1());
				manga = 1;
			}
		}else if(choice == 2 && !player.bagFull()){
			if(camera == 1){
				std::cout << "There is nothing here." << std::endl;
			}else{
				std::cout << "You acquired a camera!" << std::endl;
				player.add(current->getItem2());
				camera = 1;
			}
		}else if(choice == 3){
			std::string hobby1 = getHobby1();
			std::string hobby2 = getHobby2();

			//if kiss received
			if(satisfaction == 2){
				std::cout << "Jess: Call me the mountain basketball man!!" << std::endl;
			}else if(player.find(hobby1)){ //if bag contains the object

				//remove basketball
				player.remove("Basketball");

				std::cout << "Jess: Sweet. Now I can ball you up!" << std::endl;
				
				satisfaction++;
				if(satisfaction == 2){
					std::cout << "Jess: Alright, come here and let me plant one on you!" << std::endl;
					player.gainKiss();
				}	

			}else if(player.find(hobby2)){
				//remove tent to give
				player.remove("Tent");
				std::cout << "Jess: The forests will now be mine." << std::endl;
				satisfaction++;
				if(satisfaction == 2){
					std::cout << "Jess: Alright, come here and let me plant one on you!" << std::endl;
					player.gainKiss();
				}
			}else{
				std::cout << "Jess: Don't bother me when I'm checking out mountains." << std::endl;
			}	
		}

	}
}


#include "Pat.hpp"
#include <iostream>
/*********************************
 * Pat(): constructor that sets space name to Pat
 * ********************************/
Pat::Pat() : Space() {
	setName("Pat");
}

/*************************************************************
 * action(): space action that takes in the current space and the player and allows them to either pick up items in the room, interact with the inhabitant or move to another room.
 * **********************************************************/
void Pat::action(Space* current, Player &player){
	int choice =0;

	//enter room
	if(visited == 0){ //first visit
		std::cout << "Pat: The name's Pat!!! I love posing for pictures (hehe) and tanning (hehe) ^__^V." << std::endl;
		visited = 1;
	}else if(satisfaction == 2){ // kiss received
		std::cout << "Pat: I missed you soooooooooooo much :(. Stop leaving me!!!" << std::endl;
	}else{ //multile visits
		std::cout << "Pat: Want to take some pictures of me? (hehe) Or watch me sunbathe? (hehe) ;)" << std::endl;
	}
	
	//choices
	while(choice != 4){
		std::cout << "\n1. Check the shoe rack." << std::endl;
		std::cout << "2. Check the couch." << std::endl;
		std::cout << "3. Interact with Pat." << std::endl;
		std::cout << "4. Go to another room." << std::endl;
		checkInt(choice, 1,4);

		if(choice == 1 && !player.bagFull()){
			if(shoes == 1){
				std::cout << "There is nothing here." << std::endl;
			}else{
				std::cout << "You acquired a pair of ballet shoes!" << std::endl;
				player.add(current->getItem1());
				shoes = 1;
			}
		}else if(choice == 2 && !player.bagFull()){
			if(bear == 1){
				std::cout << "There is nothing here." << std::endl;
			}else{
				std::cout << "You found a BEAR!" << std::endl;
				player.add(current->getItem2());
				bear = 1;
			}
		}else if(choice ==3){
			std::string hobby1 = getHobby1();
			std::string hobby2 = getHobby2();

			//if kiss received
			if(satisfaction == 2){
				std::cout << "Pat: Came back for another kiss? ;)" << std::endl;
			}else if(player.find(hobby1)){ //if bag contains the object

				//remove speedo
				player.remove("Speedo");

				std::cout << "Pat: I wish this could be more revealing :(, but thanks bb!! <3" << std::endl;
				
				satisfaction++;
				if(satisfaction == 2){
					std::cout << "Pat: PUCKER UP BABY!!!! (^ 3 ^)!!!!" << std::endl;
					player.gainKiss();
				}	

			}else if(player.find(hobby2)){
				//remove camera
				player.remove("Camera");
				std::cout << "Pat: How about you take some pictures of me with that? ;)" << std::endl;
				satisfaction++;
				if(satisfaction == 2){
					std::cout << "Pat: PUCKER UP BABY!!!! (^ 3 ^)!!!!" << std::endl;
					player.gainKiss();
				
				}
			}else{
				std::cout << "Pat: Hi cutie <333" << std::endl;
			}	
		}

	}

}

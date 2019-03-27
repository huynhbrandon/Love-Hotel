#include "Robin.hpp"
#include <iostream>

/******************************************
 * Robin(): constructor that sets space name to Robin
 * *****************************************/
Robin::Robin() : Space() {
	setName("Robin");
}

/*************************************************************
 * action(): space action that takes in the current space and the player and allows them to either pick up items in the room, interact with the inhabitant or move to another room.
 * **********************************************************/
void Robin::action(Space* current, Player &player){
	int choice = 0;

	//enter room
	if(visited == 0){ // first visit
		std::cout << "Robin: Call me Robin the twentieth. I liketh animalsth and danceth of the balleth." << std::endl;
		visited = 1;
	}else if(satisfaction == 2){ //kiss received 
		std::cout << "Robin: WELCOMETH BACKETH. WATCH ME TWIRL WITH YOGI!" << std::endl;
	}else{ // multiple visits
		std::cout << "Robin: Dost thou haveth a dogth? I enjoyth animals! And twirling on my toes-th!" << std::endl;
	}
	
	while(choice != 4){
		std::cout << "\n1. Check the stage." << std::endl;
		std::cout << "2. Check the underwear drawers." << std::endl;
		std::cout << "3. Interact with Robin." << std::endl;
		std::cout << "4. Go to another room." << std::endl;
		checkInt(choice, 1,4);

		if(choice == 1 && !player.bagFull()){
			if(shakespeare == 1){
				std::cout << "There is nothing here." << std::endl;
			}else{
				std::cout << "You found WILLIAM SHAKESPEARE!" << std::endl;
				player.add(current->getItem1());
				shakespeare = 1;
			}
		}else if(choice == 2 && !player.bagFull()){
			if(speedo == 1){
				std::cout << "There is nothing here." << std::endl;
			}else{
				std::cout << "You found a speedo!" << std::endl;
				player.add(current->getItem2());
				speedo = 1;
			}
		}else if(choice ==3){
			std::string hobby1 = getHobby1();
			std::string hobby2 = getHobby2();

			//if kiss received
			if(satisfaction == 2){
				std::cout << "Robin: Anon I can danceth with animals!" << std::endl;
			}else if(player.find(hobby1)){ //if bag contains the object

				//remove ballet shoes
				player.remove("Ballet shoes");

				std::cout << "Robin: Wow! I has't been dancing bareth foot this entire timeth!" << std::endl;
				
				satisfaction++;
				if(satisfaction == 2){
					std::cout << "Robin: *kisses in Shakespearean*" << std::endl;
					player.gainKiss();
				}	

			}else if(player.find(hobby2)){
				//remove skillet
				player.remove("Bear");
				std::cout << "Robin: Bears art most wondrous!" << std::endl;
				satisfaction++;
				if(satisfaction == 2){
					std::cout << "Robin: *kisses in Shakespearean*" << std::endl;
					player.gainKiss();
				}
			}else{
				std::cout << "Robin: How art thee?" << std::endl;
			}	
		}

	}

}

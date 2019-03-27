#include "lobby.hpp"
#include <iostream>

/**********************************
 * Lobby(): sets space to Lobby name
 * ********************************/
Lobby::Lobby(){
	setName("Lobby");
}

/*************************************
 * action(): lets player know when they're in the lobby
 * ************************************/
void Lobby::action(Space* space, Player &player){
	std::cout << "In Lobby..." << std::endl;
}

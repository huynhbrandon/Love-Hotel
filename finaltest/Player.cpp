#include "Player.hpp"
#include <algorithm>
#include <iterator>
#include <string>
#include <iostream>
int Player::getSize(){
	return bag.size();
}

/*********************************************
 * add() : adds the given argument item to the players bag if the bag is not full
 * ******************************************/
void Player::add(std::string item){
	if(!bagFull()){	
		bag.push_back(item);
	}else{
		std::cout << "Bag full! Give some gifts away!" << std::endl;
	}

}

/************************************************
 * remove() : removes the given argument item from the players bag when it is given to an inhabitant
 * source cited: https://stackoverflow.com/questions/39912/how-do-i-remove-an-item-from-a-stl-vector-with-a-certain-value
 * ************************************************/
void Player::remove(std::string item){
	bag.erase(std::remove(bag.begin(), bag.end(), item), bag.end());
}


int Player::getCapacity(){
	return bag.capacity();
}

/************************************************
 * find(): returns true if item is found in bag
 * source cited: https://stackoverflow.com/questions/571394/how-to-find-out-if-an-item-is-present-in-a-stdvector
 * ************************************************/
bool Player::find(std::string item){
	return (std::find(bag.begin(), bag.end(), item) != bag.end());
}

/**********************************************************
 * displayBag():  displays the content of the bag to the user
 * source cited: https://stackoverflow.com/questions/9751932/displaying-contents-of-a-vector-container-in-c
 * *************************************************************/
void Player::displayBag(){
	std::copy(bag.begin(), bag.end(), 
		std::ostream_iterator<std::string>(std::cout, ", "));
}

/***************************************************
 * gainKiss(): increments kiss amount of player
 * ************************************************/
void Player::gainKiss(){
	kisses++;
	std::cout << "You have received " << kisses << " kisses." << std::endl;
}

int Player::getKisses(){
	return kisses;
}

/*******************************************
 * bagFull(): returns a boolean if bag is full or not
 * ******************************************/
bool Player::bagFull(){
	if(bag.size() == max){
		std::cout << "Bag full! Give some gifts away!" << std::endl;
		return true;
	}else{
		return false;
	}
}		

#include "menu.hpp"
#include <iostream>
#include <vector>
using std::cout;
using std::endl;

/**************************
 * Menu(): Menu class constructor
 * **************************/
Menu::Menu(){
}

/********************************************************
 * display(): Displays menu options
 * ******************************************************/
void Menu::display(){
	for(int i = 0; i < options.size(); i++){
		cout << options[i] << endl;
	}
}

/*******************************************************
 * addOption(std::string): Add options to menu vector by passing a string
 * ****************************************************/
void Menu::addOption(std::string stringIn){
	options.push_back(stringIn);
}

/****************************************************
 * deleteOption(): Delete options
 * ***************************************************/
void Menu::deleteOption(){
}

/************************************************
 * clearVector(): clears vector
 * *********************************************/
void Menu::clearVector(){
	options.clear();
}
	

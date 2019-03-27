#include "inputVal.hpp"
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <stdexcept>
using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::getline;


/*******************************************************************
 * checkInt: Takes in a user input and checks whether or not it is an integer. Handles huge numbers and invalid arguments.
 * ****************************************************************/
void checkInt(int &input){
	string inputStr;
	bool error;
	int negativeCount = 0;
	//user input goes into declared var in main
	do {
		error = false;
		negativeCount = 0;
		cout << "Please enter an integer: " << endl;
		getline(cin, inputStr);
		
	
		// check each element of string to be digit
		for(int i = 0; i < inputStr.length(); i++){
			if(!isdigit(inputStr[i]) && inputStr[i] != '-'){
				//cout << "Bad input: " << inputStr[i] << endl;
				error = true;	
			} 
			if(inputStr[i] == '-'){
				negativeCount++;
				//cout << "negative count: " << negativeCount << endl;
				if(negativeCount > 1 || i !=0){
					error = true;
				}else{
					error = false;
				}
			}
			
		}

		
		if(error == false){
			try{
				//cout << "Changing to int: " << inputStr << endl;
				input = std::stoi(inputStr);
			}
			catch(std::out_of_range){
				cout << "TOO HIGH" << endl;
				error = true;
			}
			catch(std::invalid_argument){
				cout << "INVALID" << endl;
				error = true;
			}
		}	
	}while(error);
}


/*******************************************************************
 * checkInt: Overloaded input validation that checks whether or not the input is an integer that is within the given range. Handles huge and invalid arguments.
 * *****************************************************************/
void checkInt(int &input, int min, int max){
	string inputStr;
	bool error;
	//user input goes into declared var in main
	do {
		error = false;
		cout << "(Enter integer from " << min << " to " << max << "): " << endl;
		getline(cin, inputStr);
		
		if(inputStr.empty()){
			error = true;
		}
		// check each element of string to be digit
		for(int i = 0; i < inputStr.length(); i++){
			if(!isdigit(inputStr[i])){
				error = true;	
			}
		}
		
		//if it is an int, check boundaries
		if(error == false){	
			try{
				input = std::stoi(inputStr);
			}
			catch(std::out_of_range){
				cout << "TOO HIGH" << endl;
				error = true;
			}
			catch(std::invalid_argument){
				cout << "INVALID" << endl;
				error = true;
			}
			if(min > input || max < input){
				
				error = true;
			}
		}

	}while(error);
}

/*************************************************************
 * checkPosInt: Takes input and checks if it is a positive integer. Handles huge and invalid arguments.
 * ************************************************************/
void checkPosInt(int &input){
	string inputStr;
	bool error;

	//user input goes into declared var in main
	do {
		error = false;
		cout << "Please enter a positive integer: " << endl;
		getline(cin, inputStr);
		
		// check each element of string to be digit
		for(int i = 0; i < inputStr.length(); i++){
			if(!isdigit(inputStr[i])){
				error = true;	
			}
		}

		if(error ==false){
			// handle huge numbers and invalid arguments 
			try{
				input = std::stoi(inputStr);
			}
			catch(std::out_of_range){
				cout << "TOO HIGH" <<endl;
				error = true;
			}
			catch(std::invalid_argument){
				cout << "INVALID" << endl;
				error = true;
			}
			if(input <= 0){ //Check if greater than 0/+
				error = true;
			}
		}
		
	}while(error);
}


/**********************
 *checkDouble: validates whether user input is a double or not within a given range
 * *******************/
void checkDouble(double &input, double min, double max){
	string inputStr;
	bool error;

	int count = 0;
	//user input goes into declared var in main
	do {
		error = false;
		cout << "(Floating number from " << min << " to " << max << "): " << endl;
		getline(cin, inputStr);
		
		if(inputStr.empty()){
			error = true;
		}
		// check each element of string to be digit
		for(int i = 0; i < inputStr.length(); i++){
			if(!isdigit(inputStr[i])&& inputStr[i] != '.'){
				error = true;	
			}
			if(inputStr[i] == '.'){
				count++;
			}		
		}
		cout << count << endl;
		if(count != 1){	//if there isn't one period, error
			error = true;
			count = 0;
		}
		
		cout << "Error is " << error << endl;		

		//if it is an int, check boundaries
		if(error == false){	
			try{
				input = std::stod(inputStr);
			}
			catch(std::out_of_range){
				cout << "TOO HIGH" << endl;
				error = true;
			}
			catch(std::invalid_argument){
				cout << "INVALID" << endl;
				error = true;
			}
			if(min > input || max < input){
				
				error = true;
			}
		} 

	}while(error);
}






/************************************************************
 * checkChar: Takes character input and checks whether or not it is a char of the given options
 * *********************************************************/
void checkChar(char &input, string yes, string no){
	string inputStr;
	bool error;
	//user input goes into declared variable in main
	do{
		error = false;
		cout << "Please enter " << yes << " or " << no << endl;
		getline(cin, inputStr);

		if(cin.fail() || inputStr.length() > 1 || (inputStr != yes && inputStr != no)){
			error = true;
		} 
	}while(error);
	
	//change user input
	if(inputStr == "y"){
		input = 'y';
	}else{
		input = 'n';
	}
	
	
}

/****************************************************************
 * checkString: Takes input and checks whether or not it is a string
 * *************************************************************/
void checkString(string &input){
	string inputStr;
	bool error;

	do{
		error = false;
		getline(cin, inputStr);
		if(cin.fail()){
			error = true;
		}
		for(int i = 0; i < inputStr.length(); i++){
			if(isdigit(inputStr[i])){
				error = true;	
			}
		}
	}while(error);

	input = inputStr;
}

/****************************************************************
 * checkString: Takes input and checks whether or not it is a string, against given choses
 * *************************************************************/
void checkString(string &input, string choice1, string choice2){
	string inputStr;
	bool error;

	do{
		error = false;
		cout << choice1 << " or " << choice2 << "?" << endl;
		getline(cin, inputStr);
		if(cin.fail()|| (inputStr != choice1 && inputStr != choice2)){
			error = true;
		}
		for(int i = 0; i < inputStr.length(); i++){
			if(isdigit(inputStr[i])){
				error = true;	
			}
		}
	}while(error);

	input = inputStr;
}

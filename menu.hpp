#ifndef MENU_HPP
#define MENU_HPP

#include <vector>
#include <string>
class Menu
{
	private:
		std::vector<std::string> options;

	public:
		Menu(); //constructor
		
		void display();
		void addOption(std::string);
		void deleteOption();
		void clearVector();
};
#endif			

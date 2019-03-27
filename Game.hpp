#ifndef GAME_HPP
#define GAME_HPP

#include "Space.hpp"

class Game
{
	private:
		Space* main;
		Space* room1;
		Space* room2;
		Space* room3;
		Space* room4;
		Space* room5;

	
	public:
		Game();
		~Game();
		void setPeople();
		void run();
		void display();
		void display(Space*);
};

#endif

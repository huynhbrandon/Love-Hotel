#ifndef SPACE_HPP
#define SPACE_HPP

#include <string>
#include "Player.hpp"
#include "inputVal.hpp"

class Space
{
	protected:
	
		std::string item1; //items in each room
		std::string item2;

		std::string hobby1; //hobbies of each inhabitant as clues
		std::string hobby2;

		std::string name;


		Space* up;
		Space* down;
		Space* left;
		Space* right;
		Space* upRight;
		Space* upLeft;

		//keep track of whether or not the item has been picked up
		int visited = 0;
		int basketball = 0;
		int boots = 0;
		int manga = 0;
		int camera = 0;
		int skillet = 0;
		int tent = 0;
		int shoes = 0;
		int bear = 0;
		int shakespeare = 0;
		int speedo = 0;
		int satisfaction = 0;
	public:
		Space();
		virtual ~Space();
		virtual void action(Space*, Player &) = 0; //interests
	
		Space* menu(Space*);
	
		virtual std::string getItem1();
		virtual std::string getItem2();

		virtual void setItem1(std::string);
		virtual	void setItem2(std::string);

		virtual	void setName(std::string);
		virtual	std::string getName();

		virtual void setHobby1(std::string);
		virtual void setHobby2(std::string);

		virtual std::string getHobby1();
		virtual std::string getHobby2();	
		
		virtual void setUp(Space*);
		virtual void setDown(Space*);
		virtual void setLeft(Space*);
		virtual void setRight(Space*);
		virtual void setUpRight(Space*);
		virtual void setUpLeft(Space*);
		

		virtual Space* getUp();
		virtual Space* getDown();
		virtual Space* getLeft();
		virtual Space* getRight();
		virtual Space* getUpRight();
		virtual Space* getUpLeft();
		
};
#endif


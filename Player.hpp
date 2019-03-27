#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <vector>
#include <string>

class Player
{
	private:
		int life;
		int kisses = 0;
		int max = 6; //bag max		
		std::vector<std::string> bag;

	public:
		int getSize();

		void add(std::string);
		void remove(std::string);

		int getCapacity();

		bool find(std::string);

		void displayBag();
		void gainKiss();

		int getKisses();

		bool bagFull();
		
};

#endif

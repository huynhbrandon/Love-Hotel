#ifndef LOBBY_HPP
#define LOBBY_HPP

#include "Space.hpp"

class Lobby: public Space
{
	public:
		Lobby();
		virtual void action(Space*, Player &);
};

#endif

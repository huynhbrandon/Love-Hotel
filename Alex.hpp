#ifndef ALEX_HPP
#define ALEX_HPP

#include "Space.hpp"

class Alex : public Space
{
	public:
		Alex();
		virtual void action(Space*, Player &);
};

#endif

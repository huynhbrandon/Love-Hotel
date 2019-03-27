#ifndef ROBIN_HPP
#define ROBIN_HPP

#include "Space.hpp"

class Robin: public Space
{
	public:
		Robin();
		virtual void action(Space*, Player &);
};

#endif

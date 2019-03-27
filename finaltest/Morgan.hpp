#ifndef MORGAN_HPP
#define MORGAN_HPP

#include "Space.hpp"

class Morgan : public Space
{
	public:
		Morgan();
		virtual void action(Space*, Player &);
};

#endif

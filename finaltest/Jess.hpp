#ifndef JESS_HPP
#define JESS_HPP

#include "Space.hpp"

class Jess : public Space
{
	public:
		Jess();
		virtual void action(Space*, Player &);
};

#endif

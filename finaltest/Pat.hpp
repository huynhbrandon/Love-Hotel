#ifndef PAT_HPP
#define PAT_HPP

#include "Space.hpp"

class Pat: public Space
{
	public:
		Pat();
		virtual void action(Space*, Player &);
};

#endif

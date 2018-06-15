/** ** *** ** ** ** *** ** ** ** *** ** ** ** *** ** ** ** *** ** * ** *** ** *
 *Ken Hall	3/04/2018
 *
 *CS 162 400	Project 4
 *:::HARRY POTTER HEADER FILE:::
 ** ** *** ** ** ** *** ** ** ** *** ** ** ** *** ** ** ** *** ** ** ** *** **/

#ifndef HARRY_POTTER_HPP
#define HARRY_POTTER_HPP
#include "character.hpp"

class HarryPotter: public Character
{
	private:
		int extraLife;
	public:
		HarryPotter();
		virtual int attack();
		virtual void defend(int);
};
#endif


/** ** *** ** ** ** *** ** ** ** *** ** ** ** *** ** ** ** *** ** * ** *** ** *
 *Ken Hall	3/04/2018
 *
 *CS 162 400	Project 4
 *:::BLUE MEN HEADER FILE:::
 ** ** *** ** ** ** *** ** ** ** *** ** ** ** *** ** ** ** *** ** ** ** *** **/

#ifndef BLUE_MEN_HPP
#define BLUE_MEN_HPP
#include "character.hpp"

class BlueMen : public Character
{
	public:
		BlueMen();
		virtual int attack();
		virtual void defend(int);
};
#endif

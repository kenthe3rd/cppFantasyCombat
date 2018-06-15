/** ** *** ** ** ** *** ** ** ** *** ** ** ** *** ** ** ** *** ** * ** *** ** *
 *Ken Hall	3/04/2018
 *
 *CS 162 400	Project 4
 *:::BARBARIAN HEADER FILE:::
 ** ** *** ** ** ** *** ** ** ** *** ** ** ** *** ** ** ** *** ** ** ** *** **/

#ifndef BARBARIAN_HPP
#define BARBARIAN_HPP
#include "character.hpp"

class Barbarian : public Character
{
	public:
		Barbarian();
		virtual int attack();
		virtual void defend(int);
};
#endif

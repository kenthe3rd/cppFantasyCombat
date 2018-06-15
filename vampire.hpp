/** ** *** ** ** ** *** ** ** ** *** ** ** ** *** ** ** ** *** ** * ** *** ** *
 *Ken Hall	2/18/2018
 *
 *CS 162 400	Project 3
 *:::VAMPIRE HEADER FILE:::
 ** ** *** ** ** ** *** ** ** ** *** ** ** ** *** ** ** ** *** ** ** ** *** **/

#ifndef VAMPIRE_HPP
#define VAMPIRE_HPP
#include "character.hpp"

class Vampire : public Character
{
	private:

	public:
		Vampire();
		virtual int attack();
		virtual void defend(int);
};
#endif


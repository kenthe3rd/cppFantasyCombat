/** ** *** ** ** ** *** ** ** ** *** ** ** ** *** ** ** ** *** ** * ** *** ** *
 *Ken Hall	2/18/2018
 *
 *CS 162 400	Project 3
 *:::MEDUSA HEADER FILE:::
 ** ** *** ** ** ** *** ** ** ** *** ** ** ** *** ** ** ** *** ** ** ** *** **/

#ifndef MEDUSA_HPP
#define MEDUSA_HPP
#include "character.hpp"
class Medusa : public Character
{
	public:
		Medusa();
		virtual int attack();
		virtual void defend(int);	
};
#endif

/** ** *** ** ** ** *** ** ** ** *** ** ** ** *** ** ** ** *** ** * ** *** ** *
 *Ken Hall	3/04/2018
 *
 *CS 162 400	Project 4
 *:::CHARACTER HEADER FILE:::
 ** ** *** ** ** ** *** ** ** ** *** ** ** ** *** ** ** ** *** ** ** ** *** **/

#ifndef CHARACTER_HPP
#define CHARACTER_HPP

class Character
{
	protected:
		int attCap;
		int attQuant;
		int defCap;
		int defQuant;
		int armor;
		int strengthPoints;
		int maxStrengthPoints;
	public:
		virtual int attack() = 0;
		virtual void defend(int) = 0;
		int getSP();
		void recover();
};
#endif

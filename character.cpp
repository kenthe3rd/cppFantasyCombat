/** ** *** ** ** ** *** ** ** ** *** ** ** ** *** ** ** ** *** ** * ** *** ** *
 *Ken Hall	3/04/2018
 *
 *CS 162 400	Project 4
 *:::CHARACTER IMPLEMENTATION FILE:::
 ** ** *** ** ** ** *** ** ** ** *** ** ** ** *** ** ** ** *** ** ** ** *** **/

#include "character.hpp"
#include <iostream>
using std::cout;
using std::endl;
/******************************************************************************
 *GET_SP: returns the remaining strength points for a character
 *****************************************************************************/

int Character::getSP()
{
	return strengthPoints;
}



/******************************************************************************
 *RECOVER: restores 1/3 of SP or restores to max SP, whichever is less
 *****************************************************************************/

void Character::recover()
{
	int restoreVal = maxStrengthPoints/3;
	strengthPoints += restoreVal;
	if(strengthPoints > maxStrengthPoints)
	{
		strengthPoints = maxStrengthPoints;
	}
	cout<< endl << "SP now at " << strengthPoints << endl << endl;
}

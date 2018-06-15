/** ** *** ** ** ** *** ** ** ** *** ** ** ** *** ** ** ** *** ** * ** *** ** *
 *Ken Hall	2/18/2018
 *
 *CS 162 400	Project 3
 *:::VAMPIRE IMPLEMENTATION FILE:::
 ** ** *** ** ** ** *** ** ** ** *** ** ** ** *** ** ** ** *** ** ** ** *** **/

#include "vampire.hpp"
#include <cstdlib>
#include <time.h>
#include <iostream>
using std::cout;
using std::endl;

/******************************************************************************
 *CONSTRUCTOR
 *****************************************************************************/

Vampire::Vampire()
{
	srand(time(NULL));
	attCap = 12;
	attQuant = 1;
	defCap = 6;
	defQuant = 1;
	armor = 1;
	strengthPoints = 18;
	maxStrengthPoints = 18;
}



/******************************************************************************
 *ATTACK: deals damage
 *****************************************************************************/

int Vampire::attack()
{
	//roll one d12
	int roll = rand() % 12 + 1;

	//report results of attack roll
	cout << "Vampire attacks for " << roll << " damage." << endl;
	return roll; 
}



/******************************************************************************
 *DEFEND: reduces damage
 *****************************************************************************/

void Vampire::defend(int attackVal)
{
	//roll one d20 to check for Charm success
	int charmRoll = rand() % 20 + 1;
	if(charmRoll > 10)
	{
		cout << "Vampire charms their opponent, preventing "
		<< "all damage." << endl;
		return;
	}
	
	//Charm fails: rolling regular defense: 1d6
	int roll = rand() % 6 + 1;

	cout << "Vampire defends for " << roll << endl;
	if(attackVal < 100)
	{
		//check for successful damage and apply damage to SP
		if((attackVal - (roll + armor)) > 0)
		{
			strengthPoints -= (attackVal - (roll + armor));
		}
		//report results of defense
		cout << "Vampire suffers " << attackVal << "-" << roll
		<< "-" << armor << " points of damage and now has " 
		<< strengthPoints << " strength points left." << endl;
	}
	if(attackVal == 100)
	{
		strengthPoints = 0;
		cout << "Vampire suffered a critical hit." << endl;
	}

	if(strengthPoints <= 0)
	{
		cout << "Vampire dies." << endl;
	}
}

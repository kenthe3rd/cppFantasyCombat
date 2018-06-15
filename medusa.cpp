/** ** *** ** ** ** *** ** ** ** *** ** ** ** *** ** ** ** *** ** * ** *** ** *
 *Ken Hall	2/18/2018
 *
 *CS 162 400	Project 3
 *:::MEDUSA IMPLEMENTATION FILE:::
 ** ** *** ** ** ** *** ** ** ** *** ** ** ** *** ** ** ** *** ** ** ** *** **/

#include "medusa.hpp"
#include <cstdlib>
#include <time.h>
#include <iostream>
using std::cout;
using std::endl;

/******************************************************************************
 *CONSTRUCTOR
 *****************************************************************************/

Medusa::Medusa()
{
	srand(time(NULL));
	attCap = 6;
	attQuant = 2;
	defCap = 6;
	defQuant = 1;
	armor = 3;
	strengthPoints = 8;
	maxStrengthPoints = 8;
}



/******************************************************************************
 *ATTACK: deals damage
 *****************************************************************************/

int Medusa::attack()
{
	
	//roll two d6
	int roll1 = rand() % 6 + 1;
	int roll2 = rand() % 6 + 1;

	//report results of attack roll
	cout << "Medusa attacks for " << roll1 << " + " << roll2 
	<< " damage." << endl;

	//check for Glare crit
	if((roll1 + roll2) == 12)
	{
		cout << "Medusa uses Glare." << endl;
		return 100;
	}
	return (roll1 + roll2);
}



/******************************************************************************
 *DEFEND: reduces damage
 *****************************************************************************/

void Medusa::defend(int attackVal)
{
	//roll one d6
	int rollOne = rand() % 6 + 1;
	
	cout << "Medusa defends for " << rollOne << endl;
	if(attackVal < 100)
	{
		//check for successful damage and apply damage to SP
		if((attackVal - (rollOne + armor)) > 0)
		{
			strengthPoints -= (attackVal - (rollOne + armor));
		}

		//report results of defense	
		cout<< "Medusa suffers " << attackVal << "-" << rollOne
		<< "-" <<  armor << " points of damage and now has " 
		<< strengthPoints << " strength points left." << endl;
	}
	if(attackVal == 100)
	{
		strengthPoints = 0;
		cout << "Medusa suffered a critical hit." << endl;	
	}

	if(strengthPoints <= 0)
	{
		cout << "Medusa dies." << endl;
	}
}

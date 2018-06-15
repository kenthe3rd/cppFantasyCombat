/** ** *** ** ** ** *** ** ** ** *** ** ** ** *** ** ** ** *** ** * ** *** ** *
 *Ken Hall	3/04/2018
 *
 *CS 162 400	Project 4
 *:::BARBARIAN IMPLEMENTATION FILE:::
 ** ** *** ** ** ** *** ** ** ** *** ** ** ** *** ** ** ** *** ** ** ** *** **/

#include "barbarian.hpp"
#include <cstdlib>
#include <time.h>
#include <iostream>
using std::cout;
using std::endl;

/******************************************************************************
 *CONSTRUCTOR
 *****************************************************************************/

Barbarian::Barbarian()
{
	srand(time(NULL));
	attCap = 6;
	attQuant = 2;
	defCap = 6;
	defQuant = 2;
	armor = 0;
	strengthPoints = 12;
	maxStrengthPoints = 12;
}



/******************************************************************************
 *ATTACK: deals damage
 *****************************************************************************/

int Barbarian::attack()
{
	//roll two d6
	int roll1 = rand() % 6 + 1;
	int roll2 = rand() % 6 + 1;

	//report results of attack roll
	cout << "Barbarian attacks for " << roll1 << " + " << roll2 
	<< " damage." << endl;
	return (roll1 + roll2);
}



/******************************************************************************
 *DEFEND: reduces damage
 *****************************************************************************/

void Barbarian::defend(int attackVal)
{
	//roll two d6
	int roll = rand() % 6 + 1;
	int roll2 = rand() % 6 + 1;
	
	cout << "Barbarian defends for " << roll << " + " << roll2 << endl;
	if(attackVal < 100)
	{
		//check for successful damage and apply damage to SP
		if((attackVal - (roll + roll2 + armor)) > 0)
		{
			strengthPoints -= (attackVal - (roll + roll2 + armor));
		}
		//report results of defense
		cout<< "Barbarian suffers " 
		<< attackVal << "-" << roll << "-" << roll2 << "-" 
		<< armor << " damage and now has " << strengthPoints 
		<< " strength points left." << endl;
	}	
	if(attackVal == 100)
	{
		strengthPoints = 0;
		cout << "Barbarian suffered a critical hit." << endl;	
	}

	if(strengthPoints <= 0)
	{
		cout << "Barbarian dies." << endl;
	}
	
}




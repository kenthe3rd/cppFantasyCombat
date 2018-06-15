/** ** *** ** ** ** *** ** ** ** *** ** ** ** *** ** ** ** *** ** * ** *** ** *
 *Ken Hall	3/04/2018
 *
 *CS 162 400	Project 4
 *:::BLUE MEN IMPLEMENTATION FILE:::
 ** ** *** ** ** ** *** ** ** ** *** ** ** ** *** ** ** ** *** ** ** ** *** **/

#include "blueMen.hpp"
#include <cstdlib>
#include <time.h>
#include <iostream>
using std::cout;
using std::endl;

/******************************************************************************
 *CONSTRUCTOR
 *****************************************************************************/

BlueMen::BlueMen()
{
	srand(time(NULL));
	attCap = 10;
	attQuant = 2;
	defCap = 6;
	defQuant = 3;
	armor = 3;
	strengthPoints = 12;
	maxStrengthPoints = 12;
}



/******************************************************************************
 *ATTACK: deals damage
 *****************************************************************************/

int BlueMen::attack()
{
	//roll two d10
	int roll1 = rand() % 10 + 1;
	int roll2 = rand() % 10 + 1;

	//report results of attack roll
	cout << "Blue Men attack for " << roll1 << " + " << roll2 
	<< " damage." << endl;
	return (roll1 + roll2);
}



/******************************************************************************
 *DEFEND: reduces damage
 *****************************************************************************/

void BlueMen::defend(int attackVal)
{
	int roll1 = 0;
	int roll2 = 0;
	int roll3 = 0;
	int rolls = 0;				//rolls holds the sum

	//roll (3-(damage/4))d6 
	roll1 = rand() % 6 + 1;
	if(strengthPoints > 4)
	{
		roll2 = rand() % 6 + 1;
	}
	else
	{
		roll2 = 0;
	}
	if(strengthPoints > 8)
	{
		roll3 = rand() % 6 + 1;
	}
	else
	{
		roll3 = 0;
	}

	rolls = roll1+ roll2 + roll3;
	cout << "Blue Men defends for " << roll1 << " + " << roll2 
	<< " + " << roll3 << endl;
	if(attackVal < 100)
	{
		//check for successful damage and apply damage to SP
		if((attackVal - (rolls + armor)) > 0)
		{
			strengthPoints -= 
			(attackVal - (roll1 + roll2 + roll3 + armor));
		}
		//report results of defense
	
		cout << "Blue Men suffer " << attackVal << "-" << roll1 
		<< "-" << roll2 << "-" << roll3 << "-" << armor  
		<< " points of damage and now have " << strengthPoints 
		<< " strength points left." << endl;
	}
	if(attackVal == 100)
	{
		strengthPoints = 0;
		cout << "Blue Men suffer a critical hit." << endl;	
	}

	if(strengthPoints <= 0)
	{
		cout << "Blue Men die." << endl;
	}
	
}

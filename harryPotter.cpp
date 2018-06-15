/** ** *** ** ** ** *** ** ** ** *** ** ** ** *** ** ** ** *** ** * ** *** ** *
 *Ken Hall	3/04/2018
 *
 *CS 162 400	Project 4
 *:::HARRY POTTER IMPLEMENTATION FILE:::
 ** ** *** ** ** ** *** ** ** ** *** ** ** ** *** ** ** ** *** ** ** ** *** **/

#include "harryPotter.hpp"
#include <cstdlib>
#include <time.h>
#include <iostream>
using std::cout;
using std::endl;

/******************************************************************************
 *CONSTRUCTOR
 *****************************************************************************/

HarryPotter::HarryPotter()
{
	srand(time(NULL));
	attCap = 6;
	attQuant = 2;
	defCap = 6;
	defQuant = 2;
	armor = 0;
	strengthPoints = 10;
	maxStrengthPoints = 10;
	extraLife = 1;
}



/******************************************************************************
 *ATTACK: deals damage
 *****************************************************************************/

int HarryPotter::attack()
{
	//roll two d6
	int roll1 = rand() % 6 + 1;
	int roll2 = rand() % 6 + 1;

	//report results of attack roll
	cout << "Harry Potter attacks for " << roll1 << " + " << roll2 
	<< " damage." << endl;
	return (roll1 + roll2);
}



/******************************************************************************
 *DEFEND: reduces damage
 *****************************************************************************/

void HarryPotter::defend(int attackVal)
{
	//roll two d6
	int roll1 = rand() % 6 + 1;
	int roll2 = rand() % 6 + 1;
	
	cout << "Harry Potter defends for " << roll1 << " + " << roll2 << endl;
	if(attackVal < 100)
	{
		//check for successful damage and apply damage to SP
		if((attackVal - (roll1 + roll2 + armor)) > 0)
		{
			strengthPoints -= (attackVal - (roll1 + roll2 + armor));
		}

		//report results of defense	
		cout<< "Harry Potter suffers " << attackVal << "-" << roll1
		<< "-" << roll2 << "-" << armor 
		<< " points of damage and now has " << strengthPoints 
		<< " strength points left." << endl;
	}
	if(attackVal == 100)
	{
		strengthPoints = 0;
		cout << "Harry Potter suffered a critical hit." << endl;	
	}

	if(strengthPoints <= 0)
	{
		if(extraLife)
		{
			cout << "Harry Potter revives." << endl;
			strengthPoints = 20;
			maxStrengthPoints = 20;
			extraLife--;
			return;
		}
		else
		{
			cout << "Harry Potter dies (for real)." << endl;
		}
	}
}






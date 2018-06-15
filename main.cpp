/** ** *** ** ** ** *** ** ** ** *** ** ** ** *** ** ** ** *** ** * ** *** ** *
 *Ken Hall	3/04/2018
 *
 *CS 162 400	Project 4 
 *:::MAIN IMPLEMENTATION FILE:::
 ** ** *** ** ** ** *** ** ** ** *** ** ** ** *** ** ** ** *** ** ** ** *** **/

#include "queue.hpp"
#include "menu.hpp"
#include "inputValidation.hpp"
#include "barbarian.hpp"
#include "blueMen.hpp"
#include "character.hpp"
#include "harryPotter.hpp"
#include "medusa.hpp"
#include "vampire.hpp"
#include <string>
using std::string;
#include <iostream>
using std::cin;
using std::cout;
using std::endl;

int main()
{
	Queue* pileOfShame = nullptr;
	Queue* pOneLineup = nullptr;
	int pOneKills = 0;
	Queue* pTwoLineup = nullptr;
	int pTwoKills = 0;
	Character* fighter = nullptr;

	Character* p1 = nullptr;
	int p1Attack = -1;
	string p1Name = "";

	Character* p2 = nullptr;
	int p2Attack = -1;
	string p2Name = "";

	string fighterName = "";
	int roundNumber = 1;
	int fightNumber = 1;
	int userInput = -1;
	InputValidation inVal;

	int menuChoice = -1;
	Menu mainMenu("Play", "Exit");

	Menu fighterMenu(
	"Barbarian",
	"Blue Men",
	"Harry Potter",
	"Medusa",
	"Vampire");

	Menu viewLosers("Display fallen fighters", "Continue");

	while(menuChoice != 2)
	{
		mainMenu.displayMenu();	
		menuChoice = mainMenu.enforceValidInput();
		if(menuChoice == 1)
		{
			pileOfShame = new Queue;
			pOneLineup = new Queue;
			pTwoLineup = new Queue;
			//set number of fighters in each roster
			cout << "Please enter a number of fighters for "
			<< "each team to use." << endl;
			userInput = inVal.enforceInt(1, 10);

			//build playerOne's roster
			cout << "BEGIN PLAYER ONE ROSTER" << endl << endl;
			for(int i=0; i<userInput; i++)
			{
				cout << "Please enter a name for fighter "
				<< i + 1 << ": ";
				cin.ignore();
				getline(cin, fighterName);
				cout << "Please choose a fighter type."
				<< endl;
				fighterMenu.displayMenu();
				menuChoice = fighterMenu.enforceValidInput();
				if(menuChoice == 1)
				{
					fighter = new Barbarian;
				}
				if(menuChoice == 2)
				{
					fighter = new BlueMen;
				}
				if(menuChoice == 3)
				{
					fighter = new HarryPotter;
				}
				if(menuChoice == 4)
				{
					fighter = new Medusa;
				}
				if(menuChoice == 5)
				{
					fighter = new Vampire;
				}
				pOneLineup->addBack(fighter, fighterName);
			}
			
			//build playerTwo's roster
			cout << "BEGIN PLAYER TWO ROSTER" << endl << endl;
			for(int i=0; i<userInput; i++)
			{
				cout << "Please enter a name for fighter "
				<< i + 1 << ": ";
				cin.ignore();
				getline(cin, fighterName);
				cout << "Please choose a fighter type."
				<< endl;
				fighterMenu.displayMenu();
				menuChoice = fighterMenu.enforceValidInput();
				if(menuChoice == 1)
				{
					fighter = new Barbarian;
				}
				if(menuChoice == 2)
				{
					fighter = new BlueMen;
				}
				if(menuChoice == 3)
				{
					fighter = new HarryPotter;
				}
				if(menuChoice == 4)
				{
					fighter = new Medusa;
				}
				if(menuChoice == 5)
				{
					fighter = new Vampire;
				}
				pTwoLineup->addBack(fighter, fighterName);
			}
			
			//make the roster's fight
			while(!pOneLineup->isEmpty() && !pTwoLineup->isEmpty())
			{
				

				//make the front character's fight
				//until one of them dies
				p1 = pOneLineup->getFront();
				p2 = pTwoLineup->getFront();
				p1Name = pOneLineup->getFrontName();
				p2Name = pTwoLineup->getFrontName();

				//announce the fight				
				cout << endl << endl << "Fight Number " 
				<< fightNumber << ": " << p1Name << " vs. "
				<< p2Name << endl << endl;

				while(p1->getSP() > 0 &&  p2->getSP() > 0)
				{
					cout << "Round Number: " << roundNumber
					<< endl;
					cout << p1Name << ": ";
					p1Attack = p1->attack();
					cout << endl;

					cout << p2Name << ": ";
					p2Attack = p2->attack();
					cout << endl;

					cout << p1Name << ": ";
					p1->defend(p2Attack);
					cout << endl;

					cout << p2Name << ": ";
					p2->defend(p1Attack);
					cout << endl << endl << endl;

					roundNumber++;
				}
				//reset round number
				roundNumber = 1;

				//move dead characters to the pile of shame
				if(p1->getSP() < 1)
				{
					cout << p1Name << " was defeated."
					<< endl;

					pileOfShame->addBack(
					pOneLineup->getFront(),
					pOneLineup->getFrontName());
					pOneLineup->removeFront();
				}
				else
				{
					cout << endl << p1Name << " won!" 
					<< endl;
					p1->recover();
					pOneLineup->addBack(p1, p1Name);
					pOneLineup->removeFront();
					pOneKills++;
					
				}
				if(p2->getSP() < 1)
				{
					cout << p2Name << " was defeated."
					<< endl;

					pileOfShame->addBack(
					pTwoLineup->getFront(),
					pTwoLineup->getFrontName());
					pTwoLineup->removeFront();
				}
				else
				{
					cout << endl<< p2Name << " won!" 
					<< endl;
					p2->recover();
					pTwoLineup->addBack(p2, p2Name);
					pTwoLineup->removeFront();
					pTwoKills++;
				}
				fightNumber++;
			}
			cout << "Player One Team Score: " << pOneKills << endl
			<< "Player Two Team Score: " << pTwoKills << endl;
			if(pOneLineup->isEmpty() && pTwoLineup->isEmpty())
			{
				cout << "It's a tie!" << endl;
			}
			else if(pOneLineup->isEmpty())
			{
				cout << "Player Two Team wins!" << endl;
			}
			else if(pTwoLineup->isEmpty())
			{
				cout << "Player One Team Wins!" << endl;
			}
			cout << endl;
			viewLosers.displayMenu();
			menuChoice = viewLosers.enforceValidInput();
			if(menuChoice == 1)
			{
				pileOfShame->printQueue();
			}
			
			//reset roster and gameplay data
			delete pileOfShame;
			delete pOneLineup;
			delete pTwoLineup;
			pOneKills = 0;
			pTwoKills = 0;
			//reset menuChoice to avoid early exit
			menuChoice = 1; 		
		}
	}

	return 0;
}

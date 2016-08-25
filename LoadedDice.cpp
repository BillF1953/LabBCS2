/*********************************************************************
** Program Filename: Loaded Dice CPP File
** Author: Tyler Forrester
** Date: 6/27/2016
** Description: A file that loads a dice. 
** Input: A normal dice (is derived from "Dice" Class)
** Output: A random loaded dice roll
** Citations: Object Oriented Programming Using C++ Fourth Edition Joyce Farrell Appendix E
********************************************************************/



#include "LoadedDice.h"
/*********************************************************************
** Function: Constructor LoadedDice
** Description: For creating 6 sided die
** Parameters:
** Pre-Conditions: main
** Post-Conditions: main
** Citation:
*********************************************************************/

LoadedDice::LoadedDice()
{
}
/*********************************************************************
** Function: Constructor LoadedDice: Dice
** Description: Gives access to dice constructor with new number of divisors. 
** Parameters: int div
** Pre-Conditions: Created multiside die
** Post-Conditions: set::divisor dice constructor
** Citation: 
*********************************************************************/

LoadedDice::LoadedDice(int div) : Dice(div)
{
	// allow access to Dice constructor to change dice size
}

/*********************************************************************
** Function: roll()
** Description: overrides dice roll with a loaded roll which takes every number except the biggest
** and gives a 5% chance of adding 1 to the roll.
** Parameters: 
** Pre-Conditions: Dice::getDivisor() and Dice::roll()
** Post-Conditions: main arrRoll, arrLRoll, arrSingleRoll, arrLSingleRoll
** Citation: Object Oriented Programming Using C++ Fourth Edition Joyce Farrell Appendix E
*********************************************************************/

int LoadedDice::roll()
{
	int result = 0; 
	
	const int LOADDIV = 20;
	
	result = Dice::roll();

	if (result != Dice::getDivisor()) {

		if (rand() % LOADDIV == 0) {

			result = result + 1; 

		}


	}

  
	return result;
}

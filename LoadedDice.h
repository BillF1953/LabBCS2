/*********************************************************************
** Program Filename: Loaded Dice Header File
** Author: Tyler Forrester
** Date: 6/27/2016
** Description: A file that loads a dice.
** Input: A normal dice (is derived from "Dice" Class)
** Output: A random loaded dice roll
** Citations: Object Oriented Programming Using C++ Fourth Edition Joyce Farrell
********************************************************************/


#ifndef LOADEDDICE_H
#define LOADEDDICE_H
#include "Dice.h"
class LoadedDice : public Dice {


public:
	LoadedDice();
	LoadedDice(int div);
	int roll();
	
};
#endif
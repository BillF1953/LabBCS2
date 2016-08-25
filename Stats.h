/*********************************************************************
** Program Filename: Stats Header File
** Author: Tyler Forrester
** Date: 6/27/2016
** Description: A program that performs statistical tests on random dice rolls and loaded dice rolls.
** Input: Arrays of Dice and Loaded Dice Rolls
** Output: Avg, Sum, Standard Deviation and an array of modes
** Citations: CS161 Assignment 6 Find Mode and CS162 LabAa. 
********************************************************************/


#ifndef STATS_HPP
#define STATS_HPP
#include <cmath>
#include <algorithm>
#include <iostream>
using std::count; 
class Stats {
private: int * modes; 
		 int arrayEnd;
		 void deleteItem(int);
		 double sum(int[], int);
		 void dynBubbleSort();
public:
		Stats(int);
		double avg(int[], int);
		double stanDev(int[], int);
		double median(int[], int);
		void mode(int[], int);		
		void bubbleSort(int[], int);
		
};
#endif
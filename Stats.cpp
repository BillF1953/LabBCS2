/***************** ****************************************************
** Program Filename: Stats CPP File
** Author: Tyler Forrester
** Date: 6/27/2016
** Description: A program that performs statistical tests on random dice rolls and loaded dice rolls.
** Input: Arrays of Dice and Loaded Dice Rolls
** Output: Avg, Sum, Standard Deviation and an array of modes
** Citations: CS161 Assignment 6 Find Mode and CS162 LabAa.
********************************************************************/


#include "Stats.h"




/*********************************************************************
** Function: Constructor Stats
** Description: sets array to max size, set array end to 0
** Parameters: size
** Pre-Conditions: main
** Post-Conditions: main
** Citation:
*********************************************************************/

Stats::Stats(int size)
{
	modes = new int[size];
	arrayEnd = 0;
}

/*********************************************************************
** Function: avg
** Description: averaging an array of ints
** Parameters:  int array[], size
** Pre-Conditions: sum() 
** Post-Conditions: stanDev()
** Citation: CS 162 Lab Aa 
*********************************************************************/


double Stats::avg( int array [], int size)
{
		
		double average = 0;
		average = sum(array, size) / size;

	
		return average;
	
}

/*********************************************************************
** Function: standDev
** Description: standard deviation of an array
** Parameters: int nums[], int size
** Pre-Conditions: sum() avg()
** Post-Conditions: 
** Citation: CS 162 Lab B 
*********************************************************************/

double Stats::stanDev(int nums[], int size)
{
	double mean = avg(nums, size); 
	double sumDist = 0.0;
	double standDev = 0.0;
	for (int i = 0; i < size; i++) {

		
		sumDist = sumDist + std::pow((nums[i] - mean), 2);



	}

	standDev = sqrt(sumDist / size);

	return standDev;
	
}
/*********************************************************************
** Function: mode
** Description: finds the modes of an array
** Parameters: int array[], int size
** Pre-Conditions: 
** Post-Conditions:
** Citation: CS 161 Week 6 Project "findMode" 5/4/2016
*********************************************************************/

void Stats::mode(int array[], int size)
{

	
	int arrayEnd = 0; 
	int mode1 = 0;
	for (int i = 0; i < size; i++)
	{
		int counts = count(array, array + size, array[i]);

		if (counts > mode1) {

			mode1 = counts;  //finds mode

		}

	}

	for (int k = 0; k < size; k++) {

		int counts = count(array, array + size, array[k]); //counts the number of occurence

		if (mode1 == counts) {
			modes[arrayEnd] = array[k]; //adds to dynamic array
			arrayEnd++;
		}
	}

	for (int j = 0; j < arrayEnd; j++) {
		for (int m = 0; m < arrayEnd; m++) {
			int flag = 1; 
			while (flag && j!=m) {
				if (modes[j] == modes[m]) {
					for (int i = 0; i < (arrayEnd - m); i++) {
						modes[m + i] = modes[m + i + 1];  //delete duplicates

					}
					arrayEnd--;
				}
				
				else {	
					flag = 0; 
				}

			}
		
		}
			
	}
	 
	
	dynBubbleSort(); //sorts of array

	std::cout << "Mode(s): ";
	for (int n = 0; n < arrayEnd; n++) {

		std::cout << modes[n] << " ";  //prints modes

	}

	std::cout << std::endl; 
	delete [] modes; 
}
/*********************************************************************
** Function: median
** Description: sorts array in ascending order then finds the median of an array
** Parameters: int array[], int size
** Pre-Conditions:
** Post-Conditions:
** Citation: CS 161 Week 6 Project "findMode" 5/4/2016
*********************************************************************/
double Stats::median(int array[], int size)
{
	bubbleSort(array, size);
	
	if (size % 2 == 0) {
		double med = array[size / 2 - 1] + array[(size / 2)];
		return( med / 2);
	 
	
	}
	else {
 
		return(array[size / 2]);


	}

	


}

/*********************************************************************
** Function:  Sorting Algorithm for modes array. 
** Description: BubbleSort
** Parameters: position
** Pre-Conditions: mode()
** Post-Conditions: mode()
** Citation: "Bubble Sort" http://mathbits.com/MathBits/CompSci/Arrays/Bubble.htm 
** Accessed "10:52 AM July 2, 2016"
*********************************************************************/
void Stats::dynBubbleSort()
{
	int i, j, flag = 1;    // set flag to 1 to start first pass
	int temp;             // holding variable

	for (i = 0; (i < arrayEnd) && flag; i++)
	{
		flag = 0;
		for (j = 0; j < (arrayEnd - 1); j++)
		{
			if (modes[j + 1] > modes[j])      // ascending order simply changes to <
			{
				temp = modes[j];             // swap elements
				modes[j] = modes[j + 1];
				modes[j + 1] = temp;
				flag = 1;               // indicates that a swap occurred.
			}
		}
	}

}


/*********************************************************************
** Function: deleteItem
** Description: deletes Array element
** Parameters: position
** Pre-Conditions: mode()
** Post-Conditions: mode()
** Citation: Assignment1
*********************************************************************/

 void Stats::deleteItem(int position)
{

	if (position < arrayEnd && position > -1) {

		for (int i = 0; i < (arrayEnd - position); i++) {

			modes[position + i] = modes[position + i + 1];

		}

		arrayEnd--;
	
	}
	
}
 /*********************************************************************
 ** Function:  Sorting Algorithm for static array
 ** Description: BubbleSort
 ** Parameters: position
 ** Pre-Conditions: median()
 ** Post-Conditions: median()
 ** Citation: "Bubble Sort" http://mathbits.com/MathBits/CompSci/Arrays/Bubble.htm
 ** Accessed "10:52 AM July 2, 2016"
 *********************************************************************/

 void Stats::bubbleSort(int array[], int size)
 {
	 int i, j, flag = 1;    // set flag to 1 to start first pass
	 int temp;             // holding variable

	 for (i = 0; (i < size) && flag; i++)
	 {
		 flag = 0;
		 for (j = 0; j < (size - 1); j++)
		 {
			 if (array[j + 1] < array[j])      // ascending order simply changes to <
			 {
				 temp = array[j];             // swap elements
				 array[j] = array[j + 1];
				 array[j + 1] = temp;
				 flag = 1;               // indicates that a swap occurred.
			 }
		 }
	 }


 }

/*********************************************************************
** Function: sum
** Description: sums an array
** Parameters: const int nums[], int size
** Pre-Conditions: 
** Post-Conditions: Avg(), StandDev()
** Citation: CS 162 Lab Aa
*********************************************************************/
 
double Stats::sum(int nums[], int size)
{
	double sum = 0.0;
	for (int i = 0; i < size; i++) {
		sum += nums[i];
	}

	return sum;

}






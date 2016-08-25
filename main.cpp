
/*********************************************************************
** Program Filename: main Lab B
** Author: Tyler Forrester
** Date: 6/27/2016
** Description: A program that tests random dice rolls and loaded dice rolls. 
** Input: Dice/Stats/Loaded Dice Classes
** Output: CSV file with Statisticcs
** Citations: 
********************************************************************/
#include "LoadedDice.h"
#include "Stats.h"
#include<fstream>
int main() {
	
	void analysis(Stats, int[], int);
	void rollDie(LoadedDice); 
	void arrRolls(int retArr[], int size, Dice dice1, Dice dice2);
	void arrLRolls(int retArr[], int size, Dice dice1, Dice dice2);
	void arrSingleRolls(int retArr[], int size, Dice dice1);
	void arrLSingleRolls(int retArr[], int size, Dice dice1);
	
	LoadedDice dice1 = LoadedDice();
	LoadedDice dice2 = LoadedDice();
	LoadedDice dice4 = LoadedDice(4);
	LoadedDice dice5 = LoadedDice(4);
	dice1.seed();
	dice2.seed();
	dice4.seed();
	dice5.seed();
	const int size1000 = 1000;
	int array1000[size1000];
	const int size10 = 10;
	int array10[size10];
	const int size100 = 100;
	int array100[size100];
	
	/*********************************************************************
	** section: test sections to make sure analyse functions are working correctly
	** Description: analyses known array 
	** Parameters:
	** Pre-Conditions:
	** Post-Conditions: analyse() arrSingleRolls()
	** Citation:
	*********************************************************************/

	
	const int SIZE = 5;
	int testArr[SIZE] = { 2 , 5 , 8, 3, 5};
	const int SIZE1 = 6;
	int testArr1[SIZE1] = { 2 , 5 , 8, 3, 5, 3};
	Stats stat = Stats(SIZE);
	std::cout << "Please compare to test case document\n";
	std::cout << "Testing Bubble Sort" << " ";
	stat.bubbleSort(testArr, SIZE);
	for (int i = 0; i < SIZE; i++) {

		std::cout << testArr[i] << " ";

	}
	std::cout << std::endl;

	analysis(stat, testArr, SIZE);
	
	std::cout << "Analyses of even Array\n";
	Stats stat1 = Stats(SIZE1);
	analysis(stat1, testArr1, SIZE1);

	std::cout << "Rolling Each Die\n";

	std::cout << "Rolling Dice 1\n";
	rollDie(dice1);
	std::cout << "Rolling Dice 2\n";
	rollDie(dice2);
	std::cout << "Rolling 4-sided Dice 4\n";
	rollDie(dice4);
	std::cout << "Rolling 4-sided Dice 5\n";
	rollDie(dice5);


	std::cout << "End of Stats Test\n";

	/*********************************************************************
	** section: Two 6-sided Loaded and Unloaded added together 1 roll , 10 rolls, 100 rolls
	** Description: Rolls two 6-sided die Loaded and Unloaded 1, 10 and 100 times adds the results together
	** then analyses the results
	** Parameters:
	** Pre-Conditions:
	** Post-Conditions: analyse() arrRolls(), arrLRolls()
	** Citation:
	*********************************************************************/


	std::cout << "Sum of Two Die Rolls: " << dice1.Dice::roll() + dice2.Dice::roll() << std::endl;

	std::cout << "Analysis of the sum of 10 Rolls of Two 6-sided Die\n\n";
	
	arrRolls(array10, size10, dice1, dice2);

	std::cout << "Analysis of the sum of 10 Rolls of Two Loaded 6-sided Dice\n\n";

	arrLRolls(array10, size10, dice1, dice2);

	std::cout << "Analysis of the sum of 1000 Rolls of Two 6-sided Die\n\n";
	
	arrRolls(array1000, size1000, dice1, dice2);

	std::cout << "Analysis of the sum of 1000 Rolls of Two Loaded  6-sided Die\n\n";

	arrLRolls(array1000, size1000, dice1, dice2);

	/*********************************************************************
	** section: Two 4-sided Loaded and Unloaded added together 1 roll , 10 rolls, 100 rolls
	** Description: Rolls two 4-sided die Loaded and Unloaded 1, 10 and 100 times adds the results together
	** then analyses the results
	** Parameters: 
	** Pre-Conditions:
	** Post-Conditions: analyse() arrRolls() arrLRolls()
	** Citation:
	*********************************************************************/
	
	
	std::cout << "Sum of Two 4-sided Die Rolls: " << dice4.Dice::roll() + dice5.Dice::roll() << std::endl;

	std::cout << "Analysis of the sum of 10 Rolls of Two 4-sided Die\n\n";

	arrRolls(array10, size10, dice4, dice5);

	std::cout << "Analysis of the sum of 10 Rolls of Two Loaded 4-sided Dice\n\n";
	
	arrLRolls(array10, size10, dice4, dice5);
	
	std::cout << "Analysis of the sum of 1000 Rolls of Two 4-sided Die\n\n";

	arrRolls(array1000, size1000, dice4, dice5);

	std::cout << "Analysis of the sum of 1000 Rolls of Two Loaded  4-sided Die\n\n";

	arrLRolls(array1000, size1000, dice4, dice5);

		
	/*********************************************************************
	** section: 6-sided die individual roll
	** Description: Rolls each single 6-sided die 100 times then analyzes those rolls
	** Parameters: 
	** Pre-Conditions:
	** Post-Conditions: analyse() arrSingleRolls()
	** Citation:
	*********************************************************************/

	std::cout << "Analysis of the sum of 100 Rolls of 6-sided Dice Object 1\n\n";

	arrSingleRolls(array100, size100, dice1);

	std::cout << "Analysis of the sum of 100 Rolls of a Loaded 6-sided Dice Object 2\n\n";
	
	arrLSingleRolls(array100, size100, dice2);

	/*********************************************************************
	** section: 4-sided die individual roll
	** Description: Rolls each single  4-sided die 100 times then analyzes those rolls
	** Parameters:
	** Pre-Conditions:
	** Post-Conditions: analyse() arrSingleRolls()
	** Citation:
	*********************************************************************/
		

	std::cout << "Analysis of the sum of 100 Rolls of 4-sided Dice Object 1\n\n";

	arrSingleRolls(array100, size100, dice4);

	std::cout << "Analysis of the sum of 100 Rolls 4-sided of Dice Object 2\n\n";

	arrSingleRolls(array100, size100, dice5);
	
	/*********************************************************************
	** section: 6-sided loaded die individual roll 
	** Description: Rolls each single loaded 6-sided die 100 times then analyzes those rolls
	** Parameters: 
	** Pre-Conditions: 
	** Post-Conditions: analyse() arrLSingleRolls()
	** Citation: 
	*********************************************************************/
		
	std::cout << "Analysis of the sum of 100 Rolls of a 6-sided Loaded Dice Object 1\n\n";

	arrLSingleRolls(array100, size100, dice1);

	std::cout << "Analysis of the sum of 100 Rolls of a 6-sided Loaded Dice Object 2\n\n";

	arrLSingleRolls(array100, size100, dice2);
	
	/*********************************************************************
	** section: 4-sided loaded die individual roll 
	** Description: Rolls each single loaded 4-sided die 100 times then analyzes those rolls
	** Parameters:
	** Pre-Conditions:
	** Post-Conditions: analyse() arrLSingleRolls()
	** Citation:
	*********************************************************************/

	
	std::cout << "Analysis of the sum of 100 Rolls of Loaded 4-sided Dice Object 1\n\n";

	arrLSingleRolls(array100, size100, dice4);

	std::cout << "Analysis of the sum of 100 Rolls of Loaded 4-sided Dice Object 2\n\n";

	arrLSingleRolls(array100, size100, dice5);


}
/*********************************************************************
** Function: arrRolls
** Description: Rolls two dies adds the results together an loads to an array
** Parameters: int retArr[], int size, Dice dice1, Dice dice2
** Pre-Conditions: main 
** Post-Conditions: main
** Citation:
*********************************************************************/



void arrRolls(int retArr[], int size, Dice dice1, Dice dice2) {
	void analysis(Stats, int[], int);
	Stats stat = Stats(size); 
	
	
	for (int i = 0; i < size; i++)
	{

		int roll = dice1.Dice::roll();
		int roll1 = dice2.Dice::roll();
		retArr[i] = roll + roll1;
	}

	analysis(stat, retArr, size); 
}
/*********************************************************************
** Function: arrLRolls
** Description: Rolls two loaded dies adds the results together an loads to an array
** Parameters: int retArr[], int size, Dice dice1, Dice dice2
** Pre-Conditions: main
** Post-Conditions: main
** Citation
*********************************************************************/

void arrLRolls(int retArr[], int size, Dice dice1, Dice dice2) {
	void analysis(Stats, int[], int);
	Stats stat = Stats(size);
	
	for (int i = 0; i < size; i++)
	{

		int roll = dice1.roll();
		int roll1 = dice2.roll();
		retArr[i] = roll + roll1;
	}

	analysis(stat, retArr, size);
}
/*********************************************************************
** Function: arrSingleRolls
** Description: Rolls  a dices stores in to an array analyzes
** Parameters: int retArr[], int size, Dice dice1
** Pre-Conditions: main
** Post-Conditions: main
** Citation
*********************************************************************/


void arrSingleRolls(int retArr[], int size, Dice dice1) {
	void analysis(Stats, int[], int);
	Stats stat = Stats(size);

	for (int i = 0; i < size; i++)
	{

		int roll = dice1.Dice::roll();
		retArr[i] = roll;
	}

	analysis(stat, retArr, size);
}
/*********************************************************************
** Function: arrLSingleRolls
** Description: Rolls  a loaded dices stores in an array analyzes
** Parameters: int retArr[], int size, Dice dice1
** Pre-Conditions: main
** Post-Conditions: main
** Citation
*********************************************************************/

void arrLSingleRolls(int retArr[], int size, Dice dice1) {
	void analysis(Stats, int[], int);
	Stats stat = Stats(size);

	for (int i = 0; i < size; i++)
	{

		int roll = dice1.roll();
		retArr[i] = roll;
	}

	analysis(stat, retArr, size);
}

/*********************************************************************
** Function: rollDie
** Description:rolls a single die and prints out results
** Parameters: die
** Pre-Conditions: main
** Post-Conditions: main
** Citation
*********************************************************************/

void rollDie(LoadedDice die) {
	
	for (int i = 0; i < 10; i++) {

		std::cout << die.Dice::roll() << " ";

	}

	std::cout << std::endl; 

}

/*********************************************************************
** Function: analysis
** Description: calls Stats Outputs Descriptive Statistics
** Parameters: STats stat,int array, int size 
** Pre-Conditions: arrRoll, arrLRoll, arrSingleRoll, arrLSingleRoll
** Post-Conditions: main
** Citation
*********************************************************************/

void analysis(Stats stat, int array[], int SIZE) {

	std::cout << "Average: " << stat.avg(array, SIZE) << std::endl;

	std::cout << "Standard Deviation: " << stat.stanDev(array, SIZE) << std::endl;

	std::cout << "Median: " << stat.median(array, SIZE) << std::endl;

	stat.mode(array, SIZE);

	std::cout << std::endl;



}
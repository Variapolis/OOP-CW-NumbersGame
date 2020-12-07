// OOP CW1 Numbers Game.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <ctime>
#include <iostream>
#include <sstream>
#include <vector>

#include "NumberList.h"


bool operationInput(NumberList& numlist)
{
    std::vector<std::string> inputVec;
    std::string input, tempStr;
    std::cout << "Select 2 numbers you want to use from the list and type the operation you wish to use..." << std::endl;
    std::cin >> input;
    std::istringstream inputSplit(input);
	// ADD FUNCTION SPLIT STRING, REMOVE SPACES AND COMMAS ----------------------------------------------------------
	// SET OPERATION VARIABLE ---------------------------------------------------------------------------------------
	// ADD FUNCTION CONVERT TO CHAR ---------------------------------------------------------------------------------

	// FIX THIS -----------------------------------------------------------------------------------------------------
if (operation == '+' || operation == '-' || operation == '*' || operation == '/' || operation == 's')
    {
        std::cin >> nums2;
            switch (operation)
            {
            case '+':
                numlist.add(nums1, nums2);
                break;
            case '-':
                numlist.subtract(nums1, nums2);
                break;
            case '*':
                numlist.multiply(nums1, nums2);
                break;
            case '/':
                numlist.divide(nums1, nums2);
                break;
            case 's':
                numlist.split(nums1);
				break;
			case 'q':
				break;
				// ADD QUIT FUNCTIONALITY ------------------------------------------------------------------------------------------------
            }
    }
}



void gameLoop(NumberList &numberList)
{
	while (true)
	{
		numberList.print();
		operationInput(numberList);
        if (numberList.targetFound())
        {
            std::cout << "You win! Press enter to play again..." << std::endl;
            std::cin.ignore();
	        break;
        }
	}
}

void gameStart()
{
    NumberList* numberList = new NumberList();
    gameLoop(*numberList);
}

int main()
{
	srand(time(NULL));
    while (true)
    {
        gameStart();
    }
}


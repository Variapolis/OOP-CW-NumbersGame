// OOP CW1 Numbers Game.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <ctime>
#include <iostream>
#include "NumberList.h"


void operationInput(NumberList& numlist)
{
    int nums1;
    int nums2;
    char operation;
    std::cout << "Select 2 numbers you want to use from the list and type the operation you wish to use..." << std::endl;
    std::cin >> operation;
    std::cin >> nums1;
    if (operation == '+' || operation == '-' || operation == '*' || operation == '/')
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
            }
    }
    else if (operation == 's')
    {
        numlist.split(nums1);
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


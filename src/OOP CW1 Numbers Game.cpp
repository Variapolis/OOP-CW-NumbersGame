// OOP CW1 Numbers Game.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <ctime>
#include <iostream>
#include <sstream>
#include <vector>

#include "NumberList.h"

std::vector<std::string> splitString(std::string input)
{
    input += " ";
	std::string tempString = "";
    std::vector<std::string>tempVector;
	for (auto i : input)
	{
		if(i == ' ')
		{
            tempVector.push_back(tempString);
            tempString = "";
		}
        else
        {
            tempString += i;
        }
	}
    return tempVector;
}

char findOperation(std::string word)
{
	if(word == "+" || word == "Add" || word == "add")
	{
        return '+';
	}
    if (word == "-" || word == "Subtract" || word == "subtract")
    {
        return '-';
    }
    if (word == "*" || word == "Multiply" || word == "multiply")
    {
        return '*';
    }
    if (word == "/" || word == "Divide" || word == "divide")
    {
        return '/';
    }
    if (word == "s" || word == "Split" || word == "split")
    {
        return 's';
    }
    if (word == "l" || word == "List" || word == "list")
    {
        return 'l';
    }
    if (word == "c" || word == "Cheat" || word == "cheat")
    {
        return 'c';
    }
    if (word == "q" || word == "Quit" || word == "quit")
    {
        return 'q';
    }
    return 't';
}

bool operationInput(NumberList& numlist)
{
	std::string input, tempStr;
    std::cout << "Select 2 numbers you want to use from the list and type the operation you wish to use..." << std::endl;
    std::getline(std::cin, input);
    std::vector<std::string> inputVec = splitString(input);    

    char operation = findOperation(inputVec[0]);

    try
    {
        if (inputVec.size() < 3 && (operation == '+' || operation == '-' || operation == '*' || operation == '/')) { throw std::invalid_argument("Operation requires two values!");; }
        if (inputVec.size() < 2 && (operation == 's')) { throw std::invalid_argument("Operation requires a value!"); }
        if (inputVec.size() > 3) { throw std::invalid_argument("Too many values!"); }
    	
        switch (operation)
        {
        case '+':
            numlist.add(std::stoi(inputVec[1]), std::stoi(inputVec[2]));
            numlist.print();
            break;
        case '-':
            numlist.subtract(std::stoi(inputVec[1]), std::stoi(inputVec[2]));
            numlist.print();
            break;
        case '*':
            numlist.multiply(std::stoi(inputVec[1]), std::stoi(inputVec[2]));
            numlist.print();
            break;
        case '/':
            numlist.divide(std::stoi(inputVec[1]), std::stoi(inputVec[2]));
            numlist.print();
            break;
        case 's':
            numlist.split(std::stoi(inputVec[1]));
            numlist.print();
            break;
        case 'q':
            return true;
        case 'l':
            numlist.print();
            break;
        case 'c':
            numlist.printSolution();
            break;
        default:
            throw std::invalid_argument(
	            "Input is incorrect. Please enter as 'Operation FirstNumber SecondNumber./nAvailable inputs are Add, Subtract, Multiply, Divide, Split, Quit ' ");
            
            // ADD QUIT FUNCTIONALITY ------------------------------------------------------------------------------------------------
        }
    }
    catch (const std::invalid_argument& e)
    {
		std::cout << "Error: '"<< e.what() << "'" << std::endl;
    	return false;
    }
        return false;
}




void gameLoop(NumberList &numberList)
{
	while (true)
	{
		if (operationInput(numberList))
		{
            std::cout << "You quit... Goodbye. Here is a possible solution: " << std::endl;
            numberList.printSolution();
            return;
		}
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
	gameStart();
}


#include "NumberList.h"

NumberList::NumberList(int min_given, int max_given)
{
	for (int i = min_given; i <= max_given; i++) // makes list starting from the number 1 until it reaches the number 10
	{
		m_numbers.push_back(new GivenNumber(i)); //appends numbers to the end
	}

	m_targetNum = rand() % 899 + 100; // sets the target number range from 100 to 999
	std::cout << "Target number is " << m_targetNum << std::endl;
}

void NumberList::add(int x, int y)
{
	
}

void NumberList::subtract(int x, int y)
{
	
}

void NumberList::multiply(int x, int y)
{
	
}

void NumberList::divide(int x, int y)
{
	
}

void NumberList::split(int x)
{
	
}

void NumberList::targetFound()
{
	
}

void NumberList::print()
{
	
}

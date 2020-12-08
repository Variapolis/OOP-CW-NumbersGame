

#include "GivenNumber.h"

#include <iostream>

GivenNumber::GivenNumber(int value) // Constructor initializes simple int value
	: Number(value)
{
}

int GivenNumber::getValue() // Typical 
{
	return m_value;
}

bool GivenNumber::isSplittable() // Always not splittable
{
	return false;
}

void GivenNumber::split(std::list<Number*>& myNumbers) // Does nothing
{
}

void GivenNumber::print(bool isFirst) // Prints the value of the number
{
	std::cout << m_value;
}

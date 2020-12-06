#include "GivenNumber.h"

#include <iostream>

GivenNumber::GivenNumber(int value)
	: Number(value)
{
}

int GivenNumber::getValue()
{
	return m_value;
}

bool GivenNumber::isSplittable()
{
	return false;
}

void GivenNumber::split(std::list<Number*>& myNumbers)
{
}

void GivenNumber::print(bool isFirst)
{
	std::cout << m_value;
}

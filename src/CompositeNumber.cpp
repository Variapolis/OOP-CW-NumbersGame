#include "CompositeNumber.h"


#include <iostream>
#include <string>

CompositeNumber::CompositeNumber(int value, Number* comp1, Number* comp2, char operation)
	: Number(value), m_component1(comp1), m_component2(comp2), m_operation(operation)
{

}

int CompositeNumber::getValue()
{
	return m_value;
}

std::string CompositeNumber::getOperation()
{
	return "undefined";
}

bool CompositeNumber::isSplittable()
{
	return true;
}

void CompositeNumber::split(std::list<Number*>& myNumbers)
{
	myNumbers.push_back(m_component1);
	myNumbers.push_back(m_component2);
}

void CompositeNumber::print(bool isFirst)
{
	if (isFirst) { std::cout << m_value << " ="; }
	std::cout << "(";
	m_component1->print(false);
	std::cout << m_operation;
	m_component2->print(false);
	std::cout << ")";
}

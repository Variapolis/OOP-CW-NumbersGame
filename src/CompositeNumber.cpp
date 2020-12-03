#include "CompositeNumber.h"

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
}

void CompositeNumber::print()
{
}

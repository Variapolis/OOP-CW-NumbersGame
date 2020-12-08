<<<<<<< HEAD
<<<<<<< HEAD


=======
>>>>>>> parent of 4bfa74a... Restarts after winning
=======
>>>>>>> parent of 4bfa74a... Restarts after winning
#include "CompositeNumber.h"


#include <iostream>
#include <string>

CompositeNumber::CompositeNumber(int value, Number* comp1, Number* comp2, char operation)
	: Number(value), m_component1(comp1), m_component2(comp2), m_operation(operation) // Constructor initializes the value, components and operation (Could use 3 params, value is redundant)
{

}

int CompositeNumber::getValue() // Typical getter
{
	return m_value;
}

bool CompositeNumber::isSplittable() // Composite always splittable
{
	return true;
}

void CompositeNumber::split(std::list<Number*>& myNumbers) //Pushes back original numbers to the provided list.
{
	myNumbers.push_back(m_component1);
	myNumbers.push_back(m_component2);
}

void CompositeNumber::print(bool isFirst) // Prints out itself (if it's first in the queue), then the ingredients and operations to show its makeup. 
{
	if (isFirst) { std::cout << m_value << " ="; }
	std::cout << "(";
	m_component1->print(false);
	std::cout << m_operation;
	m_component2->print(false);
	std::cout << ")";
}

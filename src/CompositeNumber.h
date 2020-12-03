#pragma once
#include <xstring>

#include "Number.h"

class CompositeNumber
	: public Number
{
	Number* m_component1;
	Number* m_component2;
	char m_operation;
public:
	CompositeNumber(int value, Number* comp1, Number* comp2, char operation);
	int getValue() override;
	std::string getOperation();
	bool isSplittable() override;
	void split(std::list<Number*>& myNumbers) override;
	void print() override;
};


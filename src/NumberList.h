#pragma once
#include <list>
#include <iostream>

#include "Number.h"
#include "GivenNumber.h"
#include "CompositeNumber.h"

class NumberList
{
private:
	int m_targetNum;
	std::list<Number*> m_numbers;
public:
	NumberList(int min_given, int max_given);
	void add(int x, int y);
	void subtract(int x, int y);
	void multiply(int x, int y);
	void divide(int x, int y);
	void split(int x);
	void targetFound();
	void print();
};


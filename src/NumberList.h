
#pragma once
#include <list>
#include "CompositeNumber.h"

class NumberList
{
private:
	const int m_listMin = 1, m_listMax = 10, m_targetMax = 999, m_targetMin = 100;
	Number* m_targetNum;
	std::list<Number*> m_numbers;
public:
	NumberList();
	void createTarget();
	void add(int x, int y);
	void subtract(int x, int y);
	void multiply(int x, int y);
	void divide(int x, int y);
	void split(int x);
	bool targetFound();
	void print();
	void printSolution();
};


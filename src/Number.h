#pragma once
#include <list>

class Number
{
protected:
	int m_value;
public:
	Number(int value);
	virtual int getValue() = 0;
	virtual bool isSplittable() = 0;
	virtual void split(std::list<Number*>& myNumbers) = 0;
	virtual void print(bool isFirst) = 0;
};


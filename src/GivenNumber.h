

#pragma once
#include "Number.h"

class GivenNumber :
    public Number
{
public:
	GivenNumber(int value);
	int getValue() override;
	bool isSplittable() override;
	void split(std::list<Number*>& myNumbers) override;
	void print(bool isFirst) override;
};


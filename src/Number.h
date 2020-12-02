#pragma once
#include <list>

class Number
{
private:
	int m_value;
	bool m_splittable;
	Number* m_split1;
	Number* m_split2;
public:
	virtual int getValue();
	virtual bool isSplittable();
	void split(std::list<Number*>& myNumbers);
	
};


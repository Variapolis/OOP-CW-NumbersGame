#include "NumberList.h"

#include <vector>

NumberList::NumberList()
{	
	for (int i = m_listMin; i <= m_listMax; i++) // Makes a list from the const of listMin to listMax, iterating by one each time.
	{
		m_numbers.push_back(new GivenNumber(i)); // Appends a new GivenNumber of value i
	}
    createTarget();
    print();
}

void NumberList::createTarget()
{
    std::vector<Number*> tempVector;
    int position1, position2;
    for (int i = m_listMin; i <= m_listMax; i++) // Makes a list from the const of listMin to listMax, iterating by one each time.
    {
        tempVector.push_back(new GivenNumber(i)); // Appends a new GivenNumber of value i
    }
    position1 = position2 = rand() % tempVector.size();
    while (position2 == position1) { position2 = rand() % tempVector.size(); }
    m_targetNum = (new CompositeNumber(tempVector[position1]->getValue() + tempVector[position2]->getValue(), tempVector[position1], tempVector[position2], '+'));
	while(m_targetNum->getValue() < 100 && tempVector.size() > 1)
	{
        position1 = rand() % tempVector.size();
        bool operation = rand() % 2;
        switch (operation)
        {
        case 0:
            m_targetNum = (new CompositeNumber(tempVector[position1]->getValue() + m_targetNum->getValue(), tempVector[position1], m_targetNum, '+'));
            break;
        case 1:
            m_targetNum = (new CompositeNumber(tempVector[position1]->getValue() * m_targetNum->getValue(), tempVector[position1], m_targetNum, '*'));
            break;
        }
	}
    if (m_targetNum->getValue() < 100) { createTarget(); }
}

void NumberList::add(int x, int y)
{
    std::list<Number*>::iterator it1, it2;
    bool numFound1 = false, numFound2 = false;
    // Iterates through the list using two stl iterators to find x and y via two for loops. Could condense into one but leaving for the sake of readability.
    for (it1 = m_numbers.begin(); it1 != m_numbers.end(); ++it1) 
    {
        if ((*it1)->getValue() == x) // If number is found, stops iterating.
        {
            numFound1 = true;
            break;
        }
    }
    for (it2 = m_numbers.begin(); it2 != m_numbers.end(); ++it2) // Same as above but with iterator 2.
    {
        if ((*it2)->getValue() == y && it2 != it1)
        {
            numFound2 = true;
            break;
        }
    }

	if(numFound1 && numFound2) // If both numbers are found, pushes back a new Composite Number containing both original numbers, the operation and the value of the combined nums.
	{
        m_numbers.push_back(new CompositeNumber((*it1)->getValue() + (*it2)->getValue(), (*it1), (*it2), '+'));
        m_numbers.erase(it1);
        m_numbers.erase(it2);
	}
    else if (!numFound1 && numFound2) { std::cout << x << " is not in your list!" << std::endl; } // Varied statements based which numbers were not found.
    else if (numFound1 && !numFound2) { std::cout << y << " is not in your list!" << std::endl; }
    else { std::cout << x << " and " << y<< " is not in your list!" << std::endl; }
}

void NumberList::subtract(int x, int y)
{
    std::list<Number*>::iterator it1, it2;
    bool numFound1 = false, numFound2 = false;
    if (x > y)
    {
        // Iterates through the list using two stl iterators to find x and y via two for loops. Could condense into one but leaving for the sake of readability.
        for (it1 = m_numbers.begin(); it1 != m_numbers.end(); ++it1) 
        {
            if ((*it1)->getValue() == x)// If number is found, stops iterating.
            {
                numFound1 = true;
                break;
            }
        }
        for (it2 = m_numbers.begin(); it2 != m_numbers.end(); ++it2)// Same as above but with iterator 2.
        {
            if ((*it2)->getValue() == y && it2 != it1)
            {
                numFound2 = true;
                break;
            }
        }

        if (numFound1 && numFound2)// If both numbers are found, pushes back a new Composite Number containing both original numbers, the operation and the value of the combined nums.
        {
            m_numbers.push_back(new CompositeNumber((*it1)->getValue() - (*it2)->getValue(), (*it1), (*it2), '-'));
            m_numbers.erase(it1);
            m_numbers.erase(it2);
        }
        else if (!numFound1 && numFound2) { std::cout << x << " is not in your list!" << std::endl;  } // Varied statements based which numbers were not found.
        else if (numFound1 && !numFound2) { std::cout << y << " is not in your list!" << std::endl;  }
        else { std::cout << x << " and " << y << " is not in your list!" << std::endl;  }
    }
    else { std::cout << "You cannot make negative numbers!" << std::endl; }
}

void NumberList::multiply(int x, int y)
{
    std::list<Number*>::iterator it1, it2;
    bool numFound1 = false, numFound2 = false;
    // Iterates through the list using two stl iterators to find x and y via two for loops. Could condense into one but leaving for the sake of readability.
    for (it1 = m_numbers.begin(); it1 != m_numbers.end(); ++it1)// If number is found, stops iterating.
    {
        if ((*it1)->getValue() == x)
        {
            numFound1 = true;
            break;
        }
    }
    for (it2 = m_numbers.begin(); it2 != m_numbers.end(); ++it2)// Same as above but with iterator 2.
    {
        if ((*it2)->getValue() == y && it2 != it1)
        {
            numFound2 = true;
            break;
        }
    }

    if (numFound1 && numFound2)// If both numbers are found, pushes back a new Composite Number containing both original numbers, the operation and the value of the combined nums.
    {
        m_numbers.push_back(new CompositeNumber((*it1)->getValue() * (*it2)->getValue(), (*it1), (*it2), '*'));
        m_numbers.erase(it1);
        m_numbers.erase(it2);
    }
    else if (!numFound1 && numFound2) { std::cout << x << " is not in your list!" << std::endl; } // Varied statements based which numbers were not found.
    else if (numFound1 && !numFound2) { std::cout << y << " is not in your list!" << std::endl; }
    else { std::cout << x << " and " << y << " is not in your list!" << std::endl; }
}

void NumberList::divide(int x, int y)
{
    std::list<Number*>::iterator it1, it2;
    bool numFound1 = false, numFound2 = false;
    if (!(x % y))
    {
        // Iterates through the list using two stl iterators to find x and y via two for loops. Could condense into one but leaving for the sake of readability.
        for (it1 = m_numbers.begin(); it1 != m_numbers.end(); ++it1)// If number is found, stops iterating.
        {
            if ((*it1)->getValue() == x && it2 != it1)
            {
                numFound1 = true;
                break;
            }
        }
        for (it2 = m_numbers.begin(); it2 != m_numbers.end(); ++it2)// Same as above but with iterator 2.
        {
            if ((*it2)->getValue() == y)
            {
                numFound2 = true;
                break;
            }
        }

        if (numFound1 && numFound2)// If both numbers are found, pushes back a new Composite Number containing both original numbers, the operation and the value of the combined nums.
        {
            m_numbers.push_back(new CompositeNumber((*it1)->getValue() / (*it2)->getValue(), (*it1), (*it2), '/'));
            m_numbers.erase(it1);
            m_numbers.erase(it2);
        }
        else if (!numFound1 && numFound2) { std::cout << x << " is not in your list!" << std::endl; } // Varied statements based which numbers were not found.
        else if (numFound1 && !numFound2) { std::cout << y << " is not in your list!" << std::endl; }
        else { std::cout << x << " and " << y << " is not in your list!" << std::endl; }
    }
    else { std::cout << "You can't divide by this number as it would return a remainder!" << std::endl; }
}

void NumberList::split(int x)
{
    std::list<Number*>::iterator it;
    bool numFound = false;
    for (it = m_numbers.begin(); it != m_numbers.end(); ++it)
    {
        if ((*it)->getValue() == x)
        {
            numFound = true;
        	if((*it)->isSplittable())
        	{
                (*it)->split(m_numbers);
                delete (*it);
                m_numbers.erase(it);
                return;
        	}
        }
    }
    if (numFound) { std::cout << x << "is not splittable!" << std::endl;   return; }
    std::cout << x << " is not in your list!" << std::endl;
}

bool NumberList::targetFound()
{
    std::list<Number*>::iterator it;
    for (it = m_numbers.begin(); it != m_numbers.end(); ++it)
    {
        if ((*it)->getValue() == m_targetNum->getValue())
        {
            std::cout << "Target reached!" << std::endl;
            return true;
        }
    }
    return false;
}

void NumberList::print()
{
    std::list<Number*>::iterator it;
    for (it = m_numbers.begin(); it != m_numbers.end(); it++)
    {
        (*it)->print(true);
        std::cout << ", ";
    }
    std::cout << "and the target number is " << m_targetNum->getValue() << ". " << std::endl;
}

void NumberList::printSolution()
{
    m_targetNum->print(true);
}

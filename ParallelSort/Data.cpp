#include "Data.h"
#include <cstdlib>
#include <ctime>
#include <algorithm>

Data::Data()
{
	std::srand(unsigned(std::time(0)));
	for (int i = 0; i < 1000; i++)
	{
		Row temp;
		temp.Nums.push_back(i);
		m_lRows.push_back(temp);
	}
	for (int i = 0; i < mySize; i++)
	{
		m_IndexMap.emplace(i, i);
		for (int j = 1; j < mySize; j++)
			m_lRows[i].Nums.push_back(std::rand()%10000);
	}
	for (int i = 0; i <= mySize; i++)
	{
		m_ColIndex.emplace(std::string("Name " + std::to_string(i)), i+1);
	}
	for (std::string name : m_lPriorityList)
	{
		for (int i = 0; i < mySize; i++)
		{
			m_lPriorityRows[i].Nums.push_back(m_lRows[i].Nums[m_ColIndex[name]]);
		}
	}
	for (int i = 0; i < mySize; i++)
	{
		m_lPriorityRows[i].Nums.push_back(m_IndexMap[i]);
	}
	std::sort(m_lPriorityRows.begin(),m_lPriorityRows.end());
	for (int i = 0; i < mySize; i++)
	{
		m_SortedIndexMap.emplace(i, m_lPriorityRows[i].Nums.back());
	}
}

bool operator<(Row a, Row b)
{
	for (int i = 0; i < a.Nums.size(); i++)
	{
		if (a.Nums.at(i) < b.Nums.at(i))
			return true;
		if (a.Nums.at(i) > b.Nums.at(i))
			return false;
	}
	return false;
}

Data::~Data()
{
}

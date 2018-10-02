#pragma once
#include <vector>
#include <map>
#include "Row.h"
class Data
{
public:
	std::vector<Row> m_lRows;
	std::vector<Row> m_lPriorityRows = std::vector<Row>(mySize);
	std::vector<std::string> m_lPriorityList = { "Name 3", "Name 4", "Name 7", "Name 45", "Name 34" };
	std::map<int, int> m_IndexMap;
	std::map<int, int> m_SortedIndexMap;
	std::map<std::string, int> m_ColIndex;
	Data();
	~Data();
};


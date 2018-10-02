#pragma once
#include <vector>
#include <string>
#define mySize 1000 
class Row
{
public:
	std::vector<int> Nums;
	std::string Name;
	Row();
	~Row();
	friend bool operator < (Row a, Row b);
};


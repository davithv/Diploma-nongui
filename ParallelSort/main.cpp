#include <iostream>
#include "Data.h"
int main()
{
	Data d;
	for (int i = 0; i < 1000; i++)
		std::cout << i << " : " << d.m_SortedIndexMap[i] << std::endl;
	std::getchar();
	return 0;
}
#include "Tools.h"

void Tools::printVector(std::vector<int> nums)
{
	cout << "\n =======Begin print vector===============" << endl;
	for (vector<int>::iterator it = nums.begin(); it != nums.end(); it++)
	{
		cout << *it << " ";
	}
}

void Tools::printDoubleVector(vector<vector<int>> vec)
{
	cout << "\n ======Begin print Double vector=======" << endl;
	for (vector<vector<int>>::iterator it = vec.begin(); it != vec.end(); it++)
	{
		for (vector<int>::iterator itt = (* it).begin(); itt != (*it).end(); itt++)
		{
			cout << *itt << " ";
		}
		cout << endl;
	}
}

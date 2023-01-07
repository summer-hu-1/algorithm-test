#include "arrayTest.h"

#include <iostream>

#include "Tools.h"
using namespace std;

Tools tool;

/// <summary>
/// ²âÊÔÊı×é
/// </summary>
/// <returns></returns>
void testArray()
{
	arrayTest testArray;
	cout << "test for double arraySize:" << endl;
	testArray.test_arr();

	cout << "\n ==========test for search================" << endl;;
	vector<int> nums{ 1, 3, 5, 7, 9 };
	cout << "find result:" << testArray.search(nums, 5);

	cout << "\n ============test for ranking squared=====" << endl;
	vector<int> squared{ -2, -1, 2, 6 };
	tool.printVector(testArray.sortedSquares(squared));

	cout << "\n ============test for minSubArrayLen======" << endl;
	vector<int> minSubVec{ 1, 2, 3, 4, 5, 6, 7 };
	cout << testArray.minSubArrayLen(10, nums);

	cout << "\n ============test for generateMatrix======" << endl;
	tool.printDoubleVector(testArray.generateMatrix(3));
}

int main()
{
	/// <summary>
	/// ²âÊÔÁ´±í
	/// </summary>
	/// <returns></returns>

	return 0;
}
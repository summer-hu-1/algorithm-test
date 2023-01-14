#include "arrayTest.h"

#include <iostream>

#include "listTest.h"
#include "Tools.h"
using namespace std;

Tools tool;

/// <summary>
/// ��������
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

/// <summary>
/// ��������
/// </summary>
/// <returns></returns>
void testList()
{
	ListTest testList;
	/*cout << "test for List algorithm:" << endl;
	ListNode* list = tool.getSingleLinkedList({1, 10, 2, 10, 5, 10, 4});
	tool.printList(list);
	testList.removeElements(list, 10);
	cout << "test after rectify:" << endl;
	tool.printList(list);
	tool.deleteList(list);*/
	
	MyLinkedList* myList = new MyLinkedList();
	myList->addAtHead(7);
	myList->addAtHead(2);
	myList->addAtHead(1);
	myList->printList();

	myList->addAtIndex(3, 0);
	myList->printList();
	myList->deleteAtIndex(2);
	myList->printList();
	myList->addAtHead(6);
	myList->printList();
	myList->addAtTail(4);
	cout << "myList->get(4):" << myList->get(4);
	myList->addAtHead(4);
	myList->printList();
	myList->addAtIndex(5, 0);
	myList->printList();
	myList->addAtHead(6);
	myList->printList();
}

int main()
{
	srand(time(0));

	testList();
	return 0;
}
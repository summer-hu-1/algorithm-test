#include "arrayTest.h"

#include <iostream>

#include "CharTest.h"
#include "listTest.h"
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

/// <summary>
/// ²âÊÔÁ´±í
/// </summary>
/// <returns></returns>
void testList()
{
	ListTest testList;

	///one:
	cout << "test for List algorithm:" << endl;
	ListNode* list = tool.getSingleLinkedList({1, 10, 2, 10, 5, 10, 4});
	tool.printList(list);
	testList.removeElements(list, 10);
	cout << "test after rectify:" << endl;
	tool.printList(list);
	tool.deleteList(list);

	///two:
	cout << "test MyLinkedList: " << endl;
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

	///three:
	cout << "test for reverseList: " << endl;
	ListNode* list2 = tool.getSingleLinkedList({ 1, 2, 3, 4, 5, 6, 7 });
	tool.printList(list2);
	ListNode* list22 = testList.reverseList(list2);
	cout << "test after rectify:" << endl;
	tool.printList(list22);
	tool.deleteList(list2);
}

/**
 * \brief ²âÊÔ×Ö·û´®ÀàĞÍ
 */
void testChar()
{
	CharTest test;
	int n = 6;
	char* str = new char[n];
	for (int i = 0; i < 5; ++i)
		*(str + i) = 'a' + i;
	*(str + 5) = '\0';
	cout << str << endl;
	cout << "after transfer to upper:" << test._strupr(str);

}

int main()
{
	srand(time(0));

	testChar();

	return 0;
}
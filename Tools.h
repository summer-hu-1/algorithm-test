#pragma once
#include <vector>
#include <iostream>

#include "listTest.h"

using namespace std;
class Tools
{
public:
	int getRand(int min, int max);

	///vector
	void printVector(std::vector<int> nums);
	void printDoubleVector(vector<vector<int>> vec);

	///list
	ListNode* getSingleLinkedList(vector<int> vec);
	ListNode* getRandomSingledLinkedList(int n); ///����һ���������ȵ��������
	void printList(ListNode* head);
	void deleteList(ListNode* head);
};



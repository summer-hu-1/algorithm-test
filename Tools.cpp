#include "Tools.h"

int Tools::getRand(int min, int max)
{
	return (rand() % (max - min + 1)) + min;
}

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

ListNode* Tools::getSingleLinkedList(vector<int> vec)
{
	ListNode Dummy(0, nullptr);
	ListNode* pre = &Dummy;
	for (size_t i = 0; i < vec.size(); i++)
	{
		ListNode* temp = new ListNode();
		temp->val = vec[i];
		temp->next = nullptr;
		pre->next = temp;
		pre = temp;
	}
	return Dummy.next;
}

ListNode* Tools::getRandomSingledLinkedList(int n)
{
	ListNode Dummy(0, nullptr);
	ListNode* pre = &Dummy;
	for (int i = 0; i < n; i++)
	{
		ListNode* temp = new ListNode();
		temp->val = getRand(0, 100);
		temp->next = nullptr;
		pre->next = temp;
		pre = temp;
	}
	return Dummy.next;
}

void Tools::printList(ListNode* head)
{
	cout << "print List:" << endl;
	while (head)
	{
		cout << head->val << " ";
		head = head->next;
	}
}

void Tools::deleteList(ListNode* head)
{
	cout << "start delete List:" << endl;
	while (head)
	{
		ListNode* temp = head;
		head = head->next;
		delete temp;
	}
}


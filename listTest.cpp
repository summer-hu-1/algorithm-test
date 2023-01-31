#include "listTest.h"

#include <iostream>

MyLinkedList::MyLinkedList()
{
	dummyHead = new ListNode(0, nullptr);
}

int MyLinkedList::get(int index)
{
	if (index < 0 || index >= size)  ///bug one: 条件判断失误导致
		return -1;
	ListNode* cur = dummyHead->next;  ///理解当前节点就是待输出节点。
	while (index && cur)
	{
		cur = cur->next;
		index--;
	}
	return cur->val;
}

void MyLinkedList::addAtHead(int val)
{
	ListNode *newNode = new ListNode(val, dummyHead->next);
	dummyHead->next = newNode;
	size++;
}

void MyLinkedList::addAtTail(int val)
{
	ListNode* cur = dummyHead;
	while (cur->next) 
		cur = cur->next;  ///重点保存最后一个存在的节点即可。

	ListNode* newNode = new ListNode(val, nullptr);
	cur->next = newNode;
	size++;
}

void MyLinkedList::addAtIndex(int index, int val)
{
	if (index < 0)
		addAtHead(val);
	else if (index > size)
		return;
	else
	{
		ListNode* pre = dummyHead;
		while (index)
		{
			pre = pre->next;
			index--;
		}
		ListNode* newNode = new ListNode(val, pre->next);
		pre->next = newNode;
		size++;
	}
}

void MyLinkedList::deleteAtIndex(int index)
{
	if (index < 0 || index >= size)
		return;
	ListNode* pre = dummyHead;
	while (index)  ///bug two:可以写成while(--index)  但一般不写成while(index--).
	{
		pre = pre->next;
		index--;
	}
		
	ListNode* tmp = pre->next;
	pre->next = pre->next->next;
	delete tmp;
	size--;
}

void MyLinkedList::printList()
{
	ListNode* cur = dummyHead;
	cout << "\n start cout MyLinkedList:" << endl;
	while (cur->next)
	{
		cur = cur->next;
		cout << cur->val << " ";
	}
}
///一些思考：处理链表问题首先定好原则：1.size是大小， index是下标（0开始） 3.是否需要头节点
///4.先接链，再断链为原则。  

ListNode* ListTest::removeElements(ListNode* head, int val)
{
	///头指针方式：
	
	///方式一：（傀儡）头指针版本
	/*ListNode Dummy(0, head);
	ListNode *cur = head, *pre = &Dummy;
	while (cur)
	{
		if (cur->val == val)
		{
			pre->next = cur->next;
			ListNode* p = cur;
			cur = cur->next;
			delete p;
		}
		else
		{
			pre = cur;
			cur = cur->next;
		}
	}
	return Dummy.next;*/
	///一些思考：利用傀儡头节点，可以将所有节点的周围环境处理情况保持一致。
	///链表需要删除节点,需要借助前驱节点来帮忙实现。
	
	///方式二：简介版本
	ListNode dummy(0, head);
	ListNode* cur = &dummy;
	while (cur->next)
	{
		if (cur->next->val == val)
		{
			ListNode* tmp = cur->next;
			cur->next = cur->next->next;
			delete tmp;
		}
		else
		{
			cur = cur->next;
		}
	}
	return dummy.next;
	///一些思考：直接利用前驱节点来处理流动，下一个节点（为主节点）实现节点的当前值判定和删除等操作。
}

ListNode* ListTest::reverseList(ListNode* head)
{
	///方法三：递归法
	

	///方法一：双指针法
	/*if (head == nullptr)
		return nullptr;

	ListNode* pre = head;
	ListNode* cur = head->next;
	while (cur)
	{
		ListNode* temp = cur->next;
		cur->next = pre;
		pre = cur;
		cur = temp;
	}
	return  pre;*/

	///方法二：简洁版本
	ListNode* pre = nullptr;
	ListNode* cur = head;
	while (cur)
	{
		ListNode* next = cur->next;
		cur->next = pre;
		pre = cur;
		cur = next;
	}
	return pre;

	///一些思考：1.前一个指针首先未空， 2.保留下一个指针， 3.当前指针是否为空 未判定依据
}

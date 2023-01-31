#include "listTest.h"

#include <iostream>

MyLinkedList::MyLinkedList()
{
	dummyHead = new ListNode(0, nullptr);
}

int MyLinkedList::get(int index)
{
	if (index < 0 || index >= size)  ///bug one: �����ж�ʧ����
		return -1;
	ListNode* cur = dummyHead->next;  ///��⵱ǰ�ڵ���Ǵ�����ڵ㡣
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
		cur = cur->next;  ///�ص㱣�����һ�����ڵĽڵ㼴�ɡ�

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
	while (index)  ///bug two:����д��while(--index)  ��һ�㲻д��while(index--).
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
///һЩ˼�������������������ȶ���ԭ��1.size�Ǵ�С�� index���±꣨0��ʼ�� 3.�Ƿ���Ҫͷ�ڵ�
///4.�Ƚ������ٶ���Ϊԭ��  

ListNode* ListTest::removeElements(ListNode* head, int val)
{
	///ͷָ�뷽ʽ��
	
	///��ʽһ�������ܣ�ͷָ��汾
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
	///һЩ˼�������ÿ���ͷ�ڵ㣬���Խ����нڵ����Χ���������������һ�¡�
	///������Ҫɾ���ڵ�,��Ҫ����ǰ���ڵ�����æʵ�֡�
	
	///��ʽ�������汾
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
	///һЩ˼����ֱ������ǰ���ڵ���������������һ���ڵ㣨Ϊ���ڵ㣩ʵ�ֽڵ�ĵ�ǰֵ�ж���ɾ���Ȳ�����
}

ListNode* ListTest::reverseList(ListNode* head)
{
	///���������ݹ鷨
	

	///����һ��˫ָ�뷨
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

	///�����������汾
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

	///һЩ˼����1.ǰһ��ָ������δ�գ� 2.������һ��ָ�룬 3.��ǰָ���Ƿ�Ϊ�� δ�ж�����
}

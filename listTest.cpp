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

ListNode* ListTest::swapPairs(ListNode* head)
{
	/// ����һ��ģ�ⷨ ���������������ɡ�
	ListNode dummy(0, head);
	ListNode* cur = head;
	ListNode* pre = &dummy;
	while (cur && cur->next)
	{
		ListNode* temp = cur->next;
		cur->next = temp->next;  ///
		temp->next = cur;  /// 
		pre->next = temp;  ///
		pre = cur;
		cur = cur->next;
	}
		return dummy.next;
	///һЩ˼���������һ����㣬���Ӻ��к�ǰ��

	///�����������汾  
	/*ListNode dummyHead(0, head);
	ListNode* cur = &dummyHead;
	while (cur->next && cur->next->next) {
		ListNode* temp1 = cur->next;
		ListNode* temp2 = cur->next->next;
		ListNode* temp3 = cur->next->next->next;

		cur->next = temp2;
		cur->next->next = temp1;
		cur->next->next->next = temp3;
		cur = cur->next->next;
	}
	return dummyHead.next;*/

	///һЩ˼�������������������ԣ�������Ӵ����ӵĽ�㡣
	///1.�������������
	///2.���õ�ǰ���������Ӷ�Ӧ��㼴��
	///3.�ƶ���ǰ��㵽��Ӧλ�á�
}

ListNode* ListTest::removeNthFromEnd(ListNode* head, int n)
{
	///����һ��˫ָ��
	//Ŀ�ģ�slowָ���ɾ��ǰ׺����fastָ������ĩβ��ָ��ʱ��slow��fast���n+1�����
	/*ListNode dummy(0, head);
	ListNode* slow = &dummy;
	ListNode* fast = dummy.next;

	while (n--) {
		fast = fast->next;
	}
	while (fast) {
		fast = fast->next;
		slow = slow->next;
	}
	ListNode* temp = slow->next;
	slow->next = temp->next;
	delete temp;
	return dummy.next;*/

	///��������
	///���ģ�����˫ָ��Ĵ���ʽ��
	///һЩ˼����while (n--)����ʵ��ָ�����n����
	///һЩ˼�����������Ǵ�ɾ������ǰ��ָ�롣
	ListNode dummy(0, head);
	ListNode* slow = &dummy;
	ListNode* fast = &dummy;
	while (n--) {
		fast = fast->next;
	}
	while (fast->next) {
		fast = fast->next;
		slow = slow->next;
	}
	ListNode* temp = slow->next;
	slow->next = temp->next;
	delete temp;
	return dummy.next;
}

ListNode* ListTest::getIntersectionNode(ListNode* headA, ListNode* headB)
{
	///����һ�� ģ�ⷨ
	///ģ�ⷨ����ʽ�������ҵ���ͬ�����λ�ã�ͬʱ�ƶ�������ͬ������ȷ��
	/*int m = 0, n = 0;
	ListNode* cur = headA;
	while (cur) {
		m++;
		cur = cur->next;
	}
	cur = headB;
	while (cur) {
		n++;
		cur = cur->next;
	}
	int diff = m - n;
	if (diff < 0) {
		diff = -diff;
		while (diff--) {
			headB = headB->next;
		}
	}
	else {
		while (diff--) {
			headA = headA->next;
		}
	}

	while (headA && headB && headA != headB) {
		headA = headA->next;
		headB = headB->next;
	}
	return headA;*/

	///�������������໥���ӣ������µĵȳ��ֶ�
	///���Թ�ָͬ���ָ���λ��
	ListNode* pA = headA;
	ListNode* pB = headB;

	while (pA != pB) {
		pA = pA == nullptr ? headB : pA->next;
		pB = pB == nullptr ? headA : pB->next;
	}
	return pA;
	///һЩ˼�������߳���һ����ͬ���л������л���һ��nullptr�Ĺ��ɽ�㡣�������ͬ������β��Ȼ��ͬ ��
	///���û����ͬ������Ȼ�����ٿ�ָ�롣
}

ListNode* ListTest::detectCycle(ListNode* head)
{

	/// ����������ָ��
	/*ListNode* slow = head;
	ListNode* fast = head;
	while (true)
	{
		if (!fast || !fast->next || !fast->next->next)
		{
			return nullptr;
		} 
		fast = fast->next->next;
		slow = slow->next;

		if (fast == slow)
			break;
	}
	slow = head;
	while (slow != fast)
	{
		slow = slow->next;
		fast = fast->next;
	}
	return slow;*/
	///һЩ˼����ѧ�����ñ�������������Ե���������x-����ֵ,y����ֵ,r����ֵ��
	///�ص��ס�����㷨˼ά������ָ���д���->������ϵ���Ƴ�����
	///(��ָ�뻨�������ӣ�x + n*r)���ŵȵ�һ���ӵ��氮(x + y)����������Я���߹�һ������ʱ�⣨y);


	///������:���Լ��汾
	ListNode* slow = head;
	ListNode* fast = head;
	while (fast->next && fast->next->next)
	{
		slow = slow->next;
		fast = fast->next->next;

		if (slow == fast)
		{
			ListNode* index1 = head;
			ListNode* index2 = slow;
			while (index1 != index2)
			{
				index1 = index1->next;
				index2 = index2->next;
			}
			return index1;
		}
	}
	return nullptr;
}

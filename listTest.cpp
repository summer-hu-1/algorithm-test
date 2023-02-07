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

ListNode* ListTest::swapPairs(ListNode* head)
{
	/// 方法一：模拟法 后者两两交换即可。
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
	///一些思考：保存后一个结点，连接后、中和前。

	///方法二：简洁版本  
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

	///一些思考：利用链表连接特性，逐个连接待链接的结点。
	///1.保存下三个结点
	///2.利用当前结点逐个链接对应结点即可
	///3.移动当前结点到对应位置。
}

ListNode* ListTest::removeNthFromEnd(ListNode* head, int n)
{
	///方法一：双指针
	//目的：slow指向待删除前缀，而fast指向链表末尾空指针时，slow与fast相距n+1个间隔
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

	///方法二：
	///核心：采用双指针的处理方式。
	///一些思考：while (n--)可以实现指针后移n步；
	///一些思考：保留的是待删除结点的前驱指针。
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
	///方法一： 模拟法
	///模拟法处理方式：首先找到相同的起点位置，同时移动，点相同则结果正确。
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

	///方法二：二者相互连接，构成新的等长字段
	///可以共同指向空指针的位置
	ListNode* pA = headA;
	ListNode* pB = headB;

	while (pA != pB) {
		pA = pA == nullptr ? headB : pA->next;
		pB = pB == nullptr ? headA : pB->next;
	}
	return pA;
	///一些思考：两者长度一定相同，切换过程中会有一个nullptr的过渡结点。如果有相同，最后结尾必然相同 。
	///如果没有相同，最后必然都面临空指针。
}

ListNode* ListTest::detectCycle(ListNode* head)
{

	/// 方法：快慢指针
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
	///一些思考：学会设置变量，分清楚各自的所求量》x-待求值,y相遇值,r环形值。
	///重点记住此类算法思维，快慢指针判存在->两倍关系倒推初遇点
	///(快指针花了两辈子（x + n*r)，才等到一辈子的真爱(x + y)，并在最终携手走过一段美好时光（y);


	///方法二:面试简洁版本
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

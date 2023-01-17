#pragma once
using namespace std;

struct ListNode
{
	int val;
	ListNode* next;
	ListNode() : val(0), next(nullptr) { }
	ListNode(int x) : val(x), next(nullptr){ }
	ListNode(int x, ListNode* next) : val(x), next(next){ } 
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */
class MyLinkedList {
public:
    MyLinkedList();
	~MyLinkedList();

    int get(int index);
    void addAtHead(int val);
    void addAtTail(int val);
    void addAtIndex(int index, int val);
	void deleteAtIndex(int index);
	void printList();

private:
	ListNode* dummyHead;
	size_t size = 0;
};

class ListTest
{
public:
	ListNode* removeElements(ListNode* head, int val);
	ListNode* reverseList(ListNode* head);
};


/*******************************************************************************
 *      file name: desing_linked_list.cpp                                               
 *         author: Hui Chen. (c) 2018                             
 *           mail: chenhui13@baidu.com                                        
 *   created time: 2018/09/21-23:00:07                              
 *  modified time: 2018/09/21-23:00:07                              
 *******************************************************************************/
#include <iostream>
using namespace std;
struct Node
{
	int   val;
	Node* next;
};

class MyLinkedList {
public:
    /** Initialize your data structure here. */
    MyLinkedList() {
		_head = NULL;
		_len = 0;
    }
    
    /** Get the value of the index-th node in the linked list. If the index is invalid, return -1. */
    int get(int index) {
		if (index > _len - 1) return -1;
		Node* ptr = _head;
		for (int i = 0; i < index; i++)
		{
			ptr = ptr->next;
		}
		return ptr->val;
    }
    
    /** Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list. */
    void addAtHead(int val) {
		Node* ptr = new Node;
		ptr->val = val;
		ptr->next = _head;
		_head = ptr;
		_len++;
    }
    
    /** Append a node of value val to the last element of the linked list. */
    void addAtTail(int val) {
		Node* ptr = new Node;
		ptr->val = val;
		ptr->next = NULL;
        Node* pp = _head;
        if (!pp)
        {
            _head = ptr;
            _len++;
            return;
        }
        while (pp->next)
            pp = pp->next;
        pp->next = ptr;
		_len++;
    }
    
    /** Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted. */
    void addAtIndex(int index, int val) {
		if (index > _len) return;
		if (index ==0 ) 
		{
			addAtHead(val);
			return;
		}
		if (index == _len ) 
		{
			addAtTail(val);
			return;
		}
		Node* ptr = _head;
		for (int i = 0; i < index - 1; i++)
		{
			ptr = ptr->next;
		}
		Node* newptr = new Node;
		newptr->val = val;
		Node* temp = ptr->next;
		ptr->next = newptr;
		newptr->next = temp;
		_len++;
    }
    
    /** Delete the index-th node in the linked list, if the index is valid. */
    void deleteAtIndex(int index) {
		if (index > _len - 1) return;
		if (index == 0)
		{
			Node* ptr = _head;
			_head = _head->next;
			delete ptr;
			_len--;
			return;
		}
		Node* ptr = _head;
		for (int i = 0; i < index - 1; i++)
		{
			ptr = ptr->next;
		}
		Node* temp = ptr->next;
		ptr->next = temp->next;
		delete temp;
		_len--;
    }
private:
	Node* _head;
	int _len;
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList obj = new MyLinkedList();
 * int param_1 = obj.get(index);
 * obj.addAtHead(val);
 * obj.addAtTail(val);
 * obj.addAtIndex(index,val);
 * obj.deleteAtIndex(index);
 */
int main()
{
    /*
	MyLinkedList obj;
	obj.addAtHead(1);
	obj.addAtTail(3);
	obj.addAtIndex(1,2);
	int param_1 = obj.get(1);
    cout<<"get(1)"<<param_1<<endl;
	obj.deleteAtIndex(1);
	int param_2 = obj.get(1);
    cout<<"get(1)"<<param_2<<endl;
    */
	MyLinkedList obj;
	obj.addAtHead(1);
	obj.addAtIndex(1,2);
	int param_1 = obj.get(1);
    cout<<"get(1)"<<param_1<<endl;
	param_1 = obj.get(0);
    cout<<"get(0)"<<param_1<<endl;
	param_1 = obj.get(2);
    cout<<"get(2)"<<param_1<<endl;

}


/*******************************************************************************
 *      file name: desing_linked_list.cpp                                               
 *         author: Hui Chen. (c) 2018                             
 *           mail: chenhui13@baidu.com                                        
 *   created time: 2018/09/21-23:00:07                              
 *  modified time: 2018/09/21-23:00:07                              
 *******************************************************************************/
#include <iostream>
using namespace std;
struct Node {
    Node(int v) {
        val = v;
        next = nullptr;
    }
    int val;
    Node* next;
};

class MyLinkedList {
public:
    /** Initialize your data structure here. */
    MyLinkedList() {
        head = tail = nullptr;
        size = 0;
    }
    
    /** Get the value of the index-th node in the linked list. If the index is invalid, return -1. */
    int get(int index) {
        if (index >= size || index < 0) return -1;
        Node *p = find_node(index);
        return p->val;
    }
    
    /** Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list. */
    void addAtHead(int val) {
        Node *p = new Node(val);
        if (head)
            p->next = head;
        else
            tail = p;
        head = p;
        ++size;
    }
    
    /** Append a node of value val to the last element of the linked list. */
    void addAtTail(int val) {
        Node *p = new Node(val);
        if (tail)
            tail->next = p;
        else
            head = p;
        tail = p;
        ++size;        
    }
    
    Node* find_node(int index, Node**pre = nullptr)
    {
        int cnt = 0;
        Node *p = head;
        if (pre)
            *pre = head;
        while (cnt < index )//&& p->next
        {
            if (pre)
                *pre = p;
            p = p->next;
            ++cnt;
        } 
        return p;
    }
    
    /** Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted. */
    void addAtIndex(int index, int val) {
        if (index > size || index < 0) return;
        Node *node = new Node(val);
        Node *pre = nullptr;
        Node *p = find_node(index, &pre);

        node->next = p;
        if (pre == p) //head
            head = node;
        else
            pre->next = node;
        
        if (index == size) tail = node;
        ++size;
    }
    
    /** Delete the index-th node in the linked list, if the index is valid. */
    void deleteAtIndex(int index) {
        if (index >= size || index < 0) return;
        int cnt = 0;
        Node *pre = nullptr;
        Node *p = find_node(index, &pre);          
        
        Node* tmp = p;
        if (p == head)
            head = p->next;
        else
            pre->next = p->next;
        
        if (p==tail)
            tail = pre;
        --size;
		delete temp;
        
    }
private:
    Node *head;
    Node *tail;
    int size;
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
	obj.addAtIndex(0,10);
	obj.addAtIndex(0,20);
	obj.addAtIndex(1,30);
    cout<<"get(4)"<<obj.get(0)<<endl;

	/*
	   ["addAtIndex","addAtIndex","addAtIndex","get"]
	   [[0,10],			[0,20],		[1,30],		[0]]
*/

}


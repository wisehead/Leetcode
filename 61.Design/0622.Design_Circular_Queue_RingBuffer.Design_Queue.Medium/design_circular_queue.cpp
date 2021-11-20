/*******************************************************************************
 *      file name: design_circular_queue.cpp                                               
 *         author: Hui Chen. (c) 2020                             
 *           mail: chenhui13@baidu.com                                        
 *   created time: 2020/09/24-11:21:59                              
 *  modified time: 2020/09/24-11:21:59                              
 *******************************************************************************/
#include <iostream>
using namespace std;
struct Node {
    Node() {
        val = 0;
        next = nullptr;
    }    
    Node(int v) {
        val = v;
        next = nullptr;
    }
    
    ~Node(){
        if (next)
        {
            delete next;
            next = nullptr;
        }
    }
    int val;
    Node* next;
};

class MyCircularQueue {
public:
    /** Initialize your data structure here. Set the size of the queue to be k. */
    MyCircularQueue(int k) {
        max_size = k;
        size = 0;
        Node *p = new Node();
        head = p;
        tail = p;
        p->next = p;
        for (int i = 1; i < k; i++)
        {
            Node *p = new Node();
            p->next = tail->next;
            tail->next = p;
            tail = p;
        }
    }
    
    /** Insert an element into the circular queue. Return true if the operation is successful. */
    bool enQueue(int value) {
        if (isFull()) return false;
        if (size == 0) {
            head->val = value;
        } else {
            head = head->next;
            head->val = value;
        }
        size++;
        return true;
    }
    
    /** Delete an element from the circular queue. Return true if the operation is successful. */
    bool deQueue() {
        if (isEmpty()) return false;
        size--;
        if (size != 0)
            tail = tail->next;
        
        return true;
    }
    
    /** Get the front item from the queue. */
    int Front() {
        if (!isEmpty()) 
        {
            return tail->next->val;
        }
        return -1;
    }
    
    /** Get the last item from the queue. */
    int Rear() {
        if (!isEmpty())
            return head->val;
        return -1;
    }
    
    /** Checks whether the circular queue is empty or not. */
    bool isEmpty() {
        return (size == 0);
    }
    
    /** Checks whether the circular queue is full or not. */
    bool isFull() {
        return size == max_size;
    }
private:
    Node* head;//head->next,第一个可写的地方。head本身是busy_tail。
    Node* tail;//最后一个可写地方，tail->next，本身是busy_head。
    int size;
    int max_size;
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */
int main()
{}

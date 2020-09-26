/*******************************************************************************
 *      file name: design_circular_deque_ringbuf.cpp                                               
 *         author: Hui Chen. (c) 2020                             
 *           mail: chenhui13@baidu.com                                        
 *   created time: 2020/09/26-09:38:05                              
 *  modified time: 2020/09/26-09:38:05                              
 *******************************************************************************/
#include <iostream>
#include <vector>
using namespace std;
class MyCircularDeque {
public:
    /** Initialize your data structure here. Set the size of the deque to be k. */
    MyCircularDeque(int k) {
        data.resize(k);
        head = tail = 0;
        reset = true;
    }
    
    /** Adds an item at the front of Deque. Return true if the operation is successful. */
    bool insertFront(int value) {
        //cout<<"insertFront:"<<value<<endl;
        if (isFull()) return false;
        head = (head - 1 + data.size())% data.size();
        data[head] = value;
        if (reset) reset = false;
        return true;
    }
    
    /** Adds an item at the rear of Deque. Return true if the operation is successful. */
    bool insertLast(int value) {
        //cout<<"insertLast:"<<value<<endl;
        if (isFull()) return false;
        data[tail] = value;
        tail = (tail + 1) % data.size();
        if (reset) reset = false;
        return true;        
    }
    
    /** Deletes an item from the front of Deque. Return true if the operation is successful. */
    bool deleteFront() {
        if (isEmpty()) return false;
        head = (head + 1)%data.size();
        if (head == tail) reset = true;
        return true;
    }
    
    /** Deletes an item from the rear of Deque. Return true if the operation is successful. */
    bool deleteLast() {
        if (isEmpty()) return false;
        tail = (tail -1 + data.size())%data.size();
        if (head == tail) reset = true;
        return true;        
    }
    
    /** Get the front item from the deque. */
    int getFront() {
        if (isEmpty()) return -1;
        return data[head];
    }
    
    /** Get the last item from the deque. */
    int getRear() {
        if (isEmpty()) return -1;
        int x = (tail - 1 + data.size()) % data.size();
        return data[x];
    }
    
    /** Checks whether the circular deque is empty or not. */
    bool isEmpty() {
        return (head == tail && reset);
    }
    
    /** Checks whether the circular deque is full or not. */
    bool isFull() {
        //cout<<"head:"<<head<<"  tail:"<<tail<<" reset:"<<reset<<endl;
        return (head == tail && !reset);
    }
private:
    vector<int> data;
    int head;
    int tail;
    bool reset;
};

/**
 * Your MyCircularDeque object will be instantiated and called as such:
 * MyCircularDeque* obj = new MyCircularDeque(k);
 * bool param_1 = obj->insertFront(value);
 * bool param_2 = obj->insertLast(value);
 * bool param_3 = obj->deleteFront();
 * bool param_4 = obj->deleteLast();
 * int param_5 = obj->getFront();
 * int param_6 = obj->getRear();
 * bool param_7 = obj->isEmpty();
 * bool param_8 = obj->isFull();
 */
int main()
{}

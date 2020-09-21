/*******************************************************************************
 *      file name: queue_with_stack.cpp                                               
 *         author: Hui Chen. (c) 17                             
 *           mail: chenhui13@baidu.com                                        
 *   created time: 17/12/28-12:12                                    
 *  modified time: 17/12/28-12:12                                    
 *******************************************************************************/
#include <iostream>
#include <stack>
#include <limits.h>
using namespace std;

class MyQueue {
public:
    /** Initialize your data structure here. */
    MyQueue() {
        
    }
    
    /** Push element x to the back of queue. */
    void push(int x) {
        s1.push(x);
    }
    
    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        int x = INT_MIN;
        if (!s2.empty())
        {
            x = s2.top();
            s2.pop();
            return x;
        }
        
        while (!s1.empty())
        {
            x = s1.top();
            s1.pop();
            s2.push(x);
        }
        x = s2.top();
        s2.pop();
        return x;
    }
    
    /** Get the front element. */
    int peek() {
        int x = INT_MIN;
        if (!s2.empty())
            return s2.top();
        while (!s1.empty())
        {
            x = s1.top();
            s1.pop();
            s2.push(x);
        }
        return s2.top();
    }
    
    /** Returns whether the queue is empty. */
    bool empty() {
        return s1.empty() && s2.empty();
    }
private:
    stack<int> s1;
    stack<int> s2;
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue obj = new MyQueue();
 * obj.push(x);
 * int param_2 = obj.pop();
 * int param_3 = obj.peek();
 * bool param_4 = obj.empty();
 */
int main()
{}

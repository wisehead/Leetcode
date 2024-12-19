/*******************************************************************************
 *      file name: stack_with_2_queues.cpp                                               
 *         author: Hui Chen. (c) 2020                             
 *           mail: chenhui13@baidu.com                                        
 *   created time: 2020/09/21-15:04:47                              
 *  modified time: 2020/09/21-15:04:47                              
 *******************************************************************************/
#include <iostream>
#include <queue>
#include <limits.h>
using namespace std;
class MyStack {
public:
    /** Initialize your data structure here. */
    MyStack() {
        flag = true;
    }
    
    /** Push element x onto stack. */
    void push(int x) {
        if (flag)
            q1.push(x);
        else
            q2.push(x);
    }
    
    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        if (flag)
        {
            int size = q1.size();
            if (size == 0) return INT_MIN;
            int x = INT_MIN;
            while(!q1.empty() && q1.size() > 1)
            {
                x = q1.front();
                q1.pop();
                q2.push(x);
            }
            x = q1.front();
            q1.pop();
            flag = false;
            return x;

        }
        else
        {
            int size = q2.size();
            if (size == 0) return INT_MIN;
            int x = INT_MIN;
            while(!q2.empty() && q2.size() > 1)
            {
                x = q2.front();
                q2.pop();
                q1.push(x);
            }
            x = q2.front();
            q2.pop();   
            flag = true;
            return x;
        }
    }
    
    /** Get the top element. */
    int top() {
        if (flag)
            return q1.back();
        return q2.back();
    }
    
    /** Returns whether the stack is empty. */
    bool empty() {
        if (flag)
            return q1.empty();
        return q2.empty();
    }
private:
    queue<int> q1;
    queue<int> q2;
    bool flag;
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */
int main()
{}

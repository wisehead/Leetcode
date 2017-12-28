/*******************************************************************************
 *      file name: queue_with_stack.cpp                                               
 *         author: Hui Chen. (c) 17                             
 *           mail: chenhui13@baidu.com                                        
 *   created time: 17/12/28-12:12                                    
 *  modified time: 17/12/28-12:12                                    
 *******************************************************************************/
#include <iostream>
#include <stack>
using namespace std;
class MyQueue {
public:
    /** Initialize your data structure here. */
    MyQueue() {
		_front = 0;
    }
    
    /** Push element x to the back of queue. */
    void push(int x) {
        if (empty())
            _front = x;
       _stack1.push(x); 
    }
    
    /** Removes the element from in front of queue and returns that element. */
    int pop() {
		if (empty())
			return 1;
		int temp = 0;
        int pop = 0;
		while (!_stack1.empty())
		{
			temp = _stack1.top();
			_stack2.push(temp);
			_stack1.pop();
		}
        pop = _stack2.top();
		_stack2.pop();
		if (!_stack2.empty())
			_front = _stack2.top();
		while (!_stack2.empty())
		{
			temp = _stack2.top();
			_stack1.push(temp);
			_stack2.pop();
		}
		return pop;
    }
    
    /** Get the front element. */
    int peek() {
		if (empty())
			return 0;
		return _front;
    }
    
    /** Returns whether the queue is empty. */
    bool empty() {
       return _stack1.empty(); 
    }
private:
	stack<int> _stack1;
	stack<int> _stack2;
	int _front;
};

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

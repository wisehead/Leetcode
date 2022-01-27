/*******************************************************************************
 *      file name: stack_with_queue.cpp                                               
 *         author: Hui Chen. (c) 17                             
 *           mail: chenhui13@baidu.com                                        
 *   created time: 17/12/25-12:12                                    
 *  modified time: 17/12/25-12:12                                    
 *******************************************************************************/
#include <iostream>
#include <queue>
using namespace std;
class MyStack {
public:
    /** Initialize your data structure here. */
    MyStack() {
		_top = 0;
    }
    	
    /** Push element x onto stack. */
    void push(int x) {
		_m_q.push(x);
		_top = x;
    }
    
    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        int pop = 0;
		while (_m_q.size() > 1)
		{
			int temp = _m_q.front();
			_m_q.pop();
			_m_q2.push(temp);
		}
		if(_m_q.size() == 1)
        {
            pop = _m_q.front();
            _m_q.pop();
        }
		while(!_m_q2.empty())
		{
			int temp = _m_q2.front();
			if(_m_q2.size() == 1)
				_top = temp;
		    _m_q2.pop();	
			_m_q.push(temp);
		}
		return pop;
    }
    
    /** Get the top element. */
    int top() {
		if(empty())
			return 0;
		return _top;
    }
    
    /** Returns whether the stack is empty. */
    bool empty() {
		return _m_q.empty();
    }
private:
	queue<int> _m_q;
	queue<int> _m_q2;
	int _top;
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack obj = new MyStack();
 * obj.push(x);
 * int param_2 = obj.pop();
 * int param_3 = obj.top();
 * bool param_4 = obj.empty();
 */
int main()
{}

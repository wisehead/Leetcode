/*******************************************************************************
 *      file name: min_stack.cpp                                               
 *         author: hui chen. (c) 17                             
 *           mail: chenhui13@baidu.com                                        
 *   created time: 17/11/23-11:11                                    
 * modified time: 17/11/23-11:11                                    
 *******************************************************************************/
#include <iostream>
#include <vector>
#include <limits.h>
using namespace std;
/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack obj = new MinStack();
 * obj.push(x);
 * obj.pop();
 * int param_3 = obj.top();
 * int param_4 = obj.getMin();
 */
class MinStack {
public:
    /** initialize your data structure here. */
    MinStack() {
        min_v = INT_MAX;
    }
    
    void push(int x) {
        vec.push_back(x);
        if (x < min_v)
            min_v = x;
    }
    
    void pop() {
        int x = top();
        vec.pop_back();
        if (x == min_v)
        {
            min_v = INT_MAX;
            for(auto x:vec)
            {
                if (x < min_v)
                    min_v = x;
            }
        }
    }
    
    int top() {
        if(vec.size() > 0)
            return vec[vec.size() - 1];
        return INT_MIN;
    }
    
    int getMin() {
        return min_v;
    }
private:
    vector<int> vec;
    int min_v;
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */

int main()
{
	MinStack minStack;
	minStack.push(-2);
	minStack.push(0);
	minStack.push(-3);
	int x = minStack.getMin();   //--> Returns -3.
	cout <<"x is:"<<x<<endl;
	minStack.pop();
	x = minStack.top();      //--> Returns 0.
	cout <<"x is:"<<x<<endl;
	x = minStack.getMin();   //--> Returns -2.
	cout <<"x is:"<<x<<endl;
}

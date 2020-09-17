/*******************************************************************************
 *      file name: min_stack.cpp                                               
 *         author: hui chen. (c) 17                             
 *           mail: chenhui13@baidu.com                                        
 *   created time: 17/11/23-11:11                                    
 * modified time: 17/11/23-11:11                                    
 *******************************************************************************/
#include <iostream>
#include <vector>
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
		min_pos = 0;
    }
    
    void push(int x) {
		int size = vec.size();
		vec.push_back(x);
		if(x < vec[min_pos])
			min_pos = size;
    }
    
    void pop() {
        int size = vec.size(); 
		if (size > 0)
			vec.pop_back();
		if (min_pos == size - 1 && size > 1)
		{
			vector<int>::iterator it;
			int i = 0;
			min_pos = 0;
			int min_val = vec[0];
			for (it = vec.begin(); it!= vec.end(); it++, i++)
			{
				if(*it < min_val)
				{
					min_val = *it;
					min_pos = i;
				}
			}
				
		}
    }
    
    int top() {
		if(!vec.empty())
			return vec.back();
		return -1;
    }
    
    int getMin() {
       if(!vec.empty()) 
		   return vec[min_pos];
	   return -1;
    }
private:
    int min_pos;
    vector<int> vec;
};

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

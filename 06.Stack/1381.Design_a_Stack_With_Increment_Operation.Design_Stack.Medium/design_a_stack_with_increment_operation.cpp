/*******************************************************************************
 *      file name: design_a_stack_with_increment_operation.cpp                                               
 *         author: Hui Chen. (c) 2020                             
 *           mail: chenhui13@baidu.com                                        
 *   created time: 2020/10/02-17:16:25                              
 *  modified time: 2020/10/02-17:16:25                              
 *******************************************************************************/
#include <iostream>
#include <vector>
using namespace std;
class CustomStack {
public:
    CustomStack(int maxSize) {
        data.resize(maxSize);
        this->maxSize = maxSize;
        size = 0;
    }
    
    void push(int x) {
        if (size < maxSize) 
        {
            data[size] = x;
            size++;
        }
    }
    
    int pop() {
        if (size > 0) 
        {
            int x = data[size-1];
            size--;
            return x;
        }
        return -1;
    }
    
    void increment(int k, int val) {
        int n = min(k, size);
        for (int i = 0; i < n; i++)
            data[i]+= val;
    }
private:
    vector<int> data;
    int maxSize;
    int size;
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */
int main()
{}

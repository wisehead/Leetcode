/*******************************************************************************
 *      file name: flatten_nested_list_iterator.cpp                                               
 *         author: Hui Chen. (c) 2020                             
 *           mail: chenhui13@baidu.com                                        
 *   created time: 2020/10/09-14:34:05                              
 *  modified time: 2020/10/09-14:34:05                              
 *******************************************************************************/
#include <iostream>
using namespace std;

/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */

class NestedIterator {
public:
    NestedIterator(vector<NestedInteger> &nestedList) {
        while (!nestedList.empty()) {
            st.push(nestedList.back());
            nestedList.pop_back();
        }    
    }
    
    int next() {
        if (hasNext()) {
            int x = st.top().getInteger();
            st.pop();
            return x;
        }
        return -1;
    }
    
    bool hasNext() {
        while (!st.empty()) {
            NestedInteger x = st.top();
            if (x.isInteger()) return true;       
            st.pop();
            vector<NestedInteger> v = x.getList();
            while (!v.empty()) {
                st.push(v.back());
                v.pop_back();
            }             
        }
        return false;
    }
private:
    stack<NestedInteger> st;
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */
/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */
int main()
{}

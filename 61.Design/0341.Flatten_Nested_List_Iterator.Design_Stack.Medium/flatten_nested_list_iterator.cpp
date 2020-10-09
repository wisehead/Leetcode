/*******************************************************************************
 *      file name: flatten_nested_list_iterator.cpp                                               
 *         author: Hui Chen. (c) 2020                             
 *           mail: chenhui13@baidu.com                                        
 *   created time: 2020/10/09-14:34:05                              
 *  modified time: 2020/10/09-14:34:05                              
 *******************************************************************************/
#include <iostream>
using namespace std;

iass NestedInteger {
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
        vec = nestedList;
        flag = false;
    }
    
    int next() {
        if (hasNext()) {
            flag = false;
            return temp;
        }
        return -1;
    }
    
    bool hasNext() {
        if (flag) return true;
        while (!st.empty() || !vec.empty())
        {
            NestedInteger x;
            if (!st.empty()) {
                x = st.top();
                st.pop();
            } else {
                x = vec[0];
                vec.erase(vec.begin());                
            }        
            if (x.isInteger()) 
            {
                temp = x.getInteger();
                flag = true;
                return true;
            }
            vector<NestedInteger> v = x.getList();
            while (!v.empty()) {
                st.push(v.back());
                v.pop_back();
            }             
        }
        return false;
    }
private:
    vector<NestedInteger> vec;
    stack<NestedInteger> st;
    int temp;
    bool flag;
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */t main()
{}

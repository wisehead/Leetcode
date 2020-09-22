/*******************************************************************************
 *      file name: insert_delete_getrandom_O1.cpp                                               
 *         author: Hui Chen. (c) 2019                             
 *           mail: chenhui13@baidu.com                                        
 *   created time: 2019/04/18-19:59:03                              
 *  modified time: 2019/04/18-19:59:03                              
 *******************************************************************************/
#include <iostream>
#include <set>
#include <vector>
using namespace std;
class RandomizedSet {
public:
    /** Initialize your data structure here. */
    RandomizedSet() {
    }
    
    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
        if (s1.count(val))
            return false;
        s1.insert(val);
        return true;
    }
    
    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
        if (!s1.count(val))
            return false;
        s1.erase(val);
        return true;
    }
    
    /** Get a random element from the set. */
    int getRandom() {
        set<int>::iterator it = s1.begin();
        int r = rand() % s1.size();
        vector<int> vec(s1.begin(), s1.end());
        return vec[r];
    }
private:
    set<int> s1;
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */
int main()
{}

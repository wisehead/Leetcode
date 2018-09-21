/*******************************************************************************
 *      file name: design_hashset.cpp                                               
 *         author: Hui Chen. (c) 2018                             
 *           mail: chenhui13@baidu.com                                        
 *   created time: 2018/09/21-22:13:09                              
 *  modified time: 2018/09/21-22:13:09                              
 *******************************************************************************/
#include <iostream>
#include <map>
using namespace std;
class MyHashSet {
public:
    /** Initialize your data structure here. */
    MyHashSet() {
    }
    
    void add(int key) {
		_hashtable[key] = 1;
    }
    
    void remove(int key) {
		_hashtable.erase(key);
    }
    
    /** Returns true if this set contains the specified element */
    bool contains(int key) {
		map<int, int>::iterator it;
		it = _hashtable.find(key);
		return (it != _hashtable.end());
    }
private:
	map<int, int> _hashtable;
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet obj = new MyHashSet();
 * obj.add(key);
 * obj.remove(key);
 * bool param_3 = obj.contains(key);
 */
int main()
{}

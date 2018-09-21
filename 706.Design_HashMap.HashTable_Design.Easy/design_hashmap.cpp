/*******************************************************************************
 *      file name: design_hashmap.cpp                                               
 *         author: Hui Chen. (c) 2018                             
 *           mail: chenhui13@baidu.com                                        
 *   created time: 2018/09/21-22:31:06                              
 *  modified time: 2018/09/21-22:31:06                              
 *******************************************************************************/
#include <iostream>
#include <map>
using namespace std;
class MyHashMap {
public:
    /** Initialize your data structure here. */
    MyHashMap() {
    }
    
    /** value will always be non-negative. */
    void put(int key, int value) {
		_ht[key] = value;
    }
    
    /** Returns the value to which the specified key is mapped, or -1 if this map contains no mapping for the key */
    int get(int key) {
		map<int, int>::iterator it;
		it = _ht.find(key);
		if (it != _ht.end())
			return it->second;
		return -1;
    }
    
    /** Removes the mapping of the specified value key if this map contains a mapping for the key */
    void remove(int key) {
		_ht.erase(key);
    }
private:
	map<int, int> _ht;
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap obj = new MyHashMap();
 * obj.put(key,value);
 * int param_2 = obj.get(key);
 * obj.remove(key);
 */
int main()
{}

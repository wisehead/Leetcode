/*******************************************************************************
 *      file name: lru_cache_list.cpp                                               
 *         author: Hui Chen. (c) 2020                             
 *           mail: chenhui13@baidu.com                                        
 *   created time: 2020/09/22-11:15:41                              
 *  modified time: 2020/09/22-11:15:41                              
 *******************************************************************************/
#include <iostream>
#include <list>
using namespace std;
struct Node
{
    Node() {
        key = 0;
        val = 0;
    }
    Node(int k, int v) {
        key = k;
        val = v;
    }    
    int key;
    int val;
};

class LRUCache {
public:
    LRUCache(int capacity) {
        lru_size = capacity;
    }
    
    int get(int key) {
        list<Node>::iterator iter;
        Node n;
        for(iter = lru.begin(); iter != lru.end(); iter++)
        {
            if (iter->key == key) {
                n.key = iter->key;
                n.val = iter->val;
                lru.erase(iter);
                lru.push_back(n);
                return n.val;
            }
        }
        return -1;
    }
    
    void put(int key, int value) {
        list<Node>::iterator iter;
        Node n(key, value);
        for(iter = lru.begin(); iter != lru.end(); iter++)
        {
            if (iter->key == key) {
                lru.erase(iter);
                lru.push_back(n);
                return;
            }
        }        
        
        if (lru.size() >= lru_size)
        {
            lru.pop_front();
        }
        lru.push_back(n);
    }

private:
    list<Node> lru;
    int lru_size;
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
int main()
{}

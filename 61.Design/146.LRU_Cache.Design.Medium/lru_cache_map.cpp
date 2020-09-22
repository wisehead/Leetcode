/*******************************************************************************
 *      file name: lru_cache_map.cpp                                               
 *         author: Hui Chen. (c) 2020                             
 *           mail: chenhui13@baidu.com                                        
 *   created time: 2020/09/22-10:47:54                              
 *  modified time: 2020/09/22-10:47:54                              
 *******************************************************************************/
#include <iostream>
#include <set>
#include <map>
using namespace std;
struct Node
{
    Node(int v, int c) {
        val = v;
        cnt = c;
    }
    int val;
    int cnt;
};

class LRUCache {
public:
    LRUCache(int capacity) {
        lru_size = capacity;
    }
    
    int get(int key) {
        map<int, Node>::iterator iter;
        iter = lru.find(key);
        if(iter != lru.end())
        {
            cout<<"iter->second.cnt:"<<iter->second.cnt<<endl;
            cout<<"iter->second.val:"<<iter->second.val<<endl;
            iter->second.cnt++;
            return iter->second.val;
        }
        return -1;
    }
    
    void put(int key, int value) {
        map<int, Node>::iterator iter;
        iter = lru.find(key);
        if(iter != lru.end())
        {
            iter->second.cnt = 0;
            iter->second.val = value;
        }
        else
        {
            
            if (lru.size() >= lru_size)
            {
                while (coldset.empty())
                {
                    map<int, Node>::iterator iter;
                    for(iter = lru.begin(); iter != lru.end(); iter++)
                    {
                        if (--iter->second.cnt == 0)
                        {
                            coldset.insert(iter->first);
                            break;
                        }
                    }
                }                

                set<int>::iterator siter = coldset.begin();
                int x = *siter;
                lru.erase(x);
                coldset.erase(x);
                    
            }

            lru.insert(make_pair(key, Node(value,0)));
        }
    }

private:
    map<int, Node> lru;
    int lru_size;
    set<int> coldset;
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
int main()
{}

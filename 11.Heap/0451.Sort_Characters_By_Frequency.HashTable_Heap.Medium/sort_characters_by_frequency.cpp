/*******************************************************************************
 *      file name: sort_characters_by_frequency.cpp                                               
 *         author: Hui Chen. (c) 2020                             
 *           mail: chenhui13@baidu.com                                        
 *   created time: 2020/10/03-13:18:16                              
 *  modified time: 2020/10/03-13:18:16                              
 *******************************************************************************/
#include <iostream>
#include <queue>
#include <map>
using namespace std;
struct Node {
    int cnt;
    char c;
    Node(int frequency, char charactor) :cnt(frequency), c(charactor){}
};

struct cmp
{
    bool operator()(Node a,Node b)
    {
        return a.cnt<b.cnt;//<为大顶堆，>为小顶堆
    }
};

class Solution {
public:
    string frequencySort(string s) {
        string res;
        map<char,int> ht;
        priority_queue<Node,vector<Node>,cmp> pq;
        for (char e: s) {
            if (ht.count(e)) {
                ht[e]++;
            } else {
                ht[e] = 1;
            }
        }
        
        map<char,int>::iterator it;
        for (it = ht.begin(); it != ht.end(); it++) {
            pq.push(Node(it->second, it->first));
        }
        
        while (!pq.empty()) {
            Node node = pq.top(); pq.pop();
            //for (int i = 0; i < node.cnt; i++)
            res.append(node.cnt, node.c);
        }
        return res;
    }
};
int main()
{}

/*******************************************************************************
 *      file name: unique_number_of_occurrences.cpp                                               
 *         author: Hui Chen. (c) 2020                             
 *           mail: chenhui13@baidu.com                                        
 *   created time: 2020/11/16-09:14:29                              
 *  modified time: 2020/11/16-09:14:29                              
 *******************************************************************************/
#include <iostream>
#include <vector>
#include <unordered_map>
#include <set>
using namespace std;
class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int, int> ht;
        for (auto e : arr) {
            ht[e]++;
        }
        unordered_map<int, int>::iterator it;
        set<int> s;
        for (it = ht.begin(); it != ht.end(); it++) {
            if (s.count(it->second)) return false;
            s.insert(it->second);
        }
        return true;
    }
};
int main()
{}

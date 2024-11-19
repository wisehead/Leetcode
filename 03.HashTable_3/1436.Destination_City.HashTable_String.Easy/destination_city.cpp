/*******************************************************************************
 *      file name: destination_city.cpp                                               
 *         author: Hui Chen. (c) 2021                             
 *           mail: alex.chenhui@gmail.com                                        
 *   created time: 2021/09/27-10:43:45                              
 *  modified time: 2021/09/27-10:43:45                              
 *******************************************************************************/
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
class Solution {
public:
    string destCity(vector<vector<string>>& paths) {
        unordered_map<string, string> mp;
        for (auto v : paths) {
            mp[v[0]] = v[1];
        }
        unordered_map<string, string>::iterator it = mp.begin();
        string str = it->first;
        while (mp.count(str)) 
            str = mp[str];
        return str;
    }
};
int main()
{}

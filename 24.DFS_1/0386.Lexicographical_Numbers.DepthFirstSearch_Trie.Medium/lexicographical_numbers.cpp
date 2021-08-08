/*******************************************************************************
 *      file name: lexicographical_numbers.cpp                                               
 *         author: Hui Chen. (c) 2021                             
 *           mail: alex.chenhui@gmail.com                                        
 *   created time: 2021/08/08-11:05:01                              
 *  modified time: 2021/08/08-11:05:01                              
 *******************************************************************************/
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    vector<int> res;
    void dfs(string s, int n) {
        if (s.length() > 0 && stoi(s) > n) return;
        for (int i = 0; i < 10; i++) {
            string temp = s+to_string(i);
            int x = stoi(temp);
            if (x == 0) continue;
            if (x > n) break;
            res.push_back(x);
            dfs(temp, n);
        }
    }
    vector<int> lexicalOrder(int n) {
        dfs("", n);
        return res;
    }
};
int main()
{}

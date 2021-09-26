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
    void dfs(int current, int n) {
        for (int i = 0; i < 10; i++) {
            int x = current*10+i;
            if (x == 0) continue;
            if (x > n) break;
            res.push_back(x);
            dfs(x, n);
        }
    }
    vector<int> lexicalOrder(int n) {
        dfs(0, n);
        return res;
    }
};
int main()
{}

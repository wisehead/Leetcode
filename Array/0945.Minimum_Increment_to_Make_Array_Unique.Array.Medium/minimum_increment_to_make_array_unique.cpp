/*******************************************************************************
 *      file name: minimum_increment_to_make_array_unique.cpp                                               
 *         author: Hui Chen. (c) 2019                             
 *           mail: chenhui13@baidu.com                                        
 *   created time: 2019/07/02-19:07:36                              
 *  modified time: 2019/07/02-19:07:36                              
 *******************************************************************************/
#include <iostream>
#include <vector>
#include <map>
#include <set>
using namespace std;
class Solution {
public:
    int minIncrementForUnique(vector<int>& A) {
        sort(A.begin(), A.end());
        int res = 0, need = 0;
        for (int a: A) {
            res += max(need - a, 0);
            need = max(a, need)+1;
        }
        return res;
    }
};
int main()
{}

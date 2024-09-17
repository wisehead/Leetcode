/*******************************************************************************
 *      file name: array_nesting.cpp                                               
 *         author: Hui Chen. (c) 2019                             
 *           mail: chenhui13@baidu.com                                        
 *   created time: 2019/04/26-17:15:36                              
 *  modified time: 2019/04/26-17:15:36                              
 *******************************************************************************/
#include <iostream>
#include <vector>
#include <set>
using namespace std;
class Solution {
public:
    int arrayNesting(vector<int>& a) {
        size_t maxsize = 0;
        for (int i = 0; i < a.size(); i++) {
            size_t size = 0;
            for (int k = i; a[k] >= 0; size++) {
                int ak = a[k];
                a[k] = -1; // mark a[k] as visited;
                k = ak;
            }
            maxsize = max(maxsize, size);
        }

        return maxsize;
    }
};
int main()
{}

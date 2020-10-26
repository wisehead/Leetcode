/*******************************************************************************
 *      file name: gray_code.cpp                                               
 *         author: Hui Chen. (c) 2020                             
 *           mail: chenhui13@baidu.com                                        
 *   created time: 2020/10/26-17:34:27                              
 *  modified time: 2020/10/26-17:34:27                              
 *******************************************************************************/
#include <iostream>
#include <vector>
#include <math.h>
using namespace std;
class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> res;
        if (n == 0)
        {
            res.push_back(0);
            return res;
        }
        if (n == 1) {
            res.push_back(0);
            res.push_back(1);
            return res;
        }
        vector<int> vec = grayCode(n-1);
        for (auto e : vec) res.push_back(e);
        for (int i = vec.size() - 1; i >= 0; i--) {
            int x = vec[i];
            x += pow(2.0, n-1);
            res.push_back(x);
        }
        return res;
    }
};
int main()
{}

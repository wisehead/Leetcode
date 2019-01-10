/*******************************************************************************
 *      file name: fair_candy_swap.cpp                                               
 *         author: Hui Chen. (c) 2019                             
 *           mail: chenhui13@baidu.com                                        
 *   created time: 2019/01/10-22:30:44                              
 *  modified time: 2019/01/10-22:30:44                              
 *******************************************************************************/
#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <numeric>

using namespace std;
class Solution {
public:
    vector<int> fairCandySwap(vector<int> A, vector<int> B) {
        vector<int> res;
        int dif = (accumulate(A.begin(), A.end(), 0) - accumulate(B.begin(), B.end(), 0)) / 2;
        unordered_set<int> S(A.begin(), A.end());
        for (int b: B)
            if (S.count(b + dif))
            {
                res.push_back(b+dif);
                res.push_back(b);
                return res; 
            }
    }    
};
int main()
{}

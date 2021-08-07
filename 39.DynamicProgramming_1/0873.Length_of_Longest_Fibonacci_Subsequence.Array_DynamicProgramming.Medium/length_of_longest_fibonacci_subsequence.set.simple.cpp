/*******************************************************************************
 *      file name: length_of_longest_fibonacci_subsequence.cpp                                               
 *         author: Hui Chen. (c) 2019                             
 *           mail: chenhui13@baidu.com                                        
 *   created time: 2019/06/17-10:00:45                              
 *  modified time: 2019/06/17-10:00:45                              
 *******************************************************************************/
#include <iostream>
#include <vector>
#include <unordered_set>
#include <map>
using namespace std;
class Solution {
public:
    int lenLongestFibSubseq(vector<int>& A) {
        unordered_set<int> s(A.begin(), A.end());
        int res = 0;
        for (int i = 0; i < A.size(); ++i) {
            for (int j = i + 1; j < A.size(); ++j) {
                int  a = A[i], b = A[j], l = 2;
                while (s.count(a + b))
                    b = a + b, a = b - a, l++;
                res = max(res, l);
            }
        }
        return res > 2 ? res : 0;
    }
};
int main()
{}

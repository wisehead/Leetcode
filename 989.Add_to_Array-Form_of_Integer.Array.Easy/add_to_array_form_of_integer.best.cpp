/*******************************************************************************
 *      file name: add_to_array_form_of_integer.cpp                                               
 *         author: Hui Chen. (c) 2019                             
 *           mail: chenhui13@baidu.com                                        
 *   created time: 2019/02/20-09:31:53                              
 *  modified time: 2019/02/20-09:31:53                              
 *******************************************************************************/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    vector<int> addToArrayForm(vector<int> A, int K) {
        for (int i = A.size() - 1; i >= 0 && K > 0; --i) {
            A[i] += K;
            K = A[i] / 10;
            A[i] %= 10;
        }
        while (K > 0) {
            A.insert(A.begin(), K % 10);
            K /= 10;
        }
        return A;
    }
};
int main()
{}

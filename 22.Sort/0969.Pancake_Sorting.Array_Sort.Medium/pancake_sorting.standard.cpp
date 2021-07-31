/*******************************************************************************
 *      file name: pancake_sorting.cpp                                               
 *         author: Hui Chen. (c) 2019                             
 *           mail: chenhui13@baidu.com                                        
 *   created time: 2019/07/07-17:14:20                              
 *  modified time: 2019/07/07-17:14:20                              
 *******************************************************************************/
#include <iostream>
#include <vector>
using namespace std;
/*
Explanation
Find the index i of the next maximum number x.
Reverse i + 1 numbers, so that the x will be at A[0]
Reverse x numbers, so that x will be at A[x - 1].
Repeat this process N times.

Update:
Actually, I didn't use the condition permutation of [1,2,..., A.length].
I searched in the descending order of A.

Time Complexity:
O(N^2)
 */
class Solution {
public:
    vector<int> pancakeSort(vector<int> A) {
        vector<int> res;
        int x,i;
        for (x = A.size(); x > 0; --x) {
            for (i = 0; A[i] != x; ++i);
            reverse(A.begin(), A.begin() + i + 1);
            res.push_back(i + 1);
            reverse(A.begin(), A.begin() + x);
            res.push_back(x);
        }
        return res;
    }
};

int main()
{
	Solution sol;
	int arr[] = {3,2,4,1};
	vector<int> vec(arr, arr+4);
	vector<int> ret = sol.pancakeSort(vec);
}










/*******************************************************************************
 *      file name: global_and_local_inversions.cpp                                               
 *         author: Hui Chen. (c) 2019                             
 *           mail: chenhui13@baidu.com                                        
 *   created time: 2019/05/27-10:03:04                              
 *  modified time: 2019/05/27-10:03:04                              
 *******************************************************************************/
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    bool isIdealPermutation(vector<int>& A) {
        int last_maxv = A[0];
		for (int i = 2; i < A.size(); i++)
		{
            last_maxv = max(last_maxv, A[i-2]);
			if (A[i] < last_maxv) return false;
		}
		return true;
    }
};
int main()
{}

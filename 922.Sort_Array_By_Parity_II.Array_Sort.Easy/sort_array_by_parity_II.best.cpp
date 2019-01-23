/*******************************************************************************
 *      file name: sort_array_by_parity_II.cpp                                               
 *         author: Hui Chen. (c) 2019                             
 *           mail: chenhui13@baidu.com                                        
 *   created time: 2019/01/23-14:03:53                              
 *  modified time: 2019/01/23-14:03:53                              
 *******************************************************************************/
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
	vector<int> sortArrayByParityII(vector<int>& A) {
	    for (int i = 0, j = 1; i < A.size(); i += 2, j += 2) {
	        while (i < A.size() && A[i] % 2 == 0) i += 2;
	        while (j < A.size() && A[j] % 2 == 1) j += 2;
	        if (i < A.size()) swap(A[i], A[j]);
	    }
	    return A;
	}
};
int main()
{}

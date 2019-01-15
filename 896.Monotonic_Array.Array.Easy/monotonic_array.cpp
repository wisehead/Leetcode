/*******************************************************************************
 *      file name: monotonic_array.cpp                                               
 *         author: Hui Chen. (c) 2019                             
 *           mail: chenhui13@baidu.com                                        
 *   created time: 2019/01/15-19:24:05                              
 *  modified time: 2019/01/15-19:24:05                              
 *******************************************************************************/
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    bool isMonotonic(vector<int>& A) {
		int size = A.size();
		if (size == 0) return false;
		if (size <= 2) return true;
		int i = 1;
		while (A[i] >= A[i-1] && i < size)
			i++;
		int j = 1;
		while (A[j] <= A[j-1] && j < size)
			j++;
		return (i == size || j == size);
    }
};
int main()
{}

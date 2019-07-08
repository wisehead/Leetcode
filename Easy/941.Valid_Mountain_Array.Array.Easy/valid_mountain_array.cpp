/*******************************************************************************
 *      file name: valid_mountain_array.cpp                                               
 *         author: Hui Chen. (c) 2019                             
 *           mail: chenhui13@baidu.com                                        
 *   created time: 2019/01/30-09:13:01                              
 *  modified time: 2019/01/30-09:13:01                              
 *******************************************************************************/
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    bool validMountainArray(vector<int>& A) {
		int size = A.size();
		int i = 0;
		int j = size - 1;
		while (i < size - 1 && A[i+1] > A[i] )
			i++;

		while (j >= 1 && A[j] <  A[j-1])
			j--;
        
        cout<<"i:"<<i<<"    j:"<<j<<endl;
		return (i == j && i > 0 && j < size - 1);
    }
};
int main()
{}

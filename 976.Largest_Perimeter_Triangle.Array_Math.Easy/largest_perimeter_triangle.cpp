/*******************************************************************************
 *      file name: largest_perimeter_triangle.cpp                                               
 *         author: Hui Chen. (c) 2019                             
 *           mail: chenhui13@baidu.com                                        
 *   created time: 2019/02/14-09:34:53                              
 *  modified time: 2019/02/14-09:34:53                              
 *******************************************************************************/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    int largestPerimeter(vector<int>& A) {
		sort(A.begin(), A.end());
		reverse(A.begin(), A.end());
		for (int i=0; i < A.size() - 2; i++)
		{
			if (A[i+1] + A[i+2] > A[i])
            {
                //cout<<"A["<<i<<"]"<<A[i]<<" A["<<i+1<<"]"<<A[i+1]<<"    A["<<i+2<<"]"<<A[i+2]<<endl;
				return A[i] + A[i+1] + A[i+2];
            }
		}
		return 0;
    }
};
int main()
{}

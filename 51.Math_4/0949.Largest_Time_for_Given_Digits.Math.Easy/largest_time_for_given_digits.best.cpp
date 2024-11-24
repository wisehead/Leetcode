/*******************************************************************************
 *      file name: largest_time_for_given_digits.cpp                                               
 *         author: Hui Chen. (c) 2019                             
 *           mail: chenhui13@baidu.com                                        
 *   created time: 2019/02/02-20:48:57                              
 *  modified time: 2019/02/02-20:48:57                              
 *******************************************************************************/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
	string largestTimeFromDigits(vector<int>& A) {
		sort(begin(A), end(A), greater<int>());
		do 
		{
			cout<<"A[0]:"<<A[0]<<"	A[1]:"<<A[1]<<"	A[2]:"<<A[2]<<"	A[3]:"<<A[3]<<endl;
			if ((A[0] < 2 || (A[0] == 2 && A[1] < 4)) && A[2] < 6) 
			  return to_string(A[0]) + to_string(A[1]) + ":" + to_string(A[2]) + to_string(A[3]);
		}
		while (prev_permutation(begin(A), end(A)));
		return "";
	}
};
int main()
{
	Solution sol;
	int arr[] = {1,2,3,4};
	//int arr[] = {5,5,5,5};
	//int arr[] = {4,2,4,4};
	//int arr[] = {9,0,7,7};
	//int arr[] = {2,0,6,6};
	vector<int> vec(arr, arr+4);
	string res = sol.largestTimeFromDigits(vec);
	cout<<"res:"<<res<<endl;
}

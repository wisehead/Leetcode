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
class Solution {
public:
	void printv(vector<int>& A) {
		for (int e:A)
			cout<<e<<"	";
		cout<<endl;
	}
	int getMax(vector<int>& A, int n) {
		int m = A[0];
		int pos = 0;
		for (int i = 0; i < n; i++)
		{
			if (A[i] > m)
			{
				m = A[i];
				pos = i;
			}
		}
		return pos;
	}
    vector<int> pancakeSort(vector<int>& A) {
		int n = A.size();
		vector<int> ret;
		for (int i = 0; i < n; i++)
		{
			int x = getMax(A, n - i);
			if (x == n - i - 1) continue;
			reverse(A.begin(), A.begin()+x+1);
			ret.push_back(x+1);
			printv(A);
			reverse(A.begin(), A.begin()+n-i);
			ret.push_back(n-i);
			printv(A);
		}
		printv(ret);
		return ret;
    }
};
int main()
{
	Solution sol;
	int arr[] = {3,2,4,1};
	vector<int> vec(arr, arr+4);
	vector<int> ret = sol.pancakeSort(vec);
}










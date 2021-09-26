/*******************************************************************************
 *      file name: duplicate_zeros.cpp                                               
 *         author: Hui Chen. (c) 2020                             
 *           mail: chenhui13@baidu.com                                        
 *   created time: 2020/01/14-20:06:34                              
 *  modified time: 2020/01/14-20:06:34                              
 *******************************************************************************/
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    void print_vec(vector<int>& vec)
    {
        vector<int>::iterator it;
        cout << "the results is:"<< endl;
        for (it = vec.begin(); it != vec.end(); it++)
        {
            cout << *it << " ";
        }
        cout<<endl;
    }
    void duplicateZeros(vector<int>& A) {
        int n = A.size(), j = n + count(A.begin(), A.end(), 0);
        for (int i = n - 1; i >= 0; --i) {
        	cout<<"i:"<<i<<endl;
            if (--j < n)
                A[j] = A[i];
            cout<<"i:"<<i<<"j:"<<j<<endl;
            if (A[i] == 0 && --j < n)
                A[j] = 0;
            cout<<"i:"<<i<<"j:"<<j<<endl;
            print_vec(A);
        }
    }
};
int main()
{
	int arr[] = {1,0,2,3,0,4,5,0};
	//int arr[] = {0,0,0,0,0,0,0};
	vector<int> vec(arr,arr+8);
	Solution sol;
	sol.print_vec(vec);
	sol.duplicateZeros(vec);
	sol.print_vec(vec);
}

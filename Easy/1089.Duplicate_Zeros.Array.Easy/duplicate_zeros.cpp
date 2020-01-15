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
    void duplicateZeros(vector<int>& arr) {
		vector<int>::iterator it;
		for (it = arr.begin(); it != arr.end(); it++)
		{
			cout<<"*it:"<<*it<<endl;
			if (*it == 0)
			{
				it++;
				if (it == arr.end()) break;
				arr.pop_back();
				it = arr.insert(it, 0);
			}
			print_vec(arr);
		}
    }
};
int main()
{
	//int arr[] = {1,0,2,3,0,4,5,0};
	int arr[] = {0,0,0,0,0,0,0};
	vector<int> vec(arr,arr+7);
	Solution sol;
	sol.print_vec(vec);
	sol.duplicateZeros(vec);
	sol.print_vec(vec);
}

/*******************************************************************************
 *      file name: remove_dup.cpp                                               
 *         author: hui chen. (c) 17                             
 *           mail: chenhui13@baidu.com                                        
 *   created time: 17/10/17-10:10                                    
 *  modified time: 17/10/17-10:10                                    
 *******************************************************************************/
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
		if (nums.size() <= 1)
			return nums.size();
		vector<int>::iterator it_pre = nums.begin();
		vector<int>::iterator it = nums.begin();
		it++;
		int current = 0;
		for (; it != nums.end();)
		{
			cout<<" "<<*it<< endl;
			if(*it == *it_pre) 
			{
				nums.erase(it);
			}
			else
			{
				it_pre++;
				it++;
			}
		}
		return nums.size();
    }
};

int main()
{
	Solution sol;
	/*
	int arr[7] = {1, 2, 2, 3, 4, 4, 5};   
	vector<int> vec(arr, arr + 7);      //将arr数组的元素用于初始化vec向量
	int arr[2] = {1, 1};   
	vector<int> vec(arr, arr + 2);      //将arr数组的元素用于初始化vec向量
	int arr[1] = {1};   
	vector<int> vec(arr, arr + 1);      //将arr数组的元素用于初始化vec向量
	*/
	vector<int> vec;      //将arr数组的元素用于初始化vec向量
	sol.removeDuplicates(vec);
	vector<int>::iterator it;
	cout << "the results is:"<< endl;
	for (it = vec.begin(); it != vec.end(); it++)
	{
		cout << *it << " ";
	}
	cout<<endl;
}

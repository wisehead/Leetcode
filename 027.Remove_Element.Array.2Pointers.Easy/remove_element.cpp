/*******************************************************************************
 *      file name: remove_element.cpp                                               
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
	int removeElement(vector<int>& nums, int val) {
		vector<int>::iterator it = nums.begin();
		for (; it != nums.end();)
		{
			cout<<" "<<*it<< endl;
			if(*it == val) 
			{
				nums.erase(it);
			}
			else
			{
				it++;
			}
		}
		return nums.size();
    }
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
};

int main()
{
	Solution sol;
	int arr1[7] = {1, 2, 2, 3, 4, 4, 5};   
	vector<int> vec1(arr1, arr1 + 7);      //将arr数组的元素用于初始化vec向量
	int arr2[2] = {1, 1};   
	vector<int> vec2(arr2, arr2 + 2);      //将arr数组的元素用于初始化vec向量
	int arr3[1] = {1};   
	vector<int> vec3(arr3, arr3 + 1);      //将arr数组的元素用于初始化vec向量
	sol.removeElement(vec1, 0);
	sol.print_vec(vec1);
	sol.removeElement(vec1, 4);
	sol.print_vec(vec1);
	sol.removeElement(vec1, 2);
	sol.print_vec(vec1);
	sol.removeElement(vec2, 1);
	sol.print_vec(vec2);
}

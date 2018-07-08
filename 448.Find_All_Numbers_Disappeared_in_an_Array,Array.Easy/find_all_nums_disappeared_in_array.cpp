/*******************************************************************************
 *      file name: find_all_nums_disappeared_in_array.cpp                                               
 *         author: Hui Chen. (c) 2018                             
 *           mail: chenhui13@baidu.com                                        
 *   created time: 2018/07/08-17:57:29                              
 *  modified time: 2018/07/08-17:57:29                              
 *******************************************************************************/
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
		int n = nums.size();
		vector<int> ret;
		for (int i = 0; i < n; i++)
			ret.push_back(i+1);
		vector<int>::iterator it;
		for (it = nums.begin(); it != nums.end(); it++)
		{
			if (ret[*it - 1])
				ret[*it - 1] = 0;
		}
		int i = 0;
		for (i=0, it = ret.begin(); it != ret.end(); it++, i++)
		{
			cout<<"ret["<<i<<"]	"<<*it<<" "<<endl;
		}
		for (it = ret.begin(); it != ret.end(); )
		{
			if (*it == 0)
				it = ret.erase(it);
			else
				it++;
		}
		return ret;
    }
};
int main()
{
	int arr[8] = {4,3,2,7,8,2,3,1};
	vector<int> vec(arr, arr + 8); 
	Solution sol;
	vector<int> ret = sol.findDisappearedNumbers(vec);
	vector<int>::iterator it;
	int i = 0;
	for (i=0, it = ret.begin(); it != ret.end(); it++, i++)
	{
		cout<<"ret["<<i<<"]	"<<*it<<" "<<endl;
	}
}

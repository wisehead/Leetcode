/*******************************************************************************
 *      file name: degree_of_an_array.cpp                                               
 *         author: Hui Chen. (c) 2018                             
 *           mail: chenhui13@baidu.com                                        
 *   created time: 2018/09/20-22:37:45                              
 *  modified time: 2018/09/20-22:37:45                              
 *******************************************************************************/
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;
class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
		map<int, int> mm;
		int len = nums.size();
		int max = 1;
		map<int, int>::iterator iter;
		for (int i=0; i<len; i++)
		{
			int x = nums[i];
			iter = mm.find(x);
			if(iter != mm.end())
			{
				if (++mm[x] > max)
					max = mm[x];
			}
			else
				mm[x] = 1;
		}

		int min = len;
		vector<int> vec(nums);
		reverse(vec.begin(), vec.end());
		for (iter = mm.begin(); iter != mm.end(); iter++)
		{
			if (iter->second == max)
			{
				vector<int>::iterator it_left = find(nums.begin(), nums.end(), iter->first);
				vector<int>::iterator it_right = find(vec.begin(), vec.end(), iter->first);
				int left = it_left - nums.begin();
				int right = vec.end() - it_right - 1;
				int delta = right - left + 1;
				cout<<"left:"<<left<<"	right:"<<right<<"	delta:"<<delta<<endl;
				if (delta < min)
					min = delta;
			}
		}
		return min;

    }
};
int main()
{
	//int array[5] = {1, 2, 2, 3, 1};
	//vector<int> vec(array, array+5);
	int array[7] = {1,2,2,3,1,4,2};
	vector<int> vec(array, array+7);
	Solution sol;
	int ret = 0;
	ret = sol.findShortestSubArray(vec);
	cout<<"ret:"<<ret<<endl;
}

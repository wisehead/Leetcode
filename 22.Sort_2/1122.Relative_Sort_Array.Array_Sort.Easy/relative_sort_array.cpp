/*******************************************************************************
 *      file name: relative_sort_array.cpp                                               
 *         author: Hui Chen. (c) 2020                             
 *           mail: chenhui13@baidu.com                                        
 *   created time: 2020/01/16-20:00:06                              
 *  modified time: 2020/01/16-20:00:06                              
 *******************************************************************************/
#include <iostream>
#include <map>
#include <vector>
using namespace std;
class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
		map<int, int> mm;
		vector<int> res;
		for (auto e: arr2)
		{
			mm[e] = 0;
		}

		vector<int>::iterator it;
		for (it = arr1.begin(); it != arr1.end(); it++)
		{
			if (mm.count(*it))
			{
				mm[*it]++;
				arr1.erase(it);
				it--;
			}
		}
		for (auto e: arr2)
		{
			int cnt = mm[e];
			for (int i = 0; i < cnt; i++)
				res.push_back(e);
		}
		sort(arr1.begin(), arr1.end());
		res.insert(res.end(), arr1.begin(), arr1.end());
		return res;
    }
};
int main()
{}

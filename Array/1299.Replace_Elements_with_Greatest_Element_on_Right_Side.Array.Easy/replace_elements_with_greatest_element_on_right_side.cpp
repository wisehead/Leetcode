/*******************************************************************************
 *      file name: replace_elements_with_greatest_element_on_right_side.cpp                                               
 *         author: Hui Chen. (c) 2020                             
 *           mail: chenhui13@baidu.com                                        
 *   created time: 2020/01/18-14:18:56                              
 *  modified time: 2020/01/18-14:18:56                              
 *******************************************************************************/
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
		int n = arr.size();
		vector<vector<int>> vv;
		for (int i = 0; i < n; i++)
		{
			vector<int> vec(2, i);
			vec[0] = arr[i];
			vv.push_back(vec);
		}
		sort(vv.begin(), vv.end());
		vector<int> res;
		for (int i = 0; i < n; i++)
		{
			int j = n - 1;
			while (!vv.empty() && vv.back()[1] <= i)
				vv.pop_back();
			if (!vv.empty())
				res.push_back(vv.back()[0]);
			else
				res.push_back(-1);
		}
		return res;
		
    }
};
int main()
{}

/*******************************************************************************
 *      file name: array_nesting.cpp                                               
 *         author: Hui Chen. (c) 2019                             
 *           mail: chenhui13@baidu.com                                        
 *   created time: 2019/04/26-17:15:36                              
 *  modified time: 2019/04/26-17:15:36                              
 *******************************************************************************/
#include <iostream>
#include <vector>
#include <set>
using namespace std;
class Solution {
public:
    int arrayNesting(vector<int>& nums) {
		int n = nums.size();
		int max_len = 0;
		set<int> s1;
		for (int i = 0; i < n; i++ )
		{
			int x = i;
			int len = 0;
			while (!s1.count(x))
			{
				len++;
                //cout<<"x:"<<x<<"    len:"<<len<<endl;
				s1.insert(x);
				x = nums[x];
			}
			if (len > max_len) max_len = len;
		}
		return max_len;
    }
};
int main()
{}

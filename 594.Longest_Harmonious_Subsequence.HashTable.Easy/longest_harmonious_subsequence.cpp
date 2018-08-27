/*******************************************************************************
 *      file name: longest_harmonious_subsequence.cpp                                               
 *         author: Hui Chen. (c) 2018                             
 *           mail: chenhui13@baidu.com                                        
 *   created time: 2018/08/27-09:45:15                              
 *  modified time: 2018/08/27-09:45:15                              
 *******************************************************************************/
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int findLHS(vector<int>& nums) {
		int len = nums.size();
		sort(nums.begin(), nums.end());
		int count = 0;
		int count_pre = -1;
		int max = 0;
		for (int i = 0; i < len; i++)
		{

			if ((i==0) || (nums[i] == nums[i-1]))
			{
				count++;
                //cout<<"1 count_pre:"<<count_pre<<"    count:"<<count<<" max:"<<max<<endl;
                if (count_pre > 0 && (count + count_pre > max) )
				    max = count + count_pre;
				continue;
			}
			
			if (nums[i] == nums[i-1] + 1)
				count_pre = count;
			else
				count_pre = 0;
			count = 1;
            //cout<<"2 count_pre:"<<count_pre<<"    count:"<<count<<" max:"<<max<<endl;
            if (count_pre > 0 && count + count_pre > max)
				max = count + count_pre;
		}
        if (count_pre == -1)
            return 0;
		return max;
    }
};
int main()
{}

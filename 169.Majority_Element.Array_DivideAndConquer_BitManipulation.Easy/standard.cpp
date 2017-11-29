/*******************************************************************************
 *      file name: major_element.cpp                                               
 *         author: Hui Chen. (c) 17                             
 *           mail: chenhui13@baidu.com                                        
 *   created time: 17/11/29-11:11                                    
 *  modified time: 17/11/29-11:11                                    
 *******************************************************************************/
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int, int> counts; 
        int n = nums.size();
        for (int i = 0; i < n; i++)
            if (++counts[nums[i]] > n / 2)
                return nums[i];
    }
};
int main()
{
	Solution sol;
	int array[] = {1,2,3,4,2,2,2};
	vector<int> vec(array, array+7);
	int out = sol.majorityElement(vec);
	cout<<"the majority num is:"<<out<<endl;
}


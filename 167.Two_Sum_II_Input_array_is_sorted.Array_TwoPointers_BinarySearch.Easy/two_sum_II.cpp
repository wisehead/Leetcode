/*******************************************************************************
 *      file name: two_sum_II.cpp                                               
 *         author: hui chen. (c) 17                             
 *           mail: chenhui13@baidu.com                                        
 *   created time: 17/11/27-11:11                                    
 * modified time: 17/11/27-11:11                                    
 *******************************************************************************/
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
		int size = numbers.size();
		vector<int> vec;
		if (size == 0)
			return vec;
		int i = 0;
		int j = size - 1;
		while (i < j)
		{
			while (i<j && numbers[i] + numbers[j] > target)
			{
				j--;
			}
			if (i < j && numbers[i] + numbers[j] == target)
			{
				vec.push_back(i+1);
				vec.push_back(j+1);
				return vec;
			}
			i++;
		}
		return vec;
    }
};
int main()
{
	Solution sol;
	int array[] = {1,2,3,4,5,6,7,11,15};
	vector<int>vec_in(array,array+9);
	vector<int> vec_out = sol.twoSum(vec_in, 9);
	vector<int>::iterator it;
	for(it = vec_out.begin(); it != vec_out.end(); it++)
	{
		cout<<"*it is:"<<*it<<endl;
	}
}

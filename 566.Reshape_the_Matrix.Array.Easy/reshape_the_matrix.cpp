/*******************************************************************************
 *      file name: reshape_the_matrix.cpp                                               
 *         author: Hui Chen. (c) 2018                             
 *           mail: chenhui13@baidu.com                                        
 *   created time: 2018/08/25-21:59:13                              
 *  modified time: 2018/08/25-21:59:13                              
 *******************************************************************************/
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    vector<vector<int> > matrixReshape(vector<vector<int> >& nums, int r, int c) {
		vector<vector<int> > res;
		vector<int> vec;
		int r0 = nums.size();
		int c0 = nums[0].size(); 
		int total = r0 * c0;
		if (r*c != total)
			return nums;
		for (int i = 0; i < r0; i++)
		{
			for (int j=0; j < c0; j++ )
			{
				vec.push_back(nums[i][j]);
			}
		}
		int k = 0;
		for (int i = 0; i < r; i++)
		{
			vector<int> temp;
			for (int j=0; j < c; j++ )
			{
				temp.push_back(vec[k++]);
			}
			res.push_back(temp);
		}
		return res;

    }
};
int main()
{}

/*******************************************************************************
 *      file name: container_with_most_water.cpp                                               
 *         author: Hui Chen. (c) 2019                             
 *           mail: chenhui13@baidu.com                                        
 *   created time: 2019/02/23-20:18:57                              
 *  modified time: 2019/02/23-20:18:57                              
 *******************************************************************************/
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int maxArea(vector<int>& height) {
		int size = height.size();
		int maxA = 0;
		for (int i = 0; i < size; i++)
		{
			for (int j = i+1; j < size; j++)
			{
				int h = min(height[i], height[j]);
				int area = (j - i) * h;
				if (area > maxA) maxA = area;
			}
		}
		return maxA;
    }
};
int main()
{}

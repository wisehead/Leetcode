/*******************************************************************************
 *      file name: largest_triangle_area.cpp                                               
 *         author: Hui Chen. (c) 2018                             
 *           mail: chenhui13@baidu.com                                        
 *   created time: 2018/11/07-11:29:48                              
 *  modified time: 2018/11/07-11:29:48                              
 *******************************************************************************/
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    double largestTriangleArea(vector<vector<int> >& points) {
		int len = points.size();
		double max = 0;
		for (int i = 0; i < len; i++)
		{
			for (int j = i+1; j < len; j++)
			{
				for (int k = j+1; k < len; k++)
				{
					vector<int> a = points[i];
					vector<int> b = points[j];
					vector<int> c = points[k];
					if ( (a[0] == b[0] && b[0] == c[0])
							|| (a[1] == b[1] && b[1] == c[1]))
						continue;
					double result = 0.5* abs(a[0]*b[1] + b[0]*c[1] + c[0]*a[1] - a[0]*c[1] - c[0]*b[1] - b[0]*a[1]);
					if (result > max) max = result;
				}
			}
		}
		return max;
    }
};
int main()
{}

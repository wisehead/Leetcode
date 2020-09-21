/*******************************************************************************
 *      file name: construct_rectangle.cpp                                               
 *         author: Hui Chen. (c) 2018                             
 *           mail: chenhui13@baidu.com                                        
 *   created time: 2018/08/19-07:25:22                              
 *  modified time: 2018/08/19-07:25:22                              
 *******************************************************************************/
#include <iostream>
#include <math.h>
#include <vector>
using namespace std;
class Solution {
public:
    vector<int> constructRectangle(int area) {
		vector<int> res;
		double area_double = (double)area;
		double s = sqrt(area_double);
		for (int l = s; l <= area; l++)
		{
			if (area % l == 0 && l >= area/l)
			{
				int w = area / l;
				res.push_back(l);
				res.push_back(w);
                return res;
			}
		}
		return res;
    }
};
int main()
{}

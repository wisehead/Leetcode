/*******************************************************************************
 *      file name: range_addition_II.cpp                                               
 *         author: Hui Chen. (c) 2018                             
 *           mail: chenhui13@baidu.com                                        
 *   created time: 2018/08/27-11:06:53                              
 *  modified time: 2018/08/27-11:06:53                              
 *******************************************************************************/
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int maxCount(int m, int n, vector<vector<int> >& ops) {
		int min_r = m, min_c = n;
		for (int k = 0; k < ops.size(); k++)
		{
			vector<int> temp = ops[k] ;
			int r = temp[0];
			int c = temp[1];
			if (r < min_r) min_r = r;
			if (c < min_c) min_c = c;
		}
		return min_r*min_c;
    }
};
int main()
{}

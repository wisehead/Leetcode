/*******************************************************************************
 *      file name: k_closest_points_to_origin.cpp                                               
 *         author: Hui Chen. (c) 2019                             
 *           mail: chenhui13@baidu.com                                        
 *   created time: 2019/02/13-15:44:14                              
 *  modified time: 2019/02/13-15:44:14                              
 *******************************************************************************/
#include <iostream>
#include <map>
#include <vector>
#include <math.h>
using namespace std;
class Solution {
public:
    vector<vector<int> > kClosest(vector<vector<int> >& points, int K) {
		int size = points.size();
		map<unsigned long, vector<int> > mm;
		vector<vector<int> > res;
		for (int i = 0; i < size; i++)
		{
			vector<int> vec = points[i];
			unsigned long key = vec[0]*vec[0] + vec[1]*vec[1];
			mm[key] = vec;
		}
		map<unsigned long, vector<int> >::iterator it;
		int i = 0;
		for (it = mm.begin(); it != mm.end() && i < K; it++, i++)
		{
            cout<<"key:"<<it->first<<endl;
			res.push_back(it->second);
		}
		return res;
    }
};
int main()
{}

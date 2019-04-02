/*******************************************************************************
 *      file name: triangle.cpp                                               
 *         author: Hui Chen. (c) 2019                             
 *           mail: chenhui13@baidu.com                                        
 *   created time: 2019/04/02-09:25:39                              
 *  modified time: 2019/04/02-09:25:39                              
 *******************************************************************************/
#include <iostream>
#include <vector>
#include <queue>
using namespace std;
class Solution {
public:
    int minimumTotal(vector<vector<int> >& triangle) {
		if (triangle.empty() || triangle[0].empty()) return 0;
		int ret = INT_MAX;
		queue<int> q;
		int m = triangle.size();
		q.push(triangle[0][0]);
		for (int i = 1; i < m; i++)
		{
			vector<int> tmp = triangle[i];
			int size = q.size();
            //cout<<"size:"<<size<<endl;
            int z = INT_MAX;
			for (int j = 0; j < size; j++)
			{
				int e = q.front();
                //cout<<"i:"<<i<<"    j:"<<j<<"   e:"<<e<<endl;
				q.pop();
                int x = min(e+tmp[j], z);
				q.push(x);
                z = e + tmp[j+1];
                if (j == size - 1) 
                    q.push(z);
			}
		}
		while (!q.empty())
		{
			int e = q.front();
			q.pop();
			if (e < ret) ret = e;
		}
		return ret;
    }
};
int main()
{}

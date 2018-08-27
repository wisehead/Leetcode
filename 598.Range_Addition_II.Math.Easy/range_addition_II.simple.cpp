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
        if (ops.size() == 0)
            return m*n;
		vector<int> vec(m*n, 0);
		//vector<int> ;
		for (int k = 0; k < ops.size(); k++)
		{
			vector<int> temp = ops[k] ;
			int r = temp[0];
			int c = temp[1];
			for (int i = 0; i < r; i++)
			{
				for (int j = 0; j < c; j++)
				{
					vec[i*m+j]++;
				}
			}
		}
		sort(vec.begin(), vec.end());
		int count = 0;
		for (int i = vec.size() - 1; i >= 0; i--)
		{
            //cout<<"i:"<<i<<"    val:"<<vec[i]<<endl;
			if (i == vec.size() - 1)
			{
				count=1;
                //cout<<"1 count is:"<<count<<endl;
				continue;
			}
			if (vec[i+1] == vec[i])
			{
				count++;
                //cout<<"2 count is:"<<count<<endl;
                continue;
			}
            return count;
                
		}
		return count;
    }
};
int main()
{}

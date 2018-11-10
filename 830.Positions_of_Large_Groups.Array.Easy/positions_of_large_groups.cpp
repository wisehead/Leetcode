/*******************************************************************************
 *      file name: positions_of_large_groups.cpp                                               
 *         author: Hui Chen. (c) 2018                             
 *           mail: chenhui13@baidu.com                                        
 *   created time: 2018/11/10-14:22:09                              
 *  modified time: 2018/11/10-14:22:09                              
 *******************************************************************************/
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    vector<vector<int> > largeGroupPositions(string S) {
		vector<vector<int> > res;
		int len = S.length();
		int start = 0, end = 0;
		for (int i = 0; i < len; i++)
		{
			if (S[i] == S[start] && i != len - 1)
				end = i;
			else
			{
                if (i == len - 1 && S[i] == S[start])
                    end = i;
                
				if (end - start >= 2)
				{
					vector<int> vec;
					vec.push_back(start);
					vec.push_back(end);
					res.push_back(vec);
				}
				start = i;
				end = i;
			}
		}
		return res;
    }
};
int main()
{}

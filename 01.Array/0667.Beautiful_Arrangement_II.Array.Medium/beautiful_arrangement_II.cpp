/*******************************************************************************
 *      file name: beautiful_arrangement_II.cpp                                               
 *         author: Hui Chen. (c) 2019                             
 *           mail: chenhui13@baidu.com                                        
 *   created time: 2019/04/29-21:49:30                              
 *  modified time: 2019/04/29-21:49:30                              
 *******************************************************************************/
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    void printvec(vector<int>& vec) {
        for (auto e : vec)
            cout<<e<<",";
        cout<<endl;
    }
    vector<int> constructArray(int n, int k) {
		vector<int> vec;
		int l = 1, r = n;
		if (k % 2 == 1)//odd
		{
			int x = 1;
			while (x != k)
			{
				vec.push_back(l++);
				vec.push_back(r--);
				x += 2;
			}
			while (l <= r)
			{
				vec.push_back(l++);
			}
		}
		else//even
		{
			int x = 0;
			while (x != k)
			{
				vec.push_back(r--);
				vec.push_back(l++);
				x += 2;
			}
			while (l <= r)
			{
				vec.push_back(l++);
			}
		}
		printvec(vec);
		return vec;
    }
};
int main()
{}

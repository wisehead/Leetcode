/*******************************************************************************
 *      file name: binary_gap.cpp                                               
 *         author: Hui Chen. (c) 2018                             
 *           mail: chenhui13@baidu.com                                        
 *   created time: 2018/12/31-21:54:54                              
 *  modified time: 2018/12/31-21:54:54                              
 *******************************************************************************/
#include <iostream>
using namespace std;
class Solution {
public:
    int binaryGap(int N) {
        int res = 0;
        for (int d = -32; N; N /= 2, d++)
            if (N % 2) res = max(res, d), d = 0;
        return res;
    }
};
int main()
{
	Solution sol;
	int ret = sol.binaryGap(6);
	cout<<"ret:"<<ret<<endl;
}

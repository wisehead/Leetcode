/*******************************************************************************
 *      file name: number_of_matching_subsequences.cpp                                               
 *         author: Hui Chen. (c) 2019                             
 *           mail: chenhui13@baidu.com                                        
 *   created time: 2019/05/28-09:19:56                              
 *  modified time: 2019/05/28-09:19:56                              
 *******************************************************************************/
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int numMatchingSubseq(string S, vector<string>& words) {
		int cnt = 0;
		for (auto e: words)
		{
			int ret = 0;
			for (auto c: e)
			{
				ret = S.find(c, ret);
				if (ret == string::npos) break;
                ret++;
			}
			if (ret != string::npos) cnt++;
		} 
		return cnt;
    }
};
int main()
{}

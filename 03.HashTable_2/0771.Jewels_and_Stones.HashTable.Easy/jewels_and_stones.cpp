/*******************************************************************************
 *      file name: jewels_and_stones.cpp                                               
 *         author: Hui Chen. (c) 2018                             
 *           mail: chenhui13@baidu.com                                        
 *   created time: 2018/10/05-12:33:37                              
 *  modified time: 2018/10/05-12:33:37                              
 *******************************************************************************/
#include <iostream>
#include <set>
using namespace std;
class Solution {
public:
    int numJewelsInStones(string J, string S) {
		set<char> ss;
		for (int i = 0; i < J.length(); i++)
		{
			ss.insert(J[i]);
		}
		int count = 0;
		for (int i = 0; i < S.length(); i++)
		{
			set<char>::iterator iter;
			if((iter = ss.find(S[i])) != ss.end())
				count++;
		}
		return count;
    }
};
int main()
{}

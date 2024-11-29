/*******************************************************************************
 *      file name: repeated_string_match.cpp                                               
 *         author: Hui Chen. (c) 2018                             
 *           mail: chenhui13@baidu.com                                        
 *   created time: 2018/09/18-09:39:10                              
 *  modified time: 2018/09/18-09:39:10                              
 *******************************************************************************/
#include <iostream>
using namespace std;
class Solution {
public:
    int repeatedStringMatch(string A, string B) {
		int len_a = A.length();
		if (len_a == 0) return -1;
		int len_b = B.length();
		int high = (len_b/len_a) + 2;
		string dest;
		for (int i = 0; i < high; i++)
		{
			dest += A;
			if (high > 0 && i >= high - 3)
			{
				int pos = dest.find(B);
				if (pos != string::npos)
				{
					return i+1;
				}
			}
		}
		return -1;
    }
};
int main()
{}

/*******************************************************************************
 *      file name: string_without_AAA_or_BBB.cpp                                               
 *         author: Hui Chen. (c) 2019                             
 *           mail: chenhui13@baidu.com                                        
 *   created time: 2019/02/18-10:33:06                              
 *  modified time: 2019/02/18-10:33:06                              
 *******************************************************************************/
#include <iostream>
using namespace std;
class Solution {
public:
    string construct(int x, int y, bool flag) {
		string s;
		for (int i = 0; i < x; i++)
		{
            if (flag)
			    s += "bba";
            else
                s += "aab";
		}
		for (int i = 0; i < y; i++)
		{
            if (flag)
    			s += "ba";
            else
                s += "ab";
		}
		return s;
	}
    string strWithout3a3b(int A, int B) {
		int x = 0, y = 0;
        string tail;
		if (A > B)
		{
            if (A <= 2*B)
            {
			    x = A - B;
			    y = 2*B - A;
            }
            else
            {
                x = B; y = 0;
                for (int k=0; k<A-2*B;k++)
                    tail += "a";
            }
		}
		else
		{
            if (B <= 2*A)
            {
			    x = B - A;
			    y = 2*A - B;
            }
            else
            {
                x = A; y = 0;
                for (int k=0; k<B-2*A;k++)
                    tail += "b";
            }
		}
		return construct(x, y, A < B)+tail;
    }
};
int main()
{}

/*******************************************************************************
 *      file name: single_number_II.cpp                                               
 *         author: Hui Chen. (c) 2021                             
 *           mail: alex.chenhui@gmail.com                                        
 *   created time: 2021/10/06-10:44:39                              
 *  modified time: 2021/10/06-10:44:39                              
 *******************************************************************************/
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
   int singleNumber(vector<int>& s) 
    {
    	vector<int> t(32);////Made a array contain 32 elements.
    	int sz = s.size();
    	int i, j, n;
    	for (i = 0; i < sz; ++i)
    	{
    		n = s[i];
    		for (j = 31; j >= 0; --j)
    		{
    			t[j] += n & 1;//Find the last digit.
    			n >>= 1;
    			if (!n)
    				break;
    	    }
        }
	int res = 0;
	for (j = 31; j >= 0; --j)
	{
		n = t[j] % 3;//"3" represents k times. 
		if (n)
			res += 1 << (31 - j);
	}
	return res;
}
};
int main()
{}

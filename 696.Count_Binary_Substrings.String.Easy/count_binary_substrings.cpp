/*******************************************************************************
 *      file name: count_binary_substrings.cpp                                               
 *         author: Hui Chen. (c) 2018                             
 *           mail: chenhui13@baidu.com                                        
 *   created time: 2018/09/20-13:45:06                              
 *  modified time: 2018/09/20-13:45:06                              
 *******************************************************************************/
#include <iostream>
using namespace std;
class Solution {
public:
    int countBinarySubstrings(string s) {
		int len = s.length();
		int count_0 = 0, count_1 = 0, count = 0;
		bool flag_1 = false;
		for (int i=0; i<len; i++)
		{
			if (s[i] == '1' )
			{
				if (!flag_1)
				{
					count_1 = 0;
					flag_1 = true;
				}
				count_1++;
				if (count_0 > 0)
				{
					count_0--;
					count++;
				}
                //cout<<"i:"<<i<<"    count_0:"<<count_0<<"   count_1:"<<count_1<<"   count:"<<count<<endl;
				continue;
			}
			if (s[i] == '0' )
			{
				if (flag_1)
				{
					count_0 = 0;
					flag_1 = false;
				}
				count_0++;
				if (count_1 > 0)
				{
					count_1--;
					count++;
				}
                //cout<<"i:"<<i<<"    count_0:"<<count_0<<"   count_1:"<<count_1<<"   count:"<<count<<endl;
			}
		}
		return count;
    }
};
int main()
{}

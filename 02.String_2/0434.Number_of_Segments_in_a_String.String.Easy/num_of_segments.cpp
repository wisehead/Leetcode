/*******************************************************************************
 *      file name: num_of_segments.cpp                                               
 *         author: Hui Chen. (c) 18                             
 *           mail: chenhui13@baidu.com                                        
 *   created time: 18/03/28- 3:03                                    
 *  modified time: 18/03/28- 3:03                                    
 *******************************************************************************/
#include <iostream>
using namespace std;
class Solution {
public:
    int countSegments(string s) {
		if (s.length() == 0)
			return 0;
		int count = 0;
		if (s[0] != ' ')
			count++;

		for (int i=0; i<s.length() - 1; i++)
		{
			if (s[i] == ' ' && s[i+1] != ' ')
			{
				count++;
				continue;
			}
		}
		cout<<"s is:"<<s<<endl;
		cout<<"count is:"<<count<<endl;
		return count;
    }
};

int main()
{
	Solution sol;
	//int ret = sol.countSegments("Hello, my name is John");
	int ret = sol.countSegments("");
}

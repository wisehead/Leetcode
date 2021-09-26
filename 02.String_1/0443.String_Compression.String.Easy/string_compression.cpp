/*******************************************************************************
 *      file name: string_compression.cpp                                               
 *         author: Hui Chen. (c) 18                             
 *           mail: chenhui13@baidu.com                                        
 *   created time: 18/06/30- 6:06                                    
 *  modified time: 18/06/30- 6:06                                    
 *******************************************************************************/
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int compress(vector<char>& chars) {
		vector<char>::iterator it;
		vector<char>::iterator it_pre = chars.begin();
		int i = 0, j = 0;
		int count = 1;
		int start = 0;
		if (chars.size() == 1)
			start = 1;
		for (it = chars.begin() + 1; it != chars.end(); it++, i++)
		{
			if (*it == *it_pre && it+1 != chars.end())
				count++;
			else
			{
				bool flag = false;
				if (it+1 == chars.end())
				{
					if (*it == *it_pre)
						count++;
					else
						flag = true;
				}
				chars[start] = *it_pre;
				it_pre = it;
				if (count > 999)
				{
					chars[start+1] = '1';
					chars[start+2] = '0';
					chars[start+3] = '0';
					chars[start+4] = '0';
					start = start + 5;
				}
				else if (count > 99)
				{
					chars[start+1] = count / 100 + '0';
					int temp = count / 100;
					count = count - temp * 100;
					chars[start+2] = count / 10  + '0';
					temp = count / 10;
					count = count - temp * 10;
					chars[start+3] = count + '0';
					start = start + 4;
				}
				else if (count > 9)
				{
					chars[start+1] = count / 10  + '0';
					int temp = count / 10;
					count = count - temp * 10;
					chars[start+2] = count + '0';
					start = start + 3;
				}
				else if (count > 1)
				{
					chars[start+1] = count + '0';
					start = start + 2;
				}
				else
				{
					start = start + 1;
				}
				count = 1;
				if (flag)
				{
					chars[start] = *it;
					start = start + 1;
				}

			}
		}
		for (int i=0; i< start;i++)
			cout<<"vec["<<i<<"] is:"<<chars[i]<<endl;
		return start;
    }
};

int main()
{
	Solution sol;
	vector<char> vec1;
	/*
	vec1.push_back('a');
	vec1.push_back('a');
	vec1.push_back('b');
	vec1.push_back('b');
	vec1.push_back('c');
	vec1.push_back('c');
	vec1.push_back('c');
	*/
	/*
	vec1.push_back('a');
	*/
	/*
	vec1.push_back('a');
	vec1.push_back('b');
	vec1.push_back('b');
	vec1.push_back('b');
	vec1.push_back('b');
	vec1.push_back('b');
	vec1.push_back('b');
	vec1.push_back('b');
	vec1.push_back('b');
	vec1.push_back('b');
	vec1.push_back('b');
	vec1.push_back('b');
	vec1.push_back('b');
	*/
	/*
	vec1.push_back('a');
	vec1.push_back('b');
	vec1.push_back('b');
	vec1.push_back('b');
	vec1.push_back('b');
	vec1.push_back('b');
	vec1.push_back('b');
	vec1.push_back('b');
	vec1.push_back('b');
	vec1.push_back('b');
	vec1.push_back('b');
	vec1.push_back('b');
	vec1.push_back('b');
	vec1.push_back('b');
	vec1.push_back('b');
	vec1.push_back('b');
	vec1.push_back('b');
	vec1.push_back('b');
	vec1.push_back('b');
	vec1.push_back('b');
	vec1.push_back('b');
	vec1.push_back('b');
	vec1.push_back('b');
	vec1.push_back('b');
	vec1.push_back('b');
	vec1.push_back('b');
	vec1.push_back('b');
	vec1.push_back('b');
	vec1.push_back('b');
	vec1.push_back('b');
	vec1.push_back('b');
	vec1.push_back('b');
	vec1.push_back('b');
	vec1.push_back('b');
	vec1.push_back('b');
	vec1.push_back('b');
	vec1.push_back('b');
	vec1.push_back('b');
	vec1.push_back('b');
	vec1.push_back('b');
	vec1.push_back('b');
	vec1.push_back('b');
	vec1.push_back('b');
	vec1.push_back('b');
	vec1.push_back('b');
	vec1.push_back('b');
	vec1.push_back('b');
	vec1.push_back('b');
	vec1.push_back('b');
	vec1.push_back('b');
	vec1.push_back('b');
	vec1.push_back('b');
	vec1.push_back('b');
	vec1.push_back('b');
	vec1.push_back('b');
	vec1.push_back('b');
	vec1.push_back('b');
	vec1.push_back('b');
	vec1.push_back('b');
	vec1.push_back('b');
	vec1.push_back('b');
	vec1.push_back('b');
	vec1.push_back('b');
	vec1.push_back('b');
	vec1.push_back('b');
	vec1.push_back('b');
	vec1.push_back('b');
	vec1.push_back('b');
	vec1.push_back('b');
	vec1.push_back('b');
	vec1.push_back('b');
	vec1.push_back('b');
	vec1.push_back('b');
	vec1.push_back('b');
	vec1.push_back('b');
	vec1.push_back('b');
	vec1.push_back('b');
	vec1.push_back('b');
	vec1.push_back('b');
	vec1.push_back('b');
	vec1.push_back('b');
	vec1.push_back('b');
	vec1.push_back('b');
	vec1.push_back('b');
	vec1.push_back('b');
	vec1.push_back('b');
	vec1.push_back('b');
	vec1.push_back('b');
	vec1.push_back('b');
	vec1.push_back('b');
	vec1.push_back('b');
	vec1.push_back('b');
	vec1.push_back('b');
	vec1.push_back('b');
	vec1.push_back('b');
	vec1.push_back('b');
	vec1.push_back('b');
	vec1.push_back('b');
	vec1.push_back('b');
	vec1.push_back('b');
	vec1.push_back('b');
	vec1.push_back('b');
	vec1.push_back('b');
	vec1.push_back('b');
	vec1.push_back('b');
	vec1.push_back('b');
	vec1.push_back('b');
	vec1.push_back('b');
	vec1.push_back('b');
	vec1.push_back('b');
	vec1.push_back('b');
	vec1.push_back('b');
	vec1.push_back('b');
	vec1.push_back('b');
	vec1.push_back('b');
	vec1.push_back('b');
	vec1.push_back('b');
	vec1.push_back('b');
	vec1.push_back('b');
	vec1.push_back('b');
	vec1.push_back('b');
	vec1.push_back('b');
	vec1.push_back('b');
	vec1.push_back('b');
	vec1.push_back('b');
	vec1.push_back('b');
	vec1.push_back('b');
	vec1.push_back('b');
	vec1.push_back('b');
	vec1.push_back('b');
	vec1.push_back('b');
	vec1.push_back('b');
	vec1.push_back('b');
	*/
	vec1.push_back('a');
	vec1.push_back('b');
	vec1.push_back('c');
	int ret = sol.compress(vec1);
	cout<<"ret:"<<ret<<endl;
}

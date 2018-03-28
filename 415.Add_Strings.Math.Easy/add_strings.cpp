/*******************************************************************************
 *      file name: add_strings.cpp                                               
 *         author: Hui Chen. (c) 18                             
 *           mail: chenhui13@baidu.com                                        
 *   created time: 18/03/28- 3:03                                    
 *  modified time: 18/03/28- 3:03                                    
 *******************************************************************************/
#include <iostream>
#include <algorithm>
#include <stdio.h>
using namespace std;
class Solution {
public:
    string reverseString(string s) {
        reverse(s.begin(), s.end());
        return s;
    }

    string addStrings(string num1, string num2) {
		string r1 = reverseString(num1);
		string r2 = reverseString(num2);
		string out;
		int len1 = num1.length();
		int len2 = num2.length();
		int len = (len1 > len2) ? len2: len1;
		int max_len = (len1 > len2) ? len1: len2;
		int carry = 0;
		for (int i=0; i<max_len; i++)
		{
			char c1 = '0';
			char c2 = '0';
			if (i < len1)
				c1 = r1[i];
			if(i < len2)
				c2 = r2[i];
			cout<<"c1 is:"<<c1<<endl;
			cout<<"c2 is:"<<c2<<endl;
			c1 = c1 - 0x30;
			c2 = c2 - 0x30;
			//printf("c1 is:%d\n", c1 );
			//printf("c2 is:%d\n", c2 );
			int sum = c1 + c2 + carry;
			carry = 0;
			cout<<"sum is:"<<sum<<endl;
			if (sum >= 10)
			{
				carry = 1;
				sum = sum - 10;
			}
			//printf("sum is:%d\n", sum);
			sum = sum + 0x30;
			out.push_back(sum);
			//cout<<"out is:"<<out<<endl;
		}
		if (carry)
			out.push_back(1+0x30);

		cout<<"reverse out is:"<<out<<endl;
		out = reverseString(out); 
		cout<<"out is:"<<out<<endl;
		return out;
    }
};
int main()
{
	Solution sol;
	string result;
	//result = sol.addStrings("111","222");
	//result = sol.addStrings("999","222");
	result = sol.addStrings("999","2222");
}


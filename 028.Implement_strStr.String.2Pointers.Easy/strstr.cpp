/*******************************************************************************
 *      file name: strstr.cpp                                               
 *         author: hui chen. (c) 17                             
 *           mail: chenhui13@baidu.com                                        
 *   created time: 17/10/23-10:10                                    
 * modified time: 17/10/23-10:10                                    
 *******************************************************************************/
#include <iostream>
#include <string>
using namespace std;
class Solution {
public:
    int strStr(string haystack, string needle) {
		cout<<"haystack is:"<<haystack<<"	needle is:"<<needle<<endl;
		int len1 = haystack.length();
		int len2 = needle.length();
		int ret = 0;
		if (len2 > len1)
			return -1;
		for (int i = 0; i< len1 - len2 + 1; i++)
		{
			ret = haystack.compare(i, len2, needle);
			if (ret == 0)
				return i;
		}
		return -1;
    }
};

int main()
{
	Solution sol;
	int ret = -1;
	string str1("abccdddb");
	string str2("ddb");
	string str3("");
	string str4("");
	ret = sol.strStr(str1, str2);
	cout << "ret is:"<<ret<<endl;
	ret = sol.strStr(str1, "ccc");
	cout << "ret is:"<<ret<<endl;
	ret = sol.strStr(str1, "");
	cout << "ret is:"<<ret<<endl;
	ret = sol.strStr(str3, "");
	cout << "ret is:"<<ret<<endl;
	ret = sol.strStr("", "aaa");
	cout << "ret is:"<<ret<<endl;
}

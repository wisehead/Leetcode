/*******************************************************************************
 *      file name: excel_sheet_column_title.cpp                                               
 *         author: hui chen. (c) 17                             
 *           mail: chenhui13@baidu.com                                        
 *   created time: 17/11/27-11:11                                    
 * modified time: 17/11/27-11:11                                    
 *******************************************************************************/
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
#define BASE 26
class Solution {
public:
    string convertToTitle(int n) {
		char array[] = {'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};
		string str_out="";
		while (n > 0)
		{
			int mod = 0; 
			mod = n % BASE;
			if (mod == 0)
			{
				mod = 26;
			}
			n = n - mod;
			n = n / BASE;
			const char c = array[mod-1];
			str_out = str_out + c;
		}
		reverse(str_out.begin(), str_out.end());
		return str_out;
    }
};
int main()
{
	Solution sol;
	string  out = "";
	out =  sol.convertToTitle(28);
	out =  sol.convertToTitle(27);
	out =  sol.convertToTitle(26);
	out =  sol.convertToTitle(52);
	out =  sol.convertToTitle(676);
	out =  sol.convertToTitle(677);
	out =  sol.convertToTitle(702);
	out =  sol.convertToTitle(1048);
}

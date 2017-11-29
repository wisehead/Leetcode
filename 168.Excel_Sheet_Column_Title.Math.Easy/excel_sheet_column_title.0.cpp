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
class Solution {
public:
    string convertToTitle(int n) {
		char array[] = {'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};
		cout<<"input num is:"<<n<<endl;
		string str_out="";
		//cout<<"str_out is:"<<str_out<<endl;
		//cout<<"len of str_out is:"<<str_out.length()<<endl;
		int flag = 0;
		while (n > 0)
		{
			int mod = 0; 
			mod = n % 26;
			n =  n / 26;
			if (flag == 0)
			{
				if (mod == 0)
				{
					mod = 26;
					flag = 1;
				}
				else
				{
					flag = 0;
				}
			}
			else//flag == 1
			{
				if (mod == 0)
				{
					if(n == 0)
						mod = 26;
					else
						mod = 1;
					flag = 1;
				}
				else
				{
					flag = 0;
					//if (n == 0 || n==1)
					//	break;
					mod--;
					if (mod == 0)
						break;
				}

			}
			const char c = array[mod-1];
			//str_out.append(&c);
			str_out = str_out + c;
			//cout<<"str_out is:"<<str_out<<endl;
			//cout<<"len of str_out is:"<<str_out.length()<<endl;
		}
		//cout<<"str_out is:"<<str_out<<endl;
		reverse(str_out.begin(), str_out.end());
		cout<<"str_out is:"<<str_out<<endl;
		cout<<"len of str_out is:"<<str_out.length()<<endl;
		return str_out;
    }
};
int main()
{
	Solution sol;
	string  out = "";
	//out =  sol.convertToTitle(28);
	//out =  sol.convertToTitle(27);
	//out =  sol.convertToTitle(26);
	//out =  sol.convertToTitle(52);
	//out =  sol.convertToTitle(676);
	out =  sol.convertToTitle(677);
	//out =  sol.convertToTitle(702);
}

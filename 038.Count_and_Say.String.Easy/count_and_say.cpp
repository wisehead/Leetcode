/*******************************************************************************
 *      file name: count_and_say.cpp                                               
 *         author: hui chen. (c) 17                             
 *           mail: chenhui13@baidu.com                                        
 *   created time: 17/10/26-10:10                                    
 * modified time: 17/10/26-10:10                                    
 *******************************************************************************/
#include <iostream>
#include <sstream>
#include <vector>
using namespace std;
class Solution {
public:
	string myReadNum(string num)
	{
		//cout<<"input num string is:"<<num<<endl;
		string out("");
		char count_array[3];
		int len = num.length();
		int count = 1;
		for (int i=0; i<len; i++)
		{
			stringstream ss_count,ss_num;  
			string str_count(""), str_num("");
			if (i+1 < len && num[i+1] == num[i])
				count++;
			else	
			{
				ss_count<<count;
				ss_count>>str_count;
				ss_num<<num[i];
				ss_num>>str_num;
				out.append(str_count);
				out.append(str_num);
				count = 1;
			}
		}
		//cout<<"ouput string is:"<<out<<endl;
		return out;
	}
    string countAndSay(int n) {
		vector<string> vec;
		vec.push_back(string("1"));
		for (int i=0; i<n; i++)
		{
			string out = myReadNum(vec[i]); 
			vec.push_back(out);
		}
		cout<<"output for "<<n<<" is: "<<vec[n-1]<<endl;
		return vec[n-1];
    }
};

int main()
{
	Solution sol;
	/*
	sol.myReadNum("1");
	sol.myReadNum("11");
	sol.myReadNum("21");
	sol.myReadNum("1211");
	sol.myReadNum("111221");
	sol.myReadNum("312211");
	*/
	string out("");
	out = sol.countAndSay(0);
	out = sol.countAndSay(1);
	out = sol.countAndSay(2);
	out = sol.countAndSay(3);
	out = sol.countAndSay(4);
	out = sol.countAndSay(5);
	out = sol.countAndSay(6);
	out = sol.countAndSay(10);
	out = sol.countAndSay(20);
}

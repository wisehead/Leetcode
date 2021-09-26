/*******************************************************************************
 *      file name: unique_email_addresses.cpp                                               
 *         author: Hui Chen. (c) 2019                             
 *           mail: chenhui13@baidu.com                                        
 *   created time: 2019/01/25-10:18:23                              
 *  modified time: 2019/01/25-10:18:23                              
 *******************************************************************************/
#include <iostream>
#include <vector>
#include <set>
using namespace std;
class Solution {
public:
    int numUniqueEmails(vector<string>& emails) {
		int size = emails.size();
		set<string> ss;
		for (int i = 0; i < size; i++)
		{
			string temp = emails[i];
			string::iterator it;
			for (it = temp.begin(); it != temp.end(); it++)
			{
				if (*it == '.')
				{
					temp.erase(it);
					it--;
				}
				else if (*it == '+')
				{
					while(*it != '@')
						temp.erase(it);
					break;
				}
			}
			ss.insert(temp);
		}
		return ss.size();
    }
};
int main()
{
	string arr[] = {"test.email+alex@leetcode.com","test.e.mail+bob.cathy@leetcode.com","testemail+david@lee.tcode.com"};
	vector<string> vec(arr, arr+3);
	Solution sol;
	int ret = sol.numUniqueEmails(vec);
	cout<<"ret:"<<ret<<endl;
}

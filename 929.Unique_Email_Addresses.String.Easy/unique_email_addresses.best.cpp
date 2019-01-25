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
		set<string> ss;
        for( auto& e: emails )
		{
            auto pivot = e.find_first_of('@'); auto name = e.substr( 0, pivot ), domain = e.substr( pivot );
            name.erase( remove( name.begin(), name.end(), '.' ), name.end() );
			ss.insert(name.erase( name.find_first_of('+') ) + domain);
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

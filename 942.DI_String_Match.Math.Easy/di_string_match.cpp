/*******************************************************************************
 *      file name: di_string_match.cpp                                               
 *         author: Hui Chen. (c) 2019                             
 *           mail: chenhui13@baidu.com                                        
 *   created time: 2019/01/31-10:41:38                              
 *  modified time: 2019/01/31-10:41:38                              
 *******************************************************************************/
#include <iostream>
#include <vector>
#include <set>
using namespace std;
class Solution {
public:
    vector<int> diStringMatch(string S) {
		set<int> myset;
		for (int i = 0; i < S.length()+1; i++)
			myset.insert(i);
		vector<int> vec;
		int val = 0;
		for (auto &e : S)
		{
			set<int>::iterator it;
			if (e == 'I')
			{
				val = *myset.begin();
				myset.erase(val);
				cout<<"I val:"<<val<<endl;
				vec.push_back(val);
			}
			else
			{
				val = *myset.rbegin();
				myset.erase(val);
				cout<<"D val:"<<val<<endl;;
				vec.push_back(val);
			}
		}
		val = *myset.begin();
		cout<<"I val:"<<val<<endl;
		vec.push_back(val);
		return vec;

    }
};
int main()
{
	Solution sol;
	//string ss = "IDID";
	//string ss = "III";
	string ss = "DDI";
	vector<int> res = sol.diStringMatch(ss);
}

/*******************************************************************************
 *      file name: groups_of_special_equivalent_strings.cpp                                               
 *         author: Hui Chen. (c) 2019                             
 *           mail: chenhui13@baidu.com                                        
 *   created time: 2019/01/14-11:17:38                              
 *  modified time: 2019/01/14-11:17:38                              
 *******************************************************************************/
#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <algorithm>

using namespace std;
class Solution {
public:
	int numSpecialEquivGroups(vector<string>& A) {
	    set<pair<string,string>> s;
	    for (const auto& w : A) {
	        pair<string,string> p;
	        for (int i = 0; i < w.size (); ++i) {
	            if (i % 2) p.first  += w[i];
	            else       p.second += w[i];
	        }
	        sort (p.first.begin  (), p.first.end ());
	        sort (p.second.begin (), p.second.end ());
	        s.insert (p);
	    }
	    return s.size ();
	}
};
int main()
{
	Solution sol;
	string arr[] = {"a","b","c","a","c","c"};
	vector<string> vec(arr, arr+6);
	/*
	string arr[] = {"aa","bb","ab","ba"};
	vector<string> vec(arr, arr+4);
	*/
	/*
	string arr[] = {"abcd","cdab","adcb","cbad"};
	vector<string> vec(arr, arr+4);
	*/
	/*
	string arr[] = {"abc","acb","bac","bca","cab","cba"};
	vector<string> vec(arr, arr+6);
	*/
	int ret = sol.numSpecialEquivGroups(vec);
	cout<<"count:"<<ret<<endl;
}


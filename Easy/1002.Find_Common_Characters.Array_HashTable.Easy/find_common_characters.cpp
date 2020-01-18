/*******************************************************************************
 *      file name: find_common_characters.cpp                                               
 *         author: Hui Chen. (c) 2019                             
 *           mail: chenhui13@baidu.com                                        
 *   created time: 2019/07/09-09:36:37                              
 *  modified time: 2019/07/09-09:36:37                              
 *******************************************************************************/
#include <iostream>
#include <vector>
#include <unordered_map>
#include <sstream>
using namespace std;
class Solution {
public:
    vector<string> commonChars(vector<string>& A) {
		int n = A.size();
		vector<string> vec;
		if (n == 0) return vec; 
		unordered_map<char, int> m1;
		string s = A[0];
		for (char e: s)
		{
			if (m1.count(e))
				m1[e]++;
			else
				m1[e] = 1;
		}
		for (int i = 1; i < n; i++)
		{
			unordered_map<char, int> m2(m1);
			string s = A[i];
			for (char e: s)
			{
				if (m2.count(e))
					m2[e]++;
			}
			unordered_map<char,int>::iterator it;
			for (it = m1.begin(); it != m1.end(); it++)
			{
				it->second = min(m2[it->first] - it->second, it->second);
			}
		}
		for (auto it: m1)
		{
			while (it.second)
			{
                stringstream stream;
                stream << it.first;
                string str = stream.str();
				vec.push_back(str);
				it.second--;
			}
		}
		return vec;
    }
};
int main()
{}

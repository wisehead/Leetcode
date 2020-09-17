/*******************************************************************************
 *      file name: buddy_strings.cpp                                               
 *         author: Hui Chen. (c) 2018                             
 *           mail: chenhui13@baidu.com                                        
 *   created time: 2018/12/21-13:36:14                              
 *  modified time: 2018/12/21-13:36:14                              
 *******************************************************************************/
#include <iostream>
#include <map>
using namespace std;
class Solution {
public:
	bool has_dup_chars(string s) {
		int len = s.length();
		map<char,int> m;
		for (int i=0; i<len; i++)
		{
			if (++m[s[i]] >= 2) return true;
		}
		return false;
	}
    bool buddyStrings(string A, string B) {
		cout<<"A:"<<A<<endl;
		cout<<"B:"<<B<<endl;
		int len_A = A.length();
		int len_B = B.length();
		if (len_A != len_B) return false;

		if (A.compare(B) == 0)
		{
			if (has_dup_chars(A)) return true;
			return false;
		}

		int x = 0, y = 0, count = 0;
		for (int i=0; i<len_A; i++)
		{
			if (A[i] != B[i])
			{
				if (count == 0)
				{
					cout<<"0 count:"<<count<<endl;
					count++;
					x = i;
				}
				else if (count == 1)
				{
					cout<<"1 count:"<<count<<endl;
					count++;
					y = i;
				}
				else
				{
					cout<<"else count:"<<count<<endl;
					return false;
				}
			}
		}
		cout<<"x:"<<x<<"	y:"<<y<<endl;
		if (A[x] == B[y] && A[y] == B[x]) return true;
		return false;
    }
};
int main()
{
	Solution sol;
	string A = "ab";
	string B = "ba";
	bool ret = sol.buddyStrings(A, B);
	cout<<"ret:"<<ret<<endl;
}

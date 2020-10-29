/*******************************************************************************
 *      file name: letter_case_permutation.cpp                                               
 *         author: Hui Chen. (c) 2018                             
 *           mail: chenhui13@baidu.com                                        
 *   created time: 2018/10/08-15:59:03                              
 *  modified time: 2018/10/08-15:59:03                              
 *******************************************************************************/
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
	char up_low_exchange(char c) {
		if (c >= 'A' && c <= 'Z')
			c = c + 32;
		else if (c >= 'a' && c <= 'z')
			c = c - 32;
		return c;
	}
    vector<string> letterCasePermutation(string S) {
		cout<<"S is:"<<S<<endl;
		int len = S.length();
		vector<string> vec;
		if (len == 0) return vec;
		string sub = S.substr(1, len - 1);
		vector<string> subvec = letterCasePermutation(sub);
		/*
		for (int i=0; i<subvec.size(); i++)
			cout<<"subvec["<<i<<"]"<<subvec[i]<<endl;
			*/
		int size = subvec.size();
		cout<<"subvec size:"<<size<<endl;
		if (S[0] >= '0' && S[0] <= '9')
		{
			if (size == 0)
			{
				string sub;
				string temp = S[0] + sub;
				cout<<"temp:"<<temp<<endl;
				vec.push_back(temp);
			}
			for (int i=0; i < size; i++)
			{
				string sub;
				if (size != 0) sub = subvec[i];
				string temp = S[0] + sub;
				cout<<"temp:"<<temp<<endl;
				vec.push_back(temp);
			}
		}	
		else// letters
		{
			if (size == 0)
			{
				string sub;
				string temp = S[0] + sub;
				cout<<"temp:"<<temp<<endl;
				vec.push_back(temp);
				string temp2 = up_low_exchange(S[0]) + sub;
				cout<<"temp2:"<<temp2<<endl;
				vec.push_back(temp2);
			}
			for (int i=0; i < size; i++)
			{
				string sub;
				if (size != 0) sub = subvec[i];
				string temp = S[0] + sub;
				cout<<"temp:"<<temp<<endl;
				vec.push_back(temp);
				string temp2 = up_low_exchange(S[0]) + sub;
				cout<<"temp2:"<<temp2<<endl;
				vec.push_back(temp2);
			}
		}
		for (int i=0; i<vec.size(); i++)
			cout<<"vec["<<i<<"]"<<vec[i]<<endl;
		return vec;
    }
};
int main()
{
	Solution sol;
	string ss = "a1b2";
	vector<string> vec;
	vec = sol.letterCasePermutation(ss);
	for (int i=0; i<vec.size(); i++)
		cout<<"out vec["<<i<<"]"<<vec[i]<<endl;
}

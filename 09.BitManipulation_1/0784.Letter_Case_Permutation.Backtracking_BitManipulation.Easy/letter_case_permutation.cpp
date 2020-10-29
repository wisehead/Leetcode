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
		int len = S.length();
		vector<string> vec;
		if (len == 0)
        {
            vec.push_back(S);
            return vec;
        }
        string sub = S.substr(1, len - 1);
		vector<string> subvec = letterCasePermutation(sub);

		int size = subvec.size();
		if (S[0] >= '0' && S[0] <= '9')
		{
			for (int i=0; i < size|| i == 0; i++)
			{
				string sub;
				if (size != 0) sub = subvec[i];
				string temp = S[0] + sub;
				vec.push_back(temp);
                if (size == 0) break;
			}
		}	
		else// letters
		{
			for (int i=0; i < size || i == 0; i++)
			{
				string sub;
				if (size != 0) sub = subvec[i];
				string temp = S[0] + sub;
				vec.push_back(temp);
				string temp2 = up_low_exchange(S[0]) + sub;
				vec.push_back(temp2);
                if (size == 0) break;
			}
		}
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

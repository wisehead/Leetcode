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
    void backtrack(string &s, int i, vector<string> &res) {
        if (i == s.size()) {
            res.push_back(s);
            return;
        }
        backtrack(s, i + 1, res);
        if (isalpha(s[i])) {
            // toggle case
            s[i] ^= (1 << 5);
            backtrack(s, i + 1, res);
        }
    }
public:
    vector<string> letterCasePermutation(string S) {
        vector<string> res;
        backtrack(S, 0, res);
        return res;
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

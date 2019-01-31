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
    public int[] diStringMatch(String S) {
        int n = S.length(), left = 0, right = n;
        int[] res = new int[n + 1];
        for (int i = 0; i < n; ++i)
            res[i] = S.charAt(i) == 'I' ? left++ : right--;
        res[n] = left;
        return res;
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

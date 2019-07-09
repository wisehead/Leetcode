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
/*
For each string, we count characters in cnt1. Then, we track the minimum count for each character in cnt.

Complexity Analysis
Runtime: O(n), where n is the total number of characters.
Memory: O(1) (we use two fixed-size vectors).
 */
class Solution {
public:
	vector<string> commonChars(vector<string>& A) {
	  vector<int> cnt(26, INT_MAX);
	  vector<string> res;
	  for (auto s : A) {
	    vector<int> cnt1(26, 0);
	    for (auto c : s) ++cnt1[c - 'a'];
	    for (auto i = 0; i < 26; ++i) cnt[i] = min(cnt[i], cnt1[i]);
	  }
	  for (auto i = 0; i < 26; ++i)
	    for (auto j = 0; j < cnt[i]; ++j) res.push_back(string(1, i + 'a'));
	  return res;
	}
};
int main()
{}

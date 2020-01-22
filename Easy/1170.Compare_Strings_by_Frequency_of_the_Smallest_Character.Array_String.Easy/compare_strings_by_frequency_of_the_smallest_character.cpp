/*******************************************************************************
 *      file name: compare_strings_by_frequency_of_the_smallest_character.cpp                                               
 *         author: Hui Chen. (c) 2020                             
 *           mail: chenhui13@baidu.com                                        
 *   created time: 2020/01/22-11:39:11                              
 *  modified time: 2020/01/22-11:39:11                              
 *******************************************************************************/
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
	int cal(string s) {
		vector<int> arr(26, 0);
		for (char e : s)
			arr[e - 'a']++;
		for (int i = 0; i < 26; i++)
			if (arr[i])
				return arr[i];
		return 0;
	}
    vector<int> numSmallerByFrequency(vector<string>& queries, vector<string>& words) {
		int n = words.size();
		vector<int> vec;
		vector<int> res;
		for (auto w : words)
		{
			int x = cal(w);
			vec.push_back(x);
		}
		sort(vec.begin(), vec.end());
		for (auto e : queries)
		{
			int x = cal(e);
			vector<int>::iterator it = upper_bound(vec.begin(), vec.end(), x);
			int cnt = vec.end() - it;
			res.push_back(cnt);
		}
		return res;
    }
};
int main()
{}

/*******************************************************************************
 *      file name: find_works_that_can_be_formed_by_characters.cpp                                               
 *         author: Hui Chen. (c) 2019                             
 *           mail: chenhui13@baidu.com                                        
 *   created time: 2019/09/07-11:08:09                              
 *  modified time: 2019/09/07-11:08:09                              
 *******************************************************************************/
#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;
class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
		unordered_map<char, int> mm;
		int sum = 0;
		for (auto e: chars)
		{
			if (mm.count(e)) mm[e]++;
			else mm[e] = 1;
		}
		for (auto w: words)
		{
			unordered_map<char, int> m(mm);
			bool is_valid = true;
			for (auto c: w)
			{
				if (m.count(c))
				{
					m[c]--;
					if (m[c] == 0) m.erase(c);
				}
				else 
				{
					is_valid = false;
					break;
				}
			}
			if (is_valid) 
				sum += w.length();
		}
		return sum;
    }
};
int main()
{}

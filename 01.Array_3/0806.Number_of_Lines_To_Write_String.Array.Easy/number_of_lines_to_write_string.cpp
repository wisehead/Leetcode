/*******************************************************************************
 *      file name: number_of_lines_to_write_string.cpp                                               
 *         author: Hui Chen. (c) 2018                             
 *           mail: chenhui13@baidu.com                                        
 *   created time: 2018/11/06-12:42:45                              
 *  modified time: 2018/11/06-12:42:45                              
 *******************************************************************************/
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    vector<int> numberOfLines(vector<int>& widths, string S) {
		int len = S.length();
		vector<int> res;
		int lines = 0, char_count = 0;
		for (int i = 0; i < len; i++)
		{
			int index = S[i] - 'a';
			int width = widths[index];
			char_count += width;
			if (char_count > 100)
			{
				lines++;
				char_count = width;
			}
		}
		if (char_count > 0) lines++;
		res.push_back(lines);
		res.push_back(char_count);
		return res;
    }
};
int main()
{}

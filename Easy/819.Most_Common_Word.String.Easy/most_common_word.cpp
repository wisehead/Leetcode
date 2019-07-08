/*******************************************************************************
 *      file name: most_common_word.cpp                                               
 *         author: Hui Chen. (c) 2018                             
 *           mail: chenhui13@baidu.com                                        
 *   created time: 2018/11/09-17:09:47                              
 *  modified time: 2018/11/09-17:09:47                              
 *******************************************************************************/
#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
using namespace std;
class Solution {
public:
	bool is_alpha(char c) {
		return ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'));
	}
    string mostCommonWord(string paragraph, vector<string>& banned) {
        paragraph = paragraph + "."; 
		int len = paragraph.length();
		set<string> banset;
		map<string, int> dir;
		int pos = 0;
		int old_pos = 0;
		int max = 0;
		string maxstr;
		bool char_flag = false;
		for (int i = 0; i < banned.size(); i++)
		{
			string word = banned[i]; 
			transform(word.begin(), word.end(), word.begin(), ::tolower);
			banset.insert(word);
		}

		for (int i = 0; i < len; i++)
		{
			if (is_alpha(paragraph[i]))
			{
                char_flag = true;
			}
			else
			{
				if (char_flag)
				{
					string word = paragraph.substr(old_pos, i - old_pos);
					transform(word.begin(), word.end(), word.begin(), ::tolower);
                    //cout<<"word:"<<word<<endl;
					if (!banset.count(word))
					{
						if (dir.count(word))
							dir[word]++;
						else
							dir[word] = 1;
						if (dir[word] > max) 
						{
							max = dir[word];
							maxstr = word;
						}

					}
				}
				char_flag = false;
				old_pos = i + 1;
			}
		}

		return maxstr;
    }
};
int main()
{}

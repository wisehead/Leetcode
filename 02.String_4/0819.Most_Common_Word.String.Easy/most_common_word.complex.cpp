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
		set<string> banset;
		map<string, int> dir;
		int pos = 0;
		int old_pos = 0;
		int max = 0;
		string maxstr;
		for (int i = 0; i < banned.size(); i++)
		{
			string word = banned[i]; 
			transform(word.begin(), word.end(), word.begin(), ::tolower);
			banset.insert(word);
		}
		while (pos != string::npos)
		{
			string word;
			//pos = paragraph.find(',', old_pos);
			pos = paragraph.find(' ', old_pos);
            //cout<<"old_pos:"<<old_pos<<"    pos:"<<pos<<endl;
            if (pos == old_pos)
            {
                old_pos++;
                continue;
            }
			if (pos == string::npos) 
            {
                word = paragraph.substr(old_pos, paragraph.length() - old_pos );//remove "."
                if (!is_alpha(word[word.length() - 1]))
			    {
				    word = word.substr(0, word.length() - 1);
			    }
            }
			else
				word = paragraph.substr(old_pos, pos - old_pos);
			transform(word.begin(), word.end(), word.begin(), ::tolower);
			int comma_pos = word.find(',', 0);
			if (comma_pos != string::npos)
			{
				word = word.substr(0, comma_pos);
				pos = old_pos + comma_pos;
                //cout<<"pos:"<<pos<<endl;
			}
            
            if (!is_alpha(word[word.length() - 1]))
		    {
			    word = word.substr(0, word.length() - 1);
		    }
            
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
			old_pos = pos;
            if (paragraph[pos] == ' ' ) old_pos++;
            if (paragraph[pos+1] == ' ') old_pos++;
		}
		return maxstr;
    }
};
int main()
{}

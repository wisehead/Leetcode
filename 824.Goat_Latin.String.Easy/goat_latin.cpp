/*******************************************************************************
 *      file name: goat_latin.cpp                                               
 *         author: Hui Chen. (c) 2018                             
 *           mail: chenhui13@baidu.com                                        
 *   created time: 2018/11/10-12:08:59                              
 *  modified time: 2018/11/10-12:08:59                              
 *******************************************************************************/
#include <iostream>
using namespace std;
class Solution {
public:
	bool is_vowel(char c) {
		return (c == 'a' || c == 'e' || c == 'i' ||c == 'o' ||c == 'u' 
				|| c == 'A' || c == 'E' || c == 'I' ||c == 'O' ||c == 'U' );
	}

    string toGoatLatin(string S) {
		int pos = 0;
		int last_pos = 0;
		string res;
		int count = 0;
		while(pos != string::npos)
		{
			string word;
			pos = S.find(' ', last_pos);
			if (pos == string::npos)
			{
				word = S.substr(last_pos, S.length() - last_pos);
			}
			else
			{
				word = S.substr(last_pos, pos - last_pos);
			}
			//cout<<"word:"<<word<<endl;
			last_pos = pos + 1;
			if ( !is_vowel(word[0]))
			{
				char c = word[0];
				word = word.substr(1, word.length() - 1);
				word += c;
			}
			word += "ma";
			count++;
			for (int i = 0; i < count; i++)
			{
				word += "a";
			}
			res += word + " ";
			//cout<<"res:"<<res<<endl;
		}
		return res.substr(0, res.length() - 1);
    }
};
int main()
{}

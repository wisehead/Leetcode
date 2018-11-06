/*******************************************************************************
 *      file name: unique_morse_code_words.cpp                                               
 *         author: Hui Chen. (c) 2018                             
 *           mail: chenhui13@baidu.com                                        
 *   created time: 2018/11/06-11:43:29                              
 *  modified time: 2018/11/06-11:43:29                              
 *******************************************************************************/
#include <iostream>
#include <map>
#include <set>
#include <vector>
using namespace std;
class Solution {
public:
/*
[".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."]
*/
    int uniqueMorseRepresentations(vector<string>& words) {
		string morse_codes[26]= {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
		map<char, string> dir;
		set<string> res;
		char x = 'a';
		for (int i = 0; i < 26; i++, x++)
		{
			dir[x] = morse_codes[i];
		}
		int len = words.size();
		for (int i=0; i < len; i++)
		{
			string word = words[i];
			int word_len = word.length();
			string result;
			for (int j=0; j < word_len; j++)
			{
				result += dir[word[j]];
			}
			res.insert(result);
		}
		return res.size();

    }
};
int main()
{}

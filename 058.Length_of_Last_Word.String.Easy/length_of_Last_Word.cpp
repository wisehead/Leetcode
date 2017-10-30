/*******************************************************************************
 *      file name: length_of_Last_Word.cpp                                               
 *         author: hui chen. (c) 17                             
 *           mail: chenhui13@baidu.com                                        
 *   created time: 17/10/30-10:10                                    
 * modified time: 17/10/30-10:10                                    
 *******************************************************************************/
#include <iostream>
#include <string>
using namespace std;
class Solution {
public:
    int lengthOfLastWord(string s) {
		cout<<endl<<"input string is:"<<s<<endl;
		int len = s.length();
		if (len < 1)
			return 0;
		int start_pos = len - 1;
		for (;start_pos >= 0;start_pos--)
		{
			if (s[start_pos] != ' ')
				break;
		}
		cout<<"start_pos is:"<<start_pos<<endl;
		if (start_pos < 0)
			return 0;
		//s.rfind();
		//int find_last_of(char c, int pos = npos) const;
		int pos = -1;
		pos = s.find_last_of(' ', start_pos);
		cout<<"last of space is:"<<pos<<endl;
		//cout<<"start_pos is:"<<start_pos<<endl;
		if (pos == -1)
		{
			if (start_pos >= 0)
				return start_pos - pos;
			else
				return 0;
		}
		return start_pos - pos;
    }
};

int main()
{
	Solution sol;
	int len_last_word = 0;
	len_last_word =sol.lengthOfLastWord("Hello World");
	cout <<"last word length is: "<<len_last_word<<endl;
	len_last_word =sol.lengthOfLastWord("HelloWorld");
	cout <<"last word length is: "<<len_last_word<<endl;
	len_last_word =sol.lengthOfLastWord("Hello World ");
	cout <<"last word length is: "<<len_last_word<<endl;
	len_last_word =sol.lengthOfLastWord(" HelloWorld");
	cout <<"last word length is: "<<len_last_word<<endl;
	len_last_word =sol.lengthOfLastWord(" ");
	cout <<"last word length is: "<<len_last_word<<endl;
	len_last_word =sol.lengthOfLastWord("");
	cout <<"last word length is: "<<len_last_word<<endl;
	len_last_word =sol.lengthOfLastWord("s");
	cout <<"last word length is: "<<len_last_word<<endl;
	len_last_word =sol.lengthOfLastWord("                   ");
	cout <<"last word length is: "<<len_last_word<<endl;
}

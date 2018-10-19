/*******************************************************************************
 *      file name: shortest_completing_word.cpp                                               
 *         author: Hui Chen. (c) 2018                             
 *           mail: chenhui13@baidu.com                                        
 *   created time: 2018/10/19-18:22:18                              
 *  modified time: 2018/10/19-18:22:18                              
 *******************************************************************************/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
	bool isLetter(char c) {
		return ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'));
	}
    string shortestCompletingWord(string licensePlate, vector<string>& words) {
		string letters = licensePlate;
		string result;
		string::iterator it;
		for (it = letters.begin(); it != letters.end(); it++)
		{
			if (!isLetter(*it)) {
				letters.erase(it);
				it--;
			}
		}
		transform(letters.begin(), letters.end(), letters.begin(), ::tolower);
		cout<<"letters:"<<letters<<endl;
		int len = words.size();
		for (int i = 0; i < len; i++)
		{
			string temp = words[i];
			int j = 0;
			for (j = 0; j < letters.size(); j++)
			{
				int pos = temp.find(letters[j]);
				//cout<<"pos:"<<pos<<endl;
				if (pos == string::npos) 
					break;
				temp[pos] = '0';
			}
			if (j == letters.size())
			{
				if(result.length() == 0) 
					result = words[i];
				else
				{
					if (temp.length() < result.length())
						result = words[i];
				}
				cout<<"result:"<<result<<endl;
			}
		}
		return result;
    }
};
int main()
{
	//string input = "1s3 PSt";
	string input = "1s3 456";
	//string arr[4] = {"step", "steps", "stripe", "stepple"};
	string arr[4] = {"looks", "pest", "stew", "show"};
	vector<string> vec(arr, arr+4);
	Solution sol;
	sol.shortestCompletingWord(input, vec);
}

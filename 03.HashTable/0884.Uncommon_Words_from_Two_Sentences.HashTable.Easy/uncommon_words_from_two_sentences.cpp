/*******************************************************************************
 *      file name: uncommon_words_from_two_sentences.cpp                                               
 *         author: Hui Chen. (c) 2019                             
 *           mail: chenhui13@baidu.com                                        
 *   created time: 2019/01/09-13:50:01                              
 *  modified time: 2019/01/09-13:50:01                              
 *******************************************************************************/
#include <iostream>
#include <map>
#include <vector>
using namespace std;
class Solution {
public:
    vector<string> uncommonFromSentences(string A, string B) {
		vector<string> res;
		map<string, int> m;
		string a = " " + A + " " + B + " ";
		int last_pos = 0, pos = 1;
		for (int i=0; i<A.length(); i++)
		{
			pos = a.find(' ', last_pos+1);
			if (pos != string::npos)
			{
				string temp = a.substr(last_pos + 1, pos - last_pos - 1);
				cout<<"a temp:"<<temp<<endl;
				if (m.count(temp))
					m[temp]++;
				else
					m[temp] = 0;

				last_pos = pos;
			}
		}

		map<string, int>::iterator iter;
		for(iter = m.begin(); iter != m.end(); iter++)
		{
			if (iter->second == 0)
			{
				cout<<iter->first<<"	"<<iter->second<<endl;
				res.push_back(iter->first);
			}
		}
		return res;
    }
};
int main()
{
	Solution sol;
	string A = "this apple is sweet", B = "this apple is sour"; 
	vector<string> res;
	res = sol.uncommonFromSentences(A, B);
}

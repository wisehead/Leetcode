/*******************************************************************************
 *      file name: rearrange_spaces_between_words.cpp                                               
 *         author: Hui Chen. (c) 2022                             
 *           mail: alex.chenhui@gmail.com                                        
 *   created time: 2022/01/04-10:38:07                              
 *  modified time: 2022/01/04-10:38:07                              
 *******************************************************************************/
#include <iostream>
#include <vector>
#include <sstream>
using namespace std;
class Solution {
public:
	string reorderSpaces(string text) {
		string s, ans;
		vector<string> words;
		istringstream iss(text);
		while(iss>>s) words.push_back(s);
		int space = count(text.begin(), text.end(), ' ');
		int n = words.size();
		int quot = n==1?0:space/(n-1),
			rem = n==1?space:space%(n-1);
		for(auto &w:words){
		  if(!ans.empty())  ans+=string(quot,' ');
		  ans+=w;
		}
		ans+=string(rem,' ');
		return ans;
	}
};
int main()
{}

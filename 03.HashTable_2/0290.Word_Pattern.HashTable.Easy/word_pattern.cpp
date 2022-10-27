/*******************************************************************************
 *      file name: word_pattern.cpp                                               
 *         author: Hui Chen. (c) 18                             
 *           mail: chenhui13@baidu.com                                        
 *   created time: 18/01/04- 1:01                                    
 *  modified time: 18/01/04- 1:01                                    
 *******************************************************************************/
#include <iostream>
#include <map>
#include <vector>
using namespace std;
class Solution {
public:
    bool wordPattern(string pattern, string str) {
		map<string,char> m;
		map<char,string> m2;
		vector<string> vec;
		int start = 0;
		int end = 0;
		while (start < str.length())
		{
			end = str.find(" ", start);
			if (end == string::npos)
				break;
			//cout<<"start is:"<<start<<" 	end is:"<<end<<endl;
			string sub = str.substr(start, end - start);
			//cout<<"sub is:"<<sub<<endl;
			vec.push_back(sub);
			start = end+1;
		}
		if (end == string::npos)
		{
			//cout<<"start is:"<<start<<" 	end is:"<<end<<endl;
			string sub = str.substr(start, str.length() - start);
			//cout<<"sub is:"<<sub<<endl;
			vec.push_back(sub);
		}
		if (pattern.length() != vec.size())
			return false;

		for (int i=0; i<pattern.length(); i++)
		{
			map<string,char>::iterator it;
			it = m.find(vec[i]);
			if (it == m.end())
			{
				//cout<<"m not found!!!!inserted . key:"<<vec[i]<<" 		value:"<<pattern[i]<<endl;
				m.insert(map<string, char>::value_type (vec[i], pattern[i]));
			}
			else
			{
				//cout<<"m found!!!!key:"<<vec[i]<<"		value in vec:"<<it->second<<"	value in pattern:"<<pattern[i]<<endl;
				if (it->second != pattern[i])
					return false;
			}
			map<char,string>::iterator it2;
			it2 = m2.find(pattern[i]);
			if (it2 == m2.end())
			{
				//cout<<"m2 not found!!!!inserted . key:"<<pattern[i]<<" 		value:"<<vec[i]<<endl;
				m2.insert(map<char,string>::value_type (pattern[i], vec[i]));
			}
			else
			{
				//cout<<"m2 found!!!!key:"<<pattern[i]<<"		value in pattern:"<<it2->second<<"	value in vec:"<<vec[i]<<endl;
				if (it2->second != vec[i])
					return false;
			}

		}

		return true;
    }
};
int main()
{
	Solution sol;
	//string str ="dog cat cat dog";
	//string str ="dog cat cat fish";
	//string str ="dog cat cat dog";
	string str ="dog dog dog dog";
	string pattern = "abba";
	//string pattern = "aaaa";
	bool ret = false;
	ret = sol.wordPattern(pattern, str);
	cout<<"result is:"<<ret<<endl;
}

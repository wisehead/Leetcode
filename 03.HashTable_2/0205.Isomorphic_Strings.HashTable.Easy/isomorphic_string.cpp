/*******************************************************************************
 *      file name: isomorphic_string.cpp                                               
 *         author: Hui Chen. (c) 17                             
 *           mail: chenhui13@baidu.com                                        
 *   created time: 17/12/24-12:12                                    
 *  modified time: 17/12/24-12:12                                    
 *******************************************************************************/
#include <iostream>
#include <map>
#include <set>
using namespace std;
class Solution {
public:
    bool isIsomorphic(string s, string t) {
		map<char, char> maps;
		set<char> sets;
		string::iterator it_s;
		string::iterator it_t;
		int len = s.length();
		for (int i=0; i<len; i++)
		{
			cout<<"s["<<i<<"]"<<s[i]<<endl;
			cout<<"t["<<i<<"]"<<t[i]<<endl;
		    map<char, char>::iterator iter;
		    iter = maps.find(s[i]);
			if(iter != maps.end())
			{
			    cout<<"Find, the value is "<<iter->second<<endl;
				if (iter->second != t[i])
				{
					cout<<"not equal"<<endl;
					return false;
				}
			}
			else
			{
				set<char>::iterator iter_set;
				if((iter_set = sets.find(t[i])) != sets.end())
				{
					return false;
				}
				sets.insert(t[i]);
				maps.insert(pair<char, char>(s[i], t[i]));
			}
		}
		return true;
    }
};
int main()
{
	Solution sol;
	bool ret = false;
	string str1 = "egg";
	string str2= "add";
	//ret = sol.isIsomorphic("egg","add");
	ret = sol.isIsomorphic(str1,str2);
	cout<<str1<<","<<str2<<":"<<ret<<endl;
	str1 = "paper";
	str2= "title";
	//ret = sol.isIsomorphic("egg","add");
	ret = sol.isIsomorphic(str1,str2);
	cout<<str1<<","<<str2<<":"<<ret<<endl;
	str1 = "foo";
	str2= "bar";
	//ret = sol.isIsomorphic("egg","add");
	ret = sol.isIsomorphic(str1,str2);
	cout<<str1<<","<<str2<<":"<<ret<<endl;
	str1 = "ab";
	str2= "aa";
	//ret = sol.isIsomorphic("egg","add");
	ret = sol.isIsomorphic(str1,str2);
	cout<<str1<<","<<str2<<":"<<ret<<endl;
}

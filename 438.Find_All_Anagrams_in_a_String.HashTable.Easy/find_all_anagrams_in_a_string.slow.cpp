/*******************************************************************************
 *      file name: find_all_anagrams_in_a_string.cpp                                               
 *         author: Hui Chen. (c) 18                             
 *           mail: chenhui13@baidu.com                                        
 *   created time: 18/06/27- 6:06                                    
 *  modified time: 18/06/27- 6:06                                    
 *******************************************************************************/
#include <iostream>
#include <map>
#include <vector>
using namespace std;
class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
    	vector<int> vec;
        if (s.length() == 0 || p.length() == 0 || s.length() < p.length())
            return vec;
       map<char, int> m, m2;
	   string::iterator it;
	   for (it = p.begin(); it != p.end(); it++)
	   {
		   char c = *it;
		   map<char, int>::iterator it_map = m.find(c);
		   if (it_map == m.end())
		   {
			   m[c] = 1;
		   }
		   else
		   {
			   m[c]++;
		   }

	   }

	   for(int i=0; i<s.length() - p.length()+1; i++)
	   {
		   m2 = m;
		   for (int j = 0; j < p.length();  j++)
		   {
			   char c = s[i+j];
			   map<char, int>::iterator it_map = m2.find(c);
			   //cout<<"i:"<<i<<" j:"<<j<<"  value:"<<c<<endl;
			   if (it_map == m2.end())
			   {
			   		//cout<<"not found!!!"<<endl;
				   break;
			   }
			   else
			   {
				   m2[c]--;
				   //cout<<"m2[c]:"<<m2[c]<<endl;
	               if (m2[c] == 0)
	                   m2.erase(c);
	               	if (j == p.length()-1)
			   		{
			   			//cout<<"hahahahhahahhaaha!!!!      i:"<<i<<" j:"<<j<<endl;
			   			vec.push_back(i);
			   		}
			   }
		   }
		}

	   return vec;
        
    }
};
int main()
{
	Solution sol;
	//string s = "cbaebabacd";
	//string p = "abc";
	string s = "abab";
	string p = "ab";
	sol.findAnagrams(s, p);
}

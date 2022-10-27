/*******************************************************************************
 *      file name: valid_anagram.cpp                                               
 *         author: Hui Chen. (c) 17                             
 *           mail: chenhui13@baidu.com                                        
 *   created time: 17/12/30-12:12                                    
 *  modified time: 17/12/30-12:12                                    
 *******************************************************************************/
#include <iostream>
#include <map>
using namespace std;
class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.length() == 0 && t.length() == 0)
            return true;
        if (s.length() == 0 || t.length() == 0)
            return false;
       map<char, int> m;
	   //mapStudent.insert(pair<int, string>(1, “student_one”));
	   string::iterator it;
	   for (it = s.begin(); it != s.end(); it++)
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

	   for (it = t.begin(); it != t.end(); it++)
	   {
		   char c = *it;
		   map<char, int>::iterator it_map = m.find(c);
		   if (it_map == m.end())
		   {
			   return false;
		   }
		   else
		   {
			   m[c]--;
               if (m[c] == 0)
                   m.erase(c);
		   }
	   }
       if (m.size() != 0)
	        return false;
        return true;
    }
};int main()
{
	string s("rat");
	string t("car");
	bool ret;
	Solution sol;
	ret = sol.isAnagram(s, t);
	cout<<"ret for "<<s<<" and "<<t<<" is:"<<ret<<endl;
}

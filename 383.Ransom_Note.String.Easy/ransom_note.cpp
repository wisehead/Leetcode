/*******************************************************************************
 *      file name: ransom_note.cpp                                               
 *         author: Hui Chen. (c) 18                             
 *           mail: chenhui13@baidu.com                                        
 *   created time: 18/01/08- 1:01                                    
 *  modified time: 18/01/08- 1:01                                    
 *******************************************************************************/
#include <iostream>
using namespace std;
class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
		int len1 = ransomNote.length();
		//string::iterator it;
		int pos = 0;
		for (int i = 0; i< len1; i++)
		{
			pos = magazine.find(ransomNote[i]);
			if (pos == string::npos)
				return false;
			magazine = magazine.erase(pos, 1);
			cout<<"magzine is:"<<magazine<<endl;
		}
		return true;
    }
};
int main()
{
	Solution sol;
	string ransomNote = "a";
	string magazine = "b";
	bool ret = false;
	ret = sol.canConstruct(ransomNote, magazine);
	cout<<"ret for ransomNote:"<<ransomNote<<" and magazine:"<<magazine<<" is:"<<ret<<endl;
}

/*******************************************************************************
 *      file name: long_pressed_name.cpp                                               
 *         author: Hui Chen. (c) 2019                             
 *           mail: chenhui13@baidu.com                                        
 *   created time: 2019/01/24-09:47:08                              
 *  modified time: 2019/01/24-09:47:08                              
 *******************************************************************************/
#include <iostream>
using namespace std;
class Solution {
public:
    bool isLongPressedName(string name, string typed) {
		int i = 0, j = 0;
		while (i < name.length() && j < typed.length())
		{
			if (name[i] == typed[j]) 
            {
                i++; j++;
            }
			else if (typed[j] == typed[j-1]) j++;
			else return false;
		}
        if (i == name.length())
        {
            while (typed[j] == typed[j-1] && j < typed.length())j++;
            if (j == typed.length()) return true; 
        }
		return false;
    }
};
int main()
{
	//string name = "alex", typed = "aaleex";
	//string name = "saeed", typed = "ssaaedd";
	//string name = "leelee", typed = "lleeelee";
	string name = "laiden", typed = "laiden";
	Solution sol;
	bool ret = sol.isLongPressedName(name, typed);
	cout<<"ret:"<<ret<<endl;
}

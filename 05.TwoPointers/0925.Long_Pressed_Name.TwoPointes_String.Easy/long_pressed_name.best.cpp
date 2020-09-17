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
        int i = 0, m = name.length(), n = typed.length();
        for (int j = 0; j < n; ++j)
            if (i < m && name[i] == typed[j])
                ++i;
            else if (!j || typed[j] != typed[j - 1])
                return false;
        return i == m;
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

/*******************************************************************************
 *      file name: student_attendance_record_I.cpp                                               
 *         author: Hui Chen. (c) 2018                             
 *           mail: chenhui13@baidu.com                                        
 *   created time: 2018/08/24-09:21:38                              
 *  modified time: 2018/08/24-09:21:38                              
 *******************************************************************************/
#include <iostream>
using namespace std;
class Solution {
public:
    bool checkRecord(string s) {
		int a = 0, l = 0, p = 0;
		int len = s.length();
		for (int i=0; i< len; i++)
		{
			if (s[i] == 'A')
				a++;
			if (s[i] == 'L') 
                l++;
            else
                l = 0;
            if (a > 1 || l > 2)
             return false;
		}
        return true;
    }
};
int main()
{}

/*******************************************************************************
 *      file name: rotate_string.cpp                                               
 *         author: Hui Chen. (c) 2018                             
 *           mail: chenhui13@baidu.com                                        
 *   created time: 2018/11/06-10:49:46                              
 *  modified time: 2018/11/06-10:49:46                              
 *******************************************************************************/
#include <iostream>
using namespace std;
class Solution {
public:
    bool rotateString(string A, string B) {
		int len_a = A.length();
		int len_b = B.length();
        cout<<"A:"<<A<<"B:"<<B<<endl;
		if (len_a != len_b) return false;
        if (len_a == 0) return true;
		int last_pos = 0; 
		while (last_pos < len_a)
		{
			int pos = A.find(B[0], last_pos);
            cout<<"A:"<<A<<"    B[0]:"<<B[0]<<endl;
            cout<<"pos:"<<pos<<"    last_pos:"<<last_pos<<endl;
			if (pos == string::npos) return false;
			string s1 = A.substr(0, pos);
			string s2 = A.substr(pos, len_a - pos);
			string s = s2 + s1;
            cout<<"S:"<<s<<endl;
			if (s.compare(B) == 0) return true; 
			last_pos = pos+1;
		}
		return false;
    }
};
int main()
{}

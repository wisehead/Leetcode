/*******************************************************************************
 *      file name: reverse_only_letters.cpp                                               
 *         author: Hui Chen. (c) 2019                             
 *           mail: chenhui13@baidu.com                                        
 *   created time: 2019/01/22-11:05:23                              
 *  modified time: 2019/01/22-11:05:23                              
 *******************************************************************************/
#include <iostream>
using namespace std;
class Solution {
public:
	bool is_alpha(char x) {
		return (x >= 'a' && x <= 'z' || x >= 'A' && x <= 'Z');
	}
    string reverseOnlyLetters(string S) {
		int len = S.length();
		for (int i = 0, j = len - 1; i < j; )
		{
            //cout<<"S["<<i<<"]"<<S[i]<<endl;
            //cout<<"S["<<j<<"]"<<S[j]<<endl;
			if (!is_alpha(S[i])) 
            {
                i++;
                continue;
            }
			if (!is_alpha(S[j])) 
            {
                j--;
                continue;
            }
            char temp = S[i];
			S[i] = S[j];
			S[j] = temp;
            //cout<<"S"<<S<<endl;
            i++; j--;
		}
		return S;
    }
};
int main()
{}

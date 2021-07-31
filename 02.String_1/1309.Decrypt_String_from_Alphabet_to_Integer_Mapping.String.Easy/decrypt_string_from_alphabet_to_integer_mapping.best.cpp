/*******************************************************************************
 *      file name: decrypt_string_from_alphabet_to_integer_mapping.cpp                                               
 *         author: Hui Chen. (c) 2021                             
 *           mail: alex.chenhui@gmail.com                                        
 *   created time: 2021/07/31-12:30:38                              
 *  modified time: 2021/07/31-12:30:38                              
 *******************************************************************************/
#include <iostream>
#include <map>
using namespace std;

class Solution {
public:
	string freqAlphabets(string s) {
        string ans="";
        for(int i=0;i<s.length();) {
            if(i+2<s.length() && s[i+2]=='#') {
                int ss=(s[i]-'0')*10+(s[i+1]-'0');
                ans+=char(ss+'a'-1);
                i+=3;
            }
            else {
                ans+=char(s[i]-'0'-1+'a');
                ++i;
            }
        }
        return ans;
    }

};
int main()
{}

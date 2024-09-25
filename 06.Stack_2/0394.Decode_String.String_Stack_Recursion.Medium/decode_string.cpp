/*******************************************************************************
 *      file name: decode_string.cpp                                               
 *         author: Hui Chen. (c) 2021                             
 *           mail: alex.chenhui@gmail.com                                        
 *   created time: 2021/11/21-20:58:17                              
 *  modified time: 2021/11/21-20:58:17                              
 *******************************************************************************/
#include <iostream>
#include <vector>
#include <stack>
using namespace std;
class Solution {
public:
    bool is_digit(char c) {
        return (c >= '0' && c <= '9');
    }
    
    bool is_alpha(char c) {
        return (c >= 'a' && c <= 'z');
    }
    
    string decodeString(string s) {
        //cout<<"s:"<<s<<endl;
        string res;
        int N = s.length();
        for (int i = 0; i < N; ) {
            if (is_alpha(s[i])) {
                res += s[i];
                i++;
            } else if (is_digit(s[i])) {
                string num;
                while (is_digit(s[i])) {
                    num += s[i];
                    i++;
                }
                int cnt = stoi(num);
                stack<char> st;
                int end = 0;
                for (int j = i; j < N; j++) {
                    if (s[j] == '[') st.push(s[j]);
                    else if (s[j] == ']') {
                        st.pop();
                        if (st.empty()) {
                            end = j-1;
                            break;
                        }
                    }
                }
                string temp = decodeString(s.substr(i+1,end-i));
                while (cnt) {
                    res += temp;
                    cnt--;
                }
                i = end+2;
            } 
        }
        return res;
    }
};
int main()
{}

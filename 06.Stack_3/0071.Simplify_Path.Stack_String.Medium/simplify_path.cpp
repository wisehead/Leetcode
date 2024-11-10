/*******************************************************************************
 *      file name: simplify_path.cpp                                               
 *         author: Hui Chen. (c) 2020                             
 *           mail: chenhui13@baidu.com                                        
 *   created time: 2020/10/30-16:01:58                              
 *  modified time: 2020/10/30-16:01:58                              
 *******************************************************************************/
#include <iostream>
#include <vector>
#include <stack>
using namespace std;
class Solution {
public:
    string simplifyPath(string path) {
        stack<string> st;
        string token = get_token(path);
        while (pos != string::npos || token.length() > 0) {
            if (token == "") {
                //do nothing;
            } else if (token == "..") {
                if (st.size() > 1) {
                    st.pop(); st.pop();
                }
            } else if (token == ".") {
                //continue;
            } else {
                st.push("/");
                st.push(token);
            } 
            token = get_token(path);
        }

        vector<string> vec;
        while (!st.empty()) {
            string str = st.top();
            st.pop();
            vec.insert(vec.begin(), str);
        }
        
        string res;
        for (auto e : vec) {
            res += e;
        }
        if (res.length() == 0) res = "/";
        return res;
    }
    string get_token(string str) {
        if (pos == string::npos) return "";
        int index = str.find('/', pos+1);
        if (index == string::npos) {
            index = pos;
            pos = string::npos;
            return str.substr(index+1);
        }
        string s = str.substr(pos+1, index-pos-1);
        pos = index;
        return s;
    }    
private:
    int pos;
};
int main()
{}

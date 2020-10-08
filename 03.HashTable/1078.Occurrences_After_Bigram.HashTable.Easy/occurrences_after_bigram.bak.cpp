/*******************************************************************************
 *      file name: occurrences_after_bigram.cpp                                               
 *         author: Hui Chen. (c) 2020                             
 *           mail: chenhui13@baidu.com                                        
 *   created time: 2020/10/08-22:01:05                              
 *  modified time: 2020/10/08-22:01:05                              
 *******************************************************************************/
#include <iostream>
using namespace std;
class Solution {
public:
    string get(string str, int pos) {
        int i = pos;
        for (; i < str.length(); i++)
        {
            if (str[i] == ' ' || str[i] == '\n') break;
        }
        if( i != pos) return str.substr(pos, i-pos);
        return string("");
    }
    vector<string> findOcurrences(string text, string first, string second) {
        cout<<"text length:"<<text.length()<<endl;
        vector<string> vec;
        vector<string> res;
        text = " " + text;
        string word = " " + first + " " + second;
        int pos = 0;
        while (pos != string::npos && pos < text.length()) {
            pos = text.find(word, pos);
            cout<<"1 pos:"<<pos<<endl;
            if (pos != string::npos) 
            {
                pos = pos + word.length() + 1;
                cout<<"2 pos:"<<pos<<endl;
                if (pos < text.length()) {
                    string tmp = get(text, pos);
                    if (tmp != string(""))
                        res.push_back(tmp);
                }
                    
            }
        }
        return res;
        
    }
};
int main()
{}

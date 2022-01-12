/*******************************************************************************
 *      file name: longest_absolute_file_path.cpp                                               
 *         author: Hui Chen. (c) 2022                             
 *           mail: alex.chenhui@gmail.com                                        
 *   created time: 2022/01/12-11:41:27                              
 *  modified time: 2022/01/12-11:41:27                              
 *******************************************************************************/
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int lengthLongestPath(string input) {
        int last_pos = 0, pos = 0, start_pos = 0;
        string s = input;
        pos = s.find("\n");
        if (pos == string::npos) return fix_dir(s);
        s += "\n";
        int ret = 0;
        while (1) {
            pos = s.find("\n", last_pos);
            if (pos == string::npos) break;
            if (pos + 1 < s.length() && s[pos+1] == '\t') {
                last_pos = pos+1; 
                continue;
            }
           
            //find it 
            string sub = s.substr(start_pos, pos-start_pos);
            int temp = fix_dir(sub);
            if (temp > ret) ret = temp;
            last_pos = pos+1;
            start_pos = last_pos;
        }
        return ret;        
    }
    int fix_dir(string input) {
        //cout<<"input:"<<input<<endl;
        int ret = 0;
        if (!input.length()) return 0;
        string s = input;
        int pos = 0;
        pos = s.find("\n\t");
        // the filename or leaf dir
        if (pos == string::npos) {
            if (is_file(s)) return fix_files(s);
            return 0;
        } 
        string dir = s.substr(0,pos);
        
        int last_pos = pos+2;
        int start_pos = last_pos;
        s += "\n\t";
       
        while (1) {
            pos = s.find("\n\t", last_pos);
            //cout<<"last_pos:"<<last_pos<<",pos:"<<pos<<endl;
            if (pos != string::npos) {
                if (pos+2 < s.length() && input[pos+2] == '\t') {
                    last_pos = pos+2;
                    continue;
                } else {
                    string sub = s.substr(start_pos, pos-start_pos);
                    sub = fun(sub);
                    //cout<<"sub:"<<sub<<endl;
                    int temp = fix_dir(sub);
                    if (temp > ret) ret = temp;
                    last_pos = pos+2;
                    start_pos = last_pos;
                }
                
            } else 
                break;
            
        } 
        //cout<<"-------5---ret:"<<dir.length()+1+ret<<endl;
        if (ret > 0) ret = dir.length()+1+ret;
        return ret;
    }
    
    bool is_file(string str) {
        int pos = str.find(".");
        return pos != string::npos;
    }
    
    string fun(string str) {
        for (int i = 0; i < str.length(); i++) {
            if (str[i] == '\n') str.erase(str.begin()+i+1);
        }
        return str;
    }
    
    int fix_files (string s) {
        int last_pos = 0, pos = 0;
        pos = s.find("\n");
        if (pos == string::npos) return s.length();
        last_pos = pos+1;
        string file = s.substr(0,pos);
        int ret = file.length();
        s += "\n";
        while (1) {
            pos = s.find("\n", last_pos);
            if (pos == string::npos) break;
            string sub = s.substr(last_pos, pos-last_pos);
            if (sub.length() > ret) ret = sub.length();
            last_pos = pos+1;
        }
        return ret;
    }
};
int main()
{}

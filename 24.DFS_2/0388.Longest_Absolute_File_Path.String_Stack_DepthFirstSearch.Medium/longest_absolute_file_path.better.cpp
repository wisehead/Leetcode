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
        vector<string> vec = split(input, "\n", '\t');
        int ret = 0;
        for (auto sub : vec) {
            int temp = fix_dir(sub);
            if (temp > ret) ret = temp;
        }
        return ret;
    }

    int fix_dir(string input) {
        vector<string> vec = split(input, "\n\t", '\t');
        int ret = 0;
        if (vec.size() == 1) {
            if (is_file(input)) return input.length();
            return 0;
        }
        string dir = vec[0];
        for (int i = 1; i < vec.size(); i++) {
            string sub = vec[i];
            sub = fun(sub);
            int temp = fix_dir(sub);
            if (temp > ret) ret = temp;
        }
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

    std::vector<std::string> split(std::string str,std::string pattern, char valid)
    {
        std::string::size_type pos;
        std::vector<std::string> result;
        str+=pattern;//扩展字符串以方便操作
        int size=str.size();
        int ps = pattern.size();
        int last_pos = 0;

        for(int i=0; i<size; i++)
        {
            pos=str.find(pattern,i);
            if(pos<size)
            {
                if (pos+ps < size && str[pos+ps] == valid) continue;
                std::string s=str.substr(last_pos,pos-last_pos);
                result.push_back(s);
                i=pos+pattern.size()-1;
                last_pos = pos + ps;
            }
        }
        return result;
    }
};
int main()
{}

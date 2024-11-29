/*******************************************************************************
 *      file name: rearrange_spaces_between_words.cpp                                               
 *         author: Hui Chen. (c) 2022                             
 *           mail: alex.chenhui@gmail.com                                        
 *   created time: 2022/01/04-10:38:07                              
 *  modified time: 2022/01/04-10:38:07                              
 *******************************************************************************/
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    string reorderSpaces(string text) {
        int spaces = 0;
        int N = text.length();
        for (int i = 0; i < N; i++) {
            char c = text[i];
            if (c != ' ') {
                continue;
            }
            while (c == ' ' && i < N) {
                spaces++;
                i++;
                c = text[i];
            } 
            
        }
        vector<string> res = split(text, " ");
        int words = res.size();
        int steps = 0;
        int remains = 0;          
        if (words == 1) {
            remains = spaces;
        } 
        else 
        {
            steps = spaces / (words-1);
            remains = spaces % (words-1);           
        }

        //cout<<"spaces:"<<spaces<<",words:"<<words<<endl;
        //cout<<"steps:"<<steps<<",remains:"<<remains<<endl;
        string pad;
        string ans;
        for (int i = 0 ;i < steps; i++) {
            pad += " ";
        }
        for (int i = 0; i < words; i++) {
            string str = res[i];
            //cout<<"i:"<<i<<",str:"<<str<<endl;
            ans += str;
            if (i != words-1)
                ans += pad;
        }
        for (int i = 0; i < remains; i++) 
            ans += " ";
        return ans;
        
    }
    
std::vector<std::string> split(std::string str, std::string pattern)
{
    std::string::size_type pos;
    std::vector<std::string> result;
    str += pattern;//扩展字符串以方便操作
    int size = str.size();
    for (int i = 0; i < size; i++)
    {
        if (str[i] == ' ') continue;
        pos = str.find(pattern, i);
        if (pos < size)
        {
            std::string s = str.substr(i, pos - i);
            result.push_back(s);
            i = pos + pattern.size() - 1;
        }
    }
    return result;
}    
};
int main()
{}

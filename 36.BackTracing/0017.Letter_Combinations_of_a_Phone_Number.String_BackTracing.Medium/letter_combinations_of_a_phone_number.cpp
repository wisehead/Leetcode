/*******************************************************************************
 *      file name: letter_combinations_of_a_phone_number.cpp                                               
 *         author: Hui Chen. (c) 2020                             
 *           mail: chenhui13@baidu.com                                        
 *   created time: 2020/10/21-09:41:23                              
 *  modified time: 2020/10/21-09:41:23                              
 *******************************************************************************/
#include <iostream>
#include <vector>
#include <map>
using namespace std;
class Solution {
public:
    Solution() {
        for (char i = '2'; i <= '9'; i++) {
            vector<char> v;
            ht[i] = v;
        }
        for (char x = 'a'; x < 's'; x++) {
            int i = (x - 'a') / 3;
            ht['0'+i+2].push_back(x);
        }
        ht['7'].push_back('s');
        ht['8'].push_back('t');      
        ht['8'].push_back('u');
        ht['8'].push_back('v');
        ht['9'].push_back('w');
        ht['9'].push_back('x');
        ht['9'].push_back('y');
        ht['9'].push_back('z');
    }
    
    vector<string> letterCombinations(string digits) {
        //cout<<"digits:"<<digits<<endl;
        vector<string> res;
        if (digits.length() == 0) return res;
        if (digits.length() == 1) { 
            for (auto x : ht[digits[0]]) {
                string str = string(1, x) ;
                //cout<<"str:"<<str<<endl;
                res.push_back(str);                 
            }                      
            return res;
        }
        char c = digits[0];
        vector<string> vec = letterCombinations(digits.substr(1));
        vector<char> v = ht[c];
        for (auto x : v) {
            for (auto e : vec) {
                string str = string(1, x) + e;
                //cout<<"str:"<<str<<endl;
                res.push_back(str); 
            }            
               
        }

        return res;
    }
private:
    map<char, vector<char>> ht;
};
int main()
{}

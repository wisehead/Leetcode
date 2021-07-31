/*******************************************************************************
 *      file name: maximum_69_number.cpp                                               
 *         author: Hui Chen. (c) 2021                             
 *           mail: alex.chenhui@gmail.com                                        
 *   created time: 2021/07/31-17:00:01                              
 *  modified time: 2021/07/31-17:00:01                              
 *******************************************************************************/
#include <iostream>
using namespace std;
class Solution {
public:
    int maximum69Number (int num) {
        string s = to_string(num);
        int i = s.find('6');
        if (i != string::npos) {
            s[i] = '9';
            int ret = stoi(s);
            return ret;
        }
        return num;
    }
};
int main()
{}

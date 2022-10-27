/*******************************************************************************
 *      file name: thousand_separator.cpp                                               
 *         author: Hui Chen. (c) 2021                             
 *           mail: alex.chenhui@gmail.com                                        
 *   created time: 2021/12/09-20:09:28                              
 *  modified time: 2021/12/09-20:09:28                              
 *******************************************************************************/
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    string thousandSeparator(int n) {
        string str = to_string(n);
        int N = str.length();
        string res;
        for (int i = 0; i < N; i++) {
            if ((N-i) % 3 == 0 && res.length() > 0) {
                res += ".";
            } 
            res += str[i];
        }
        return res;
    }
};
int main()
{}

/*******************************************************************************
 *      file name: 1bit_and_2bit_characters.cpp                                               
 *         author: Hui Chen. (c) 2018                             
 *           mail: chenhui13@baidu.com                                        
 *   created time: 2018/09/22-16:49:44                              
 *  modified time: 2018/09/22-16:49:44                              
 *******************************************************************************/
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    bool isOneBitCharacter(vector<int>& b) {
        bool c;
        for (int i = 0; i < b.size();) {
            if (b[i]) c = 0, i+=2;
            else c = 1, ++i;
        }
        return c;
    }
};
int main()
{}

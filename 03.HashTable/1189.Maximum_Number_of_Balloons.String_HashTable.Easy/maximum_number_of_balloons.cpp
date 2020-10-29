/*******************************************************************************
 *      file name: maximum_number_of_balloons.cpp                                               
 *         author: Hui Chen. (c) 2020                             
 *           mail: chenhui13@baidu.com                                        
 *   created time: 2020/10/29-14:42:37                              
 *  modified time: 2020/10/29-14:42:37                              
 *******************************************************************************/
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int maxNumberOfBalloons(string text) {
        vector<int> vec(26, 0);
        for (int i = 0; i < text.length(); i++) {
            char c = text[i];
            vec[c - 'a']++;
        }
        
        //string str = "balloon";
        int b = vec['b' - 'a'];
        int a = min(b, vec['a' - 'a']);
        int l = min(a, vec['l' - 'a']/2);
        int o = min(l, vec['o' - 'a']/2);
        int n = min(o, vec['n' - 'a']);
        return n;
    }
};
int main()
{}

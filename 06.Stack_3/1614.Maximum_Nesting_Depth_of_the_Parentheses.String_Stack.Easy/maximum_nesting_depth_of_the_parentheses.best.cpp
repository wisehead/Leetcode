/*******************************************************************************
 *      file name: maximum_nesting_depth_of_the_parentheses.cpp                                               
 *         author: Hui Chen. (c) 2022                             
 *           mail: alex.chenhui@gmail.com                                        
 *   created time: 2022/01/08-11:45:46                              
 *  modified time: 2022/01/08-11:45:46                              
 *******************************************************************************/
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int maxDepth(string s) {
        int res = 0, cur = 0;
        for (char& c: s) {
            if (c == '(')
                res = max(res, ++cur);
            if (c == ')')
                cur--;
        }
        return res;
    }
};
int main()
{}

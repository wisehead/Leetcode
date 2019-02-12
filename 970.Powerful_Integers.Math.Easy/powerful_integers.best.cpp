/*******************************************************************************
 *      file name: powerful_integers.cpp                                               
 *         author: Hui Chen. (c) 2019                             
 *           mail: chenhui13@baidu.com                                        
 *   created time: 2019/02/12-09:54:19                              
 *  modified time: 2019/02/12-09:54:19                              
 *******************************************************************************/
#include <iostream>
#include <unordered_set>
#include <vector>

using namespace std;
class Solution {
public:
    vector<int> powerfulIntegers(int x, int y, int bound) {
        unordered_set<int> s;
        for (int i = 1; i <= bound; i *= x) {
            for (int j = 1; i + j <= bound; j *= y) {
                s.insert(i + j);
                if (y == 1) break;
            }
            if (x == 1) break;

        }
        return vector<int>(s.begin(), s.end());
    }
};
int main()
{}

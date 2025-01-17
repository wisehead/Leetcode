/*******************************************************************************
 *      file name: buld_switcher.timeout.cpp                                               
 *         author: Hui Chen. (c) 2021                             
 *           mail: alex.chenhui@gmail.com                                        
 *   created time: 2021/08/10-09:55:16                              
 *  modified time: 2021/08/10-09:55:16                              
 *******************************************************************************/
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int bulbSwitch(int n) {
        vector<int> vec(n,1);
        int sum = 0;
        for (int i = 1; i < n; i++) {
            for (int j = i; j < n; j += (i+1)) {
                vec[j] = 1 - vec[j];
            }
        }
        for (auto e : vec) {
            if (e) ++sum;
        }
        return sum;
    }
};
int main()
{}

/*******************************************************************************
 *      file name: count_numbers_with_unique_digits.cpp                                               
 *         author: Hui Chen. (c) 2020                             
 *           mail: chenhui13@baidu.com                                        
 *   created time: 2020/10/28-17:19:13                              
 *  modified time: 2020/10/28-17:19:13                              
 *******************************************************************************/
#include <iostream>
#include <vector>
#include <math.h>
using namespace std;
class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        vector<bool> used(10,false);
        return doCount(n, used, 0);
    }
    
    int doCount(int n, vector<bool> &used, int d) {
        if (d == n) return 1;
        int total = 1;
        for (int i = (d == 0) ? 1 : 0; i <= 9; i++) {
            if (!used[i]) {
                used[i] = true;
                total += doCount(n, used, d + 1);
                used[i] = false;
            }
        }
        return total;
    }
};
int main()
{}

/*******************************************************************************
 *      file name: find_numbers_with_even_number_of_digits.cpp                                               
 *         author: Hui Chen. (c) 2021                             
 *           mail: chenhui13@baidu.com                                        
 *   created time: 2021/01/17-18:49:53                              
 *  modified time: 2021/01/17-18:49:53                              
 *******************************************************************************/
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    bool check(int n) {
        if (n == 100000) return true;
        if (n >= 10000) return false;
        if (n >= 1000) return true;
        if (n >= 100) return false;
        if (n >= 10) return true;
        return false;
    }
    int findNumbers(vector<int>& nums) {
        int sum  = 0;
        for (auto e : nums) {
            if (check(e)) ++sum;
        }
        return sum;
    }
};
int main()
{}

/*******************************************************************************
 *      file name: convert_integer_to_the_sum_of_two_non_zero_integers.cpp                                               
 *         author: Hui Chen. (c) 2021                             
 *           mail: alex.chenhui@gmail.com                                        
 *   created time: 2021/07/31-16:47:22                              
 *  modified time: 2021/07/31-16:47:22                              
 *******************************************************************************/
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    bool is_valid(int n) {
        while (n) {
            if (n % 10 == 0) return false;
            n /= 10;
        }
        return true;
    }
    vector<int> getNoZeroIntegers(int n) {
        vector<int> res;
        for (int i = 1; i < n/2+1; i++)
        {
            if (is_valid(i) && is_valid(n-i)){
                res.push_back(i);
                res.push_back(n-i);
                break;
            }
        }
        return res;
    }
};
int main()
{}

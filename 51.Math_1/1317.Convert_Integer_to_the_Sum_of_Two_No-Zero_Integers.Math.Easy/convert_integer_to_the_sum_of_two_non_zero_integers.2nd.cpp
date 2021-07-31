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
    vector<int> getNoZeroIntegers(int n) {
        for (int a = 1; a < n; ++a) {
            int b = n - a;
            if (to_string(a).find('0') == string::npos && to_string(b).find('0') == string::npos)
                return {a, b};
        }
        return {}; // unreachable because at least one valid solution
    }
};
int main()
{}

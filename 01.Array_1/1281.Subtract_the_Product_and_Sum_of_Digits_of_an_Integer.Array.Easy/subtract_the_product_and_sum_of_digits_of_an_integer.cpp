/*******************************************************************************
 *      file name: subtract_the_product_and_sum_of_digits_of_an_integer.cpp                                               
 *         author: Hui Chen. (c) 2021                             
 *           mail: chenhui13@baidu.com                                        
 *   created time: 2021/01/03-20:00:59                              
 *  modified time: 2021/01/03-20:00:59                              
 *******************************************************************************/
#include <iostream>
using namespace std;

class Solution {
public:
    int subtractProductAndSum(int n) {
        int product = 1, sum = 0;
        while (n > 0) {
            int x = n % 10;
            product *= x;
            sum += x;
            n = n / 10;
        }
        return product - sum;
    }
};
int main()
{}

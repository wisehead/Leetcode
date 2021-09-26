/*******************************************************************************
 *      file name: number_of_steps_to_reduce_a_number_to_zero.cpp                                               
 *         author: Hui Chen. (c) 2020                             
 *           mail: chenhui13@baidu.com                                        
 *   created time: 2020/10/29-17:32:43                              
 *  modified time: 2020/10/29-17:32:43                              
 *******************************************************************************/
#include <iostream>
using namespace std;
class Solution {
public:
    int numberOfSteps (int num) {
        int cnt = 0;
        while (num) {
            if (num & 1) --num;
            else num = num>>1;;
            ++cnt;
        }
        return cnt;
    }
};
int main()
{}

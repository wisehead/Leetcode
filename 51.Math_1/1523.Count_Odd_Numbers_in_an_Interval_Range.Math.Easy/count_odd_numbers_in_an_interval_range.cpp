/*******************************************************************************
 *      file name: count_odd_numbers_in_an_interval_range.cpp                                               
 *         author: Hui Chen. (c) 2021                             
 *           mail: alex.chenhui@gmail.com                                        
 *   created time: 2021/11/30-09:40:44                              
 *  modified time: 2021/11/30-09:40:44                              
 *******************************************************************************/
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int countOdds(int low, int high) {
        if (high % 2) high++;
        if (low % 2) low--;
        return (high-low)/2;
    }
};
int main()
{}

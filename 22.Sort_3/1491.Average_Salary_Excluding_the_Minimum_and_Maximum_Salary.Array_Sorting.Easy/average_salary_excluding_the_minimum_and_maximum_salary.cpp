/*******************************************************************************
 *      file name: average_salary_excluding_the_minimum_and_maximum_salary.cpp                                               
 *         author: Hui Chen. (c) 2021                             
 *           mail: alex.chenhui@gmail.com                                        
 *   created time: 2021/11/22-09:59:29                              
 *  modified time: 2021/11/22-09:59:29                              
 *******************************************************************************/
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    double average(vector<int>& salary) {
        int big = -1;
        int small = INT_MAX;
        int sum = 0;
        for (auto e : salary) {
            if (e > big) big = e;
            if (e < small) small = e;
            sum += e;
        }
        double ave = (double)(sum - big - small)/(salary.size()-2);
        return ave;
    }
};
int main()
{}

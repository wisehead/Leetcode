/*******************************************************************************
 *      file name: day_of_the_year.cpp                                               
 *         author: Hui Chen. (c) 2020                             
 *           mail: chenhui13@baidu.com                                        
 *   created time: 2020/10/29-14:27:26                              
 *  modified time: 2020/10/29-14:27:26                              
 *******************************************************************************/
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    Solution() {
       vec.resize(12, 0);
       vec = {31,28,31,30,31,30,31,31,30,31,30,31};
    }
    
    int dayOfYear(string date) {
        int year = std::stoi(date.substr(0,4));
        int month = std::stoi(date.substr(5,2));
        int day = std::stoi(date.substr(8,2));
        int sum = 0;
        for (int i = 0; i < month-1; i++) {
            sum += vec[i];
            if (i == 1 && is_leap(year)) sum++;
        }
        sum += day;
        return sum;
    }
    
    bool is_leap(int year) {
        if (year % 4 == 0) {
            if (year % 100 == 0) {
                if (year % 400 == 0) return true;
                return false;
            }
            return true;
        }
        return false;
    }
private:
    vector<int> vec;
};
int main()
{}

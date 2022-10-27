/*******************************************************************************
 *      file name: number_of_days_between_two_dates.cpp                                               
 *         author: Hui Chen. (c) 2021                             
 *           mail: alex.chenhui@gmail.com                                        
 *   created time: 2021/08/30-10:32:42                              
 *  modified time: 2021/08/30-10:32:42                              
 *******************************************************************************/
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int days_in_month[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31,30,  31,30,31 };
    int days[13] =          {0, 31, 59, 90, 120,151,181,212,243,273,304,334,365};
    bool is_leap_year(int year) {
        if (year % 4 != 0) return false;
        if (year % 100 == 0 && year % 400 != 0) return false;
        return true;
    }
    int daysBetweenDates(string date1, string date2) {
        if (date1 > date2) {
            string temp = date1;
            date1 = date2;
            date2 = temp;
        } 
        int year1 = stoi(date1.substr(0, 4));
        int month1 = stoi(date1.substr(5, 2));
        int day1 = stoi(date1.substr(8, 2));
        int year2 = stoi(date2.substr(0, 4));
        int month2 = stoi(date2.substr(5, 2));
        int day2 = stoi(date2.substr(8, 2)); 
        
        int sum1 = days[month1-1] + day1;
        if (is_leap_year(year1) && month1 >= 3) sum1++;
        
        int sum2 = 0;
        for (int y = year1; y < year2; y++) {
            sum2 += 365;
            if (is_leap_year(y)) sum2++;
        }
        
        sum2 += days[month2-1] + day2;
        if (is_leap_year(year2) && month2 >= 3) sum2++;
        
        return sum2 - sum1;
    }
};
int main()
{}

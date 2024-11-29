/*******************************************************************************
 *      file name: day_of_the_week.cpp                                               
 *         author: Hui Chen. (c) 2020                             
 *           mail: chenhui13@baidu.com                                        
 *   created time: 2020/01/24-09:11:54                              
 *  modified time: 2020/01/24-09:11:54                              
 *******************************************************************************/
#include <iostream>
using namespace std;
class Solution {
public:
	bool is_leap_year(int year) {
		return ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0));
	}

    string dayOfTheWeek(int day, int month, int year) {
		string out[] = {"Thursday", "Friday", "Saturday","Sunday", "Monday", "Tuesday", "Wednesday"};
		int months[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
		int cnt = 0;
		for (int i = 1971; i < year; i++)
		{
			if (is_leap_year(i))
				cnt += 366;
			else 
				cnt += 365;
		}
		
		for (int i = 1; i < month; i++)
		{
			cnt += months[i-1];
			if (i == 2 && is_leap_year(year))
				cnt++;
		}
		cnt += day;
		return out[cnt  % 7];
    }
};
int main()
{
	Solution sol;
	//string res = sol.dayOfTheWeek(1,1,1971);
	//string res = sol.dayOfTheWeek(6,5,1971);
	//string res = sol.dayOfTheWeek(31,8,2019);
	string res = sol.dayOfTheWeek(31,8,2019);
	//string res = sol.dayOfTheWeek(31,8,1990);
	cout<<"res:"<<res<<endl;

}

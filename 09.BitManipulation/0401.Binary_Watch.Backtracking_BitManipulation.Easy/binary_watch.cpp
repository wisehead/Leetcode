/*******************************************************************************
 *      file name: binary_watch.cpp                                               
 *         author: Hui Chen. (c) 18                             
 *           mail: chenhui13@baidu.com                                        
 *   created time: 18/01/27- 1:01                                    
 *  modified time: 18/01/27- 1:01                                    
 *******************************************************************************/
#include <iostream>
#include <vector>
#include <string>
#include<sstream>
using namespace std;
class Solution {
public:
    vector<string> readBinaryWatch(int num) {
		vector<string> vec;
		unsigned int hour = 0, minute = 0;
		unsigned int mask = 0;
		int count_4_hour = 0;
		int count_4_minute = 0;
		for (int h = 0; h < 12; h++)
		{
		    count_4_hour = 0;
			for (int i = 0; i < 4; i++)
			{
				mask = 1 << i;
				if ((h & mask) != 0)
					count_4_hour++;
			}
			for (int m = 0; m < 60; m++)
			{
				count_4_minute = 0;
				for (int i = 0; i < 6; i++)
				{
					mask = 1 << i;
					if ((m & mask) != 0)
						count_4_minute++;
				}
				if (count_4_hour + count_4_minute == num)
				{
					stringstream ss_h,ss_m;  
					string str_h, str_m;
					ss_h<<h;
					ss_h>>str_h;
					ss_m<<m;
					ss_m>>str_m;
					if(str_m.length() == 1)
						str_m = "0" + str_m;
					string time = str_h + ":" + str_m; 
					cout<<"current time is:"<<time<<endl;
					vec.push_back(time);
				}
			}
		}
		return vec;
    }
};
int main()
{
	Solution sol;
	vector<string> ret;
	ret = sol.readBinaryWatch(1);
}

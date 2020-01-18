/*******************************************************************************
 *      file name: corporate_flight_bookings.cpp                                               
 *         author: Hui Chen. (c) 2020                             
 *           mail: chenhui13@baidu.com                                        
 *   created time: 2020/01/18-16:05:07                              
 *  modified time: 2020/01/18-16:05:07                              
 *******************************************************************************/
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
		vector<int> vec(n, 0);
		for (auto e : bookings)
		{
			for (int i = e[0]-1; i <= e[1]-1; i++)
            {
                //cout<<"vec["<<i<<"]:"<<vec[i]<<endl;
				vec[i] += e[2];
            }
		}
		return vec;
    }
};
int main()
{}

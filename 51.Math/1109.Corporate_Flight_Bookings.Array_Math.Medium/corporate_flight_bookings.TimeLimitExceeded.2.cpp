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
		int size = bookings.size();
		sort(bookings.begin(), bookings.end());
		int start = 0;
		for (int i = 1; i <= n; i++)
		{
            //cout<<"--------i:"<<i<<endl;
			for (int j = start; j < size; j++)
			{
                //cout<<"--------j:"<<j<<endl;
				vector<int> &b = bookings[j];
                //cout<<"b[0]"<<b[0]<<"   b[1]:"<<b[1]<<" b[2]:"<<b[2]<<endl;
				if (i < b[0])
                {
					break;
                    //cout<<1<<endl;
                }
				if (i == b[0])
                {
					vec[i-1] += b[2];
                    //cout<<2<<endl;
                }
				else if (i <= b[1]) //i > j
                {
					vec[i-1] += b[2];
                    //cout<<3<<endl;
                }
				else//i > b[1]
				{
					if (j == start)
                        start++;
                    //cout<<4<<endl;
				}
			}
            //cout<<"vec["<<i-1<<"]"<<vec[i-1]<<endl;
            
		}
		return vec;
    }
};
int main()
{}

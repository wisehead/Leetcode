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
/*
Explanation
Set the change of seats for each day.
If booking = [i, j, k],
it needs k more seat on ith day,
and we don't need these seats on j+1th day.
We accumulate these changes then we have the result that we want.


Complexity
Time O(booking + N) for one pass on bookings
Space O(N) for the result
 */
class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
        vector<int> res(n + 1, 0);
        for (auto & b : bookings) {
            res[b[0] - 1] += b[2];
            res[b[1]] -= b[2];
        }
        for (int i = 1; i < n; ++i)
            res[i] += res[i - 1];
        return {res.begin(), res.end() - 1};
    }
};
int main()
{}

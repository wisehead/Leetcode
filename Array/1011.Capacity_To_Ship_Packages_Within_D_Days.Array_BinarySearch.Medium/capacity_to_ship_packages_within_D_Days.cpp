/*******************************************************************************
 *      file name: capacity_to_ship_packages_within_D_Days.cpp                                               
 *         author: Hui Chen. (c) 2019                             
 *           mail: chenhui13@baidu.com                                        
 *   created time: 2019/07/13-15:06:01                              
 *  modified time: 2019/07/13-15:06:01                              
 *******************************************************************************/
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
	int try0(vector<int>& weights, int mid) {
		int sum = 0, cnt = 0;
		int n = weights.size();
		for (int i = 0; i < n; i++)
		{
			sum += weights[i];
			if (sum > mid)
			{
				cnt++;
				sum = weights[i];
			}
			if (i == n-1)
				cnt++;
		}
        //cout<<"cnt:"<<cnt<<endl;
		return cnt;
	}
    int shipWithinDays(vector<int>& weights, int D) {
		int sum = 0, maxv = 0;
		for (int e: weights)
        {
			sum += e;
            maxv = max(e, maxv);
        }
		int avg = sum / D;
		int mid = 0, left = max(avg, maxv), right = sum;
		while (left < right)
		{
			mid = (left + right)/2;
            //cout<<"left:"<<left<<"  right:"<<right<<"   mid:"<<mid<<endl;
			if (try0(weights, mid) > D)
				left = mid + 1;
			else
				right = mid;
		}
		return left;
    }
};
int main()
{}

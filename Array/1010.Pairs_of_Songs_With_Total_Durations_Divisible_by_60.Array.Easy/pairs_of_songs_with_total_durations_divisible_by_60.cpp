/*******************************************************************************
 *      file name: pairs_of_songs_with_total_durations_divisible_by_60.cpp                                               
 *         author: Hui Chen. (c) 2019                             
 *           mail: chenhui13@baidu.com                                        
 *   created time: 2019/07/11-20:11:31                              
 *  modified time: 2019/07/11-20:11:31                              
 *******************************************************************************/
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
		int arr[60] = {0};
		int sum = 0;
		for (int e: time)
		{
			int mod = e % 60;
			arr[mod]++;
		}
		for (int i = 1; i < 30; i++)
		{
			int a = arr[i];
			int b = arr[60 - i];
			sum += a*b;
            //cout<<"i:"<<i<<"   a:"<<a<<"    b:"<<b<<"   sum:"<<sum<<endl;
		}
        int n = arr[0];
        sum += n*(n-1)/2;
		n = arr[30];
		sum += n*(n-1)/2;
		return sum;
    }
};
int main()
{}

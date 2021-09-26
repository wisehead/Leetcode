/*******************************************************************************
 *      file name: maximize_distance_to_closest_person.cpp                                               
 *         author: Hui Chen. (c) 2018                             
 *           mail: chenhui13@baidu.com                                        
 *   created time: 2018/12/19-12:21:24                              
 *  modified time: 2018/12/19-12:21:24                              
 *******************************************************************************/
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int maxDistToClosest(vector<int>& seats) {
		int size = seats.size();
		int l_zeros = 0;
		while (l_zeros < size && seats[l_zeros] == 0)
			l_zeros++;
		cout<<"l_zeros:"<<l_zeros<<endl;
		int r_zeros = 0;
		int i = size - 1;
		while (i >= 0 && seats[i] == 0)
		{
			i--;
			r_zeros++;
		}
		cout<<"r_zeros:"<<r_zeros<<endl;
		int max_dis = max(l_zeros, r_zeros);
		cout<<"ege_dis:"<<max_dis<<endl;
		int max_zeros = 0;
		for (int i = 0; i < size; )
		{
			cout<<"i:"<<i<<endl;
			if (seats[i] == 1)
			{
				i++;
				continue;
			}
			int temp = 0;
			while (seats[i] == 0)
			{
				temp++;
				i++;
			}
			if (temp > max_zeros) max_zeros = temp;
		}
		int temp = (max_zeros + 1)/2;
		cout<<"mid_dis:"<<temp<<endl;
		max_dis = max(max_dis, temp);
		return max_dis;
    }
};
int main()
{
	Solution sol;
	/*
	int array[7] = {1,0,0,0,1,0,1};
	vector<int> vec(array, array+7);
	*/
	int array[] = {1,0,0,0};
	vector<int> vec(array, array+4);
	int ret = sol.maxDistToClosest(vec);
}

/*******************************************************************************
 *      file name: reach_a_number.cpp                                               
 *         author: Hui Chen. (c) 2018                             
 *           mail: chenhui13@baidu.com                                        
 *   created time: 2018/10/19-19:11:58                              
 *  modified time: 2018/10/19-19:11:58                              
 *******************************************************************************/
#include <iostream>
#include <math.h>
using namespace std;
class Solution {
public:
    int reachNumber(int target) {
        target = abs(target);
        int step = 0;
        int sum = 0;
        while (sum < target) {
            step++;
            sum += step;
        }
        while ((sum - target) % 2 != 0) {
            step++;
            sum += step;
        }
        return step;
    }
};
int main()
{
	Solution sol;
	//int ret = sol.reachNumber(3);
	//int ret = sol.reachNumber(2);
	int ret = sol.reachNumber(1);
	cout<<"ret:"<<ret<<endl;
}

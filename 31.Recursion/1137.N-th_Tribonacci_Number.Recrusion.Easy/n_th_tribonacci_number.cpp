/*******************************************************************************
 *      file name: n_th_tribonacci_number.cpp                                               
 *         author: Hui Chen. (c) 2020                             
 *           mail: chenhui13@baidu.com                                        
 *   created time: 2020/10/28-09:19:54                              
 *  modified time: 2020/10/28-09:19:54                              
 *******************************************************************************/
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int tribonacci(int n) {
        if (n == 0) return 0;
        if (n == 1 || n == 2) return 1;
        //return tribonacci(n-1) + tribonacci(n-2) + tribonacci(n-3); 
        int i = 3; 
        vector<int> vec = {0,1,1};
        int sum = 0;
        while (i <= n) {
            sum = vec[i-1] + vec[i-2] + vec[i-3];
            vec.push_back(sum);
            i++;
        }
        return sum;
    }
};
int main()
{}

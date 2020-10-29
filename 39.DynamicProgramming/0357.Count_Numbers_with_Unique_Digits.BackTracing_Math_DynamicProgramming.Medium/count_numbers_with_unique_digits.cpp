/*******************************************************************************
 *      file name: count_numbers_with_unique_digits.cpp                                               
 *         author: Hui Chen. (c) 2020                             
 *           mail: chenhui13@baidu.com                                        
 *   created time: 2020/10/28-17:19:13                              
 *  modified time: 2020/10/28-17:19:13                              
 *******************************************************************************/
#include <iostream>
#include <vector>
#include <math.h>
using namespace std;
class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        vector<int> res;
        if (n == 0) return 1;
        dfs(res, n);
        return res.size();
    }
    
    void dfs(vector<int> &res, int n) {
        if (n == 1) {
            int arr[] = {0,1,2,3,4,5,6,7,8,9};
            res.assign(arr, arr+10);
            return;
        }
        
        vector<int> vec;
        dfs(vec, n - 1);
        res.assign(vec.begin(), vec.end());
        for (int i = 1; i <=9; i++) {
            for (auto e : vec) {
                int x = e + i*pow(10.0, n-1);
                if (is_valid(x) ) res.push_back(x);
            }
        }
    }
    
    bool is_valid(int n) {
        int flag[10] = {0};
        while (n > 0) {
            int m = n % 10;
            if (++flag[m] > 1) return false;
            n = n/10;
        }
        return true;
    }
};
int main()
{}

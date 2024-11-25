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
        vector<int> vec;
        if (n == 0) return 1;
        int arr[] = {0,1,2,3,4,5,6,7,8,9};
        vec.assign(arr, arr+10);
        if (n == 1) return 10;
        for (int i = 2; i <= n; i++) {
            int size = vec.size();
            for (int k = 1; k <=9; k++) {
                for (int j = 0; j < size; j++) {
                    int x = vec[j] + k*pow(10.0, i-1);
                    if (is_valid(x) ) vec.push_back(x);
                }
            }
        }
        return vec.size();
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

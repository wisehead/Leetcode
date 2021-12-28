/*******************************************************************************
 *      file name: sum_all_all_odd_length_subarrays.cpp                                               
 *         author: Hui Chen. (c) 2021                             
 *           mail: alex.chenhui@gmail.com                                        
 *   created time: 2021/12/28-21:24:46                              
 *  modified time: 2021/12/28-21:24:46                              
 *******************************************************************************/
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int sumOddLengthSubarrays(vector<int>& arr) {
        int sum = 0;
        int N = arr.size();
        for (int i = 0; i < N; i++) {
            int temp = 0;
            for (int x = 0; x < N && i+x < N; x++) {
                temp += arr[i+x];
                if (x %2 == 0) sum += temp;
            }
        }
        return sum;
    }
};
int main()
{}

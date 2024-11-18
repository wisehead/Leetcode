/*******************************************************************************
 *      file name: can_make_arithmetic_progression_from_sequence.cpp                                               
 *         author: Hui Chen. (c) 2021                             
 *           mail: alex.chenhui@gmail.com                                        
 *   created time: 2021/11/28-20:06:07                              
 *  modified time: 2021/11/28-20:06:07                              
 *******************************************************************************/
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    bool canMakeArithmeticProgression(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        int x = arr[1] - arr[0];
        int N = arr.size();
        for (int i = 1; i < N; i++) {
            if (arr[i] - arr[i-1] != x) return false;
        }
        return true;
    }
};
int main()
{}

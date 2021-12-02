/*******************************************************************************
 *      file name: count_good_triplets.cpp                                               
 *         author: Hui Chen. (c) 2021                             
 *           mail: alex.chenhui@gmail.com                                        
 *   created time: 2021/12/02-09:37:46                              
 *  modified time: 2021/12/02-09:37:46                              
 *******************************************************************************/
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int countGoodTriplets(vector<int>& arr, int a, int b, int c) {
        int N = arr.size();
        int cnt = 0;
        for (int i = 0; i < N-2; i++) {
            for (int j = i+1; j < N-1; j++) {
                if (abs(arr[i] - arr[j]) > a) continue;
                for (int k = j+1; k < N; k++) {
                    if (abs(arr[j] - arr[k]) <= b && abs(arr[i] - arr[k]) <= c) cnt++;
                }
            }
        }
        return cnt;
    }
};
int main()
{}

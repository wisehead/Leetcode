/*******************************************************************************
 *      file name: detect_pattern_of_length_M_repeated_K_or_more_times.cpp                                               
 *         author: Hui Chen. (c) 2021                             
 *           mail: alex.chenhui@gmail.com                                        
 *   created time: 2021/12/12-20:37:50                              
 *  modified time: 2021/12/12-20:37:50                              
 *******************************************************************************/
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    bool is_same(vector<int>& arr, int x1, int x2, int m) {
        for (int i = 0; i < m; i++) {
            if (arr[x1+i] != arr[x2+i]) return false;
        }
        return true;
    }
    bool containsPattern(vector<int>& arr, int m, int k) {
        int N = arr.size();
        for (int i = 0; i <= N-m*k; i++) {
            int cnt = 1;
            for (int j = i+m; j < N; j = j+m) {
                if (is_same(arr, i, j, m)) {
                    cnt++;
                    //cout<<"i:"<<i<<",j:"<<j<<",cnt:"<<cnt<<endl;
                    if (cnt >= k) return true;
                } else break;
            }
        }
        return false;
    }
};
int main()
{}

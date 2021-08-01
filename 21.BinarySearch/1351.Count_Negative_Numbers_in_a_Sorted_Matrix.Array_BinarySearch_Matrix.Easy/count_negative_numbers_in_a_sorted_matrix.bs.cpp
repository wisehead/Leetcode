/*******************************************************************************
 *      file name: count_negative_numbers_in_a_sorted_matrix.cpp                                               
 *         author: Hui Chen. (c) 2021                             
 *           mail: alex.chenhui@gmail.com                                        
 *   created time: 2021/08/01-19:40:06                              
 *  modified time: 2021/08/01-19:40:06                              
 *******************************************************************************/
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int bs(vector<int> &vec) {
        int l = 0, r = vec.size();
        if (vec[r-1] >= 0) return r;
        int mid = 0;
        while (l < r) {
            mid = (l+r)/2;
            if (vec[mid] >= 0) {
                l = mid + 1;
            } else {
                r = mid;
            }
        }

        return l;
    }

    int countNegatives(vector<vector<int>>& grid) {
        int cnt = 0;
        int N = grid[0].size();
        for (auto vec: grid) {
            int pos = bs(vec);
            cnt += (N-pos);
        }
        return cnt;
    }
};
int main()
{}

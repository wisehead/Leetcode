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
    int countNegatives(vector<vector<int>>& grid) {
        int cnt = 0;
        for (auto vec: grid) {
            for (auto e : vec) {
                if (e < 0) ++cnt;
            }
        }
        return cnt;
    }
};
int main()
{}

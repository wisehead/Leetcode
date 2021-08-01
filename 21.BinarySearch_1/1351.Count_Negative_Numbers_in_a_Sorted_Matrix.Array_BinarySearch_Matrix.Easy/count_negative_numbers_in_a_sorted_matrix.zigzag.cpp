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
        int m = 0;//m
        int j = 0;
        int N = grid[0].size();
        for (int i = 0; i < grid.size(); i++) {
            if (i == 0) {
                for (j = m; j < N && grid[i][j] >= 0; j++);
                j--;
            } else {
                for (j = m; j >= 0 && grid[i][j] < 0; j--);
            }
            m = j;
            cnt += (N-m-1);
            //cout <<"i:" <<i <<",cnt:"<<cnt<<endl;
        }
        return cnt;
    }
};
int main()
{}

/*******************************************************************************
 *      file name: lucky_numbers_in_a_matrix.cpp                                               
 *         author: Hui Chen. (c) 2021                             
 *           mail: alex.chenhui@gmail.com                                        
 *   created time: 2021/09/04-10:34:39                              
 *  modified time: 2021/09/04-10:34:39                              
 *******************************************************************************/
#include <iostream>
#include <vector>
#include <set>
using namespace std;
class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& matrix) {
        int N = matrix.size();
        int M = matrix[0].size();
        set<vector<int>> st1;
        vector<int> res;
        
        for (int i = 0; i < N; i++) {
            int min_v = INT_MAX;
            int min_index = 0;
            for (int j = 0; j < M; j++) {
                if (matrix[i][j] < min_v) {
                    min_v = matrix[i][j];
                    min_index = j;
                }
            }
            vector<int> vec(1, i);
            vec.push_back(min_index);
            st1.insert(vec);
        }
        for (int j = 0; j < M; j++) {
            int max_v = INT_MIN;
            int max_index = 0;
            for (int i = 0; i < N; i++) {
                if (matrix[i][j] > max_v) {
                    max_v = matrix[i][j];
                    max_index = i;
                }
            }
            vector<int> vec(1, max_index);
            vec.push_back(j);
            if (st1.count(vec)) res.push_back(max_v);
        }        
        return res;
    }
};
int main()
{}

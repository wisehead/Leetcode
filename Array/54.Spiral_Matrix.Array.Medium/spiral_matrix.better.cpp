/*******************************************************************************
 *      file name: spiral_matrix.cpp                                               
 *         author: Hui Chen. (c) 2019                             
 *           mail: chenhui13@baidu.com                                        
 *   created time: 2019/03/07-09:27:29                              
 *  modified time: 2019/03/07-09:27:29                              
 *******************************************************************************/
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    enum direction {left, right, up, down};
    
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> solution;
    size_t c = 0, r = 0;
    direction d = direction::right;
    size_t cycle = 0;

    if(matrix.empty())
        return solution;

    size_t rowsNum = matrix.size();
    size_t colsNum = matrix[0].size();

    for(;;) {
        if(solution.size() == rowsNum*colsNum)
            break;

        switch (d) {
        case direction::right:
            if(c == colsNum - 1 - cycle)
                d = direction::down;
            else
                solution.push_back(matrix[r][c++]);
            break;
        case direction::down:
            if(r == rowsNum - 1 - cycle)
                d = direction::left;
            else
                solution.push_back(matrix[r++][c]);
            break;
        case direction::left:
            if(c == cycle)
            {
                d = direction::up;
                cycle++;
            }
            else
                solution.push_back(matrix[r][c--]);
            break;
        case direction::up:
            if(r == cycle)
                d = direction::right;
            else
                solution.push_back(matrix[r--][c]);
            break;
        }
    }

    return solution;
    }
};
int main()
{}

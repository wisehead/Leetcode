/*******************************************************************************
 *      file name: matrix_cells_in_distance_order.cpp                                               
 *         author: Hui Chen. (c) 2020                             
 *           mail: chenhui13@baidu.com                                        
 *   created time: 2020/09/20-09:28:27                              
 *  modified time: 2020/09/20-09:28:27                              
 *******************************************************************************/
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;
class Solution {
public:
    vector<vector<int>> allCellsDistOrder(int R, int C, int r0, int c0) {
        auto comp = [r0, c0](vector<int> &a, vector<int> &b)
        {
            return abs(a[0]-r0) + abs(a[1]-c0) < abs(b[0]-r0) + abs(b[1]-c0);
        };
        
        vector<vector<int>> resp;
        for(int i=0 ; i<R ; i++)
        {
            for(int j=0; j<C ; j++)
            {
                resp.push_back({i, j});
            }
        }

        sort(resp.begin(), resp.end(), comp);

        return resp;
    }
};
int main()
{}

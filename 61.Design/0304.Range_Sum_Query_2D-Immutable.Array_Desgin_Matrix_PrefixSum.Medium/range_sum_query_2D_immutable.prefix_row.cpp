/*******************************************************************************
 *      file name: range_sum_query_2D_immutable.prefix_row.cpp                                               
 *         author: Hui Chen. (c) 2021                             
 *           mail: alex.chenhui@gmail.com                                        
 *   created time: 2021/10/08-20:24:00                              
 *  modified time: 2021/10/08-20:24:00                              
 *******************************************************************************/
#include <iostream>
#include <vector>
using namespace std;
class NumMatrix {
public:
    NumMatrix(vector<vector<int>>& matrix) {
        for (auto vec : matrix) {
            vector<int> v;
            int sum = 0;
            for (int i = 0; i < vec.size(); i++) {
                sum += vec[i];
                v.push_back(sum);
            }
            vv.push_back(v);
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        int sum = 0;
        for (int i = row1; i <= row2; i++) {
            if (col1-1 >= 0)
                sum += (vv[i][col2] - vv[i][col1-1]);
            else 
                sum += vv[i][col2];
        }
        return sum;
    }
private:
    vector<vector<int> > vv;
};
int main()
{}

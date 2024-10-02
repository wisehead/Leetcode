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
        for (int i = 0; i <= matrix.size(); i++) {
            int M = matrix[0].size();
            if (i == 0) {
                vector<int> v(M+1, 0);
                vv.push_back(v);
                continue;
            }
            int sum = 0;
            vector<int> v;
            for (int j = 0; j <= M; j++) {
                if (j == 0) {
                    v.push_back(0);
                    continue;
                }
                sum += matrix[i-1][j-1];
                int val = sum + vv[i-1][j];;
                //cout<<"i:"<<i<<",j:"<<j<<",val:"<<val<<endl;
                v.push_back(val);
            }
            vv.push_back(v);
        }
    }

    int sumRegion(int row1, int col1, int row2, int col2) {
        int sum = vv[row2+1][col2+1] + vv[row1][col1] - vv[row2+1][col1] - vv[row1][col2+1];
        return sum;
    }
private:
    vector<vector<int> > vv;
    //vector<vector<int> > _matrix;
};

int main()
{}

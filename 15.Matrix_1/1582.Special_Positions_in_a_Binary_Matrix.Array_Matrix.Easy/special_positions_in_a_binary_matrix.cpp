/*******************************************************************************
 *      file name: special_positions_in_a_binary_matrix.cpp                                               
 *         author: Hui Chen. (c) 2021                             
 *           mail: alex.chenhui@gmail.com                                        
 *   created time: 2021/12/27-09:38:03                              
 *  modified time: 2021/12/27-09:38:03                              
 *******************************************************************************/
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int numSpecial(vector<vector<int>>& mat) {
        int cnt = 0;
        int M = mat.size();
        int N = mat[0].size();
        vector<int> candi(M, -1);
        for (int i = 0; i < M; i++) {
            for (int j = 0; j < N; j++) {
                if (mat[i][j]) {
                    if (candi[i] == -1) candi[i] = j;
                    else {
                        candi[i] = -1;
                        break;
                    }
                } 
            }
        }
        
        vector<int> candj(N, -1);
        for (int j = 0; j < N; j++) {
            for (int i = 0; i < M; i++) {
                if (mat[i][j]) {
                    if (candj[j] == -1) candj[j] = i;
                    else {
                        candj[j] = -1;
                        break;
                    }
                }
            }
        }
        
        for (int i = 0; i < M; i++) {
            if (candi[i] != -1) {
                int j = candi[i];
                if (candj[j] == i) cnt++;
            }
        }
        return cnt;
    }
};
int main()
{}

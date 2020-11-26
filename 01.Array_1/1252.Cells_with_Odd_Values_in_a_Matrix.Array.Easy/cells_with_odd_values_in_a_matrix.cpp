/*******************************************************************************
 *      file name: cells_with_odd_values_in_a_matrix.cpp                                               
 *         author: Hui Chen. (c) 2020                             
 *           mail: chenhui13@baidu.com                                        
 *   created time: 2020/11/26-10:04:13                              
 *  modified time: 2020/11/26-10:04:13                              
 *******************************************************************************/
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int oddCells(int n, int m, vector<vector<int>>& indices) {
        vector<int> n_v(n, 0);
        vector<int> m_v(m, 0);
        for (auto v : indices) {
            //cout<<"v[0]:"<<v[0]<<"  v[1]:"<<v[1]<<endl;
            n_v[v[0]]++;
            m_v[v[1]]++;
        }
        //unordered_map<int, int>::iterator it;
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                //cout<<"i:"<<i<<"    j:"<<j<<endl;
                if ((n_v[i] + m_v[j]) % 2 == 1) cnt++;
            }
        }
        return cnt;
    }
};
int main()
{}

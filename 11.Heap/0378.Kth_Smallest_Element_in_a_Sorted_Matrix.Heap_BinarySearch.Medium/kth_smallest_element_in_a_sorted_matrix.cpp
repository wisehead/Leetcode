/*******************************************************************************
 *      file name: kth_smallest_element_in_a_sorted_matrix.cpp                                               
 *         author: Hui Chen. (c) 2020                             
 *           mail: chenhui13@baidu.com                                        
 *   created time: 2020/10/31-12:06:51                              
 *  modified time: 2020/10/31-12:06:51                              
 *******************************************************************************/
#include <iostream>
#include <queue>
using namespace std;
class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n = matrix.size();
        priority_queue<int> pq;
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                pq.push(matrix[i][j]);
                if (pq.size() > k) pq.pop();
            }
        }
        return pq.top();
    }
};
int main()
{}

/*******************************************************************************
 *      file name: the_k_weakest_rows_in_a_matrix.cpp                                               
 *         author: Hui Chen. (c) 2020                             
 *           mail: chenhui13@baidu.com                                        
 *   created time: 2020/10/29-16:55:18                              
 *  modified time: 2020/10/29-16:55:18                              
 *******************************************************************************/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
struct Node {
    int cnt;
    int index;
    Node(int c, int i): cnt(c), index(i) {}
};
class Solution {
public:
    static bool compare(Node n1, Node n2)
    {
        if (n1.cnt == n2.cnt) return n1.index < n2.index;
        return (n1.cnt < n2.cnt);
    }    
    
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        vector<Node> v;
        for (int i = 0; i < mat.size(); i++) {
            int cnt = bs(mat[i]);
            Node node(cnt, i);
            v.push_back(node);
        }
        sort(v.begin(), v.end(), compare);
        vector<int> res(k,0);
        for (int i = 0; i < k; i++)
            res[i] = v[i].index;
        return res;
    }
    
    int bs(vector<int>& vec) {
        int j = vec.size();
        int i = 0;
        int mid = 0;
        while (i < j) {
            mid = (i+j)/2;
            if (vec[mid] == 1) {
                i = mid+1;
            } else {
                j = mid;
            }
        }
        return i;
    }
};
int main()
{}

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
#include <set>
using namespace std;
struct Node {
    int cnt;
    int index;
    Node(int c, int i): cnt(c), index(i) {}
};
class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        set<pair<int,int>> st;
        for (int i = 0; i < mat.size(); i++) {
            int cnt = bs(mat[i]);
            st.insert({cnt,i});
        }
        
        vector<int> res;
        set<pair<int,int>>::iterator it;
        int i = 0;
        for (it = st.begin(); it != st.end() && i < k; it++, i++) {
            res.push_back(it->second);
        }
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

/*******************************************************************************
 *      file name: rank_transform_of_an_array.best.cpp                                               
 *         author: Hui Chen. (c) 2021                             
 *           mail: alex.chenhui@gmail.com                                        
 *   created time: 2021/07/31-17:58:03                              
 *  modified time: 2021/07/31-17:58:03                              
 *******************************************************************************/
#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;
class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        vector<int> A(arr);
        sort(A.begin(), A.end());
        unordered_map<int, int> rank;
        for (int& a : A)
            rank.emplace(a, rank.size() + 1);
        for (int i = 0; i < A.size(); ++i)
            A[i] = rank[arr[i]];
        return A;
    }
};
int main()
{}

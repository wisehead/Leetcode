/*******************************************************************************
 *      file name: longest_consecutive_sequence.cpp                                               
 *         author: Hui Chen. (c) 2021                             
 *           mail: alex.chenhui@gmail.com                                        
 *   created time: 2021/08/10-19:48:28                              
 *  modified time: 2021/08/10-19:48:28                              
 *******************************************************************************/
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;


class Union_Find{
public:
    Union_Find (int N) {
        for (int i = 0; i < N; i++) {
            id.push_back(i);
            sz.push_back(1);
        }
    }

    void Union(int A, int B) {
        int rootA = Find(A);
        int rootB = Find(B);
        if (rootA == rootB) return;
        if (sz[rootA] < sz[rootB]) {
            id[rootA] = rootB;
            sz[rootB] += sz[rootA];
        } else {
            id[rootB] = rootA;
            sz[rootA] += sz[rootB];
        }
    }

    int Find(int p) {
        while (p != id[p]) {
            id[p] = id[id[p]];
            p = id[p];
        }
        return p;
    }

    int maxSize() {
        int res = 0;
        for (auto s : sz)
            res = max(res, s);
        return res;
    }

private:
    vector<int> id;
    vector<int> sz;
};

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        Union_Find uf(nums.size());
        unordered_map<int, int> mapIndex;
        for (int i = 0; i < nums.size(); i++) {
            if (mapIndex.count(nums[i])) continue; // in case of duplicate
            mapIndex.insert(make_pair(nums[i], i));

            if (mapIndex.count(nums[i] + 1)) {
                uf.Union(i, mapIndex[nums[i] + 1]);
            }
            if (mapIndex.count(nums[i] - 1)) {
                uf.Union(i, mapIndex[nums[i] - 1]);
            }
        }
        return uf.maxSize();
    }
};
int main()
{}

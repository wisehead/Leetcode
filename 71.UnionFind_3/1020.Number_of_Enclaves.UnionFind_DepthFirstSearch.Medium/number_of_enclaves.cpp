/*******************************************************************************
 *      file name: number_of_enclaves.cpp                                               
 *         author: hui chen. (c) 25                             
 *           mail: alex.chenhui@gmail.com                                        
 *   created time: 25/01/14- 1:01                                    
 * modified time: 25/01/14- 1:01                                    
 *******************************************************************************/
#include <iostream>
class Union_Find {
public:
    Union_Find (vector<vector<int>>& matrix) {
        m = matrix.size();
        n = matrix[0].size();
        grid = matrix;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (!grid[i][j]) continue;
                //if (i == 0 || i == m-1 || j == 0 || j == n-1) continue;
                vector<int> vec = {i,j};
                id[vec] = vec;
                sz[vec] = 1;
            }
        }
    }

    void Union(vector<int> A, vector<int> B) {
        auto rootA = Find(A);
        auto rootB = Find(B);
        if (rootA == rootB) return;
        if (sz[rootA] < sz[rootB]) {
            id[rootA] = rootB;
            sz[rootB] += sz[rootA];
        } else {
            id[rootB] = rootA;
            sz[rootA] += sz[rootB];
        }
    }

    vector<int> Find(vector<int> p) {
        while (p != id[p]) {
            id[p] = id[id[p]];
            p = id[p];
        }
        return p;
    }
    bool is_boundary(int i, int j) {
        return (i == 0 || i == m-1 || j == 0 || j == n-1);
    }
    vector<int> Find2(vector<int> p) {
        bool flag = false;
        if (is_boundary(p[0],p[1])) {
            flag = true;
        }
        while (p != id[p]) {
            id[p] = id[id[p]];
            p = id[p];
            if (is_boundary(p[0],p[1])) {
                flag = true;
            }
        }
        if (flag) sz[p] = 0;
        return p;
    }
    int maxSize() {
        int max_v = 0;
        int cnt = 0;
        set<vector<int>> s;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (!grid[i][j]) continue;
                vector<int> vec = {i,j};
                auto p = Find2(vec);
            }
        }
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (!grid[i][j]) continue;
                if (i == 0 || i == m-1 || j == 0 || j == n-1) continue;
                vector<int> vec = {i,j};
                auto p = Find(vec);
                if (!s.count(p)) {
                    s.insert(p);
                    cnt += sz[p];
                }
            }
        }
        return cnt;
    }

    bool exist(vector<int> node) {
        bool ret = id.count(node);
        return ret;
    }

public:
    map<vector<int>,vector<int>> id;
    map<vector<int>,int> sz;
    vector<vector<int>> grid;
    int m;
    int n;
};

class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {
        Union_Find uf(grid);
        int m = grid.size();
        int n = grid[0].size();
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (!grid[i][j]) continue;
                vector<int> vec = {i,j};

                vector<int> vec2 = {i+1,j};
                if (uf.exist(vec2)) uf.Union(vec, vec2);

                vector<int> vec4 = {i,j+1};
                if (uf.exist(vec4)) uf.Union(vec, vec4);
            }
        }
        return uf.maxSize();
    }
};

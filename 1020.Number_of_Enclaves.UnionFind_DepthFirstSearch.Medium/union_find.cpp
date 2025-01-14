/*******************************************************************************
 *      file name: union_find.cpp                                               
 *         author: hui chen. (c) 25                             
 *           mail: alex.chenhui@gmail.com                                        
 *   created time: 25/01/14- 1:01                                    
 * modified time: 25/01/14- 1:01                                    
 *******************************************************************************/
#include <iostream>
class UnionFind {
public:
	UnionFind(int n) : parent(n), rank(n) {
		for (int i = 0; i < n; i++)
			parent[i] = i;
	}

	int find(int x) {
		if (parent[x] == x) return x;
		return parent[x] = find(parent[x]);
	}

	void unite(int x, int y) {
		int px = find(x), py = find(y);
		if (px != py) {
			if (rank[px] < rank[py]) swap(px, py);
			parent[py] = px;
			if (rank[px] == rank[py]) rank[px]++;
		}
	}

	bool same(int x, int y) {
		return find(x) == find(y);
	}
private:
	vector<int> parent, rank;
};

class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        UnionFind uf(m * n + 1);

        int virtualNode = m * n;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (i == 0 || j == 0 || i == m - 1 || j == n - 1) {
                    if (grid[i][j] == 1) {
                        uf.unite(i * n + j, virtualNode);
                    }
                }
            }
        }

        int dD[] = {1, 0, -1, 0, 1};
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    for (int k = 0; k < 4; k++) {
                        int x = i + dD[k], y = j + dD[k+1];
                        if (x >= 0 && x < m && y >= 0 && y < n && grid[x][y] == 1) {
                            uf.unite(i * n + j, x * n + y);
                        }
                    }
                }
            }
        }

        int ans = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    if(!uf.same(i * n + j, virtualNode)) ans++;
                }
            }
        }
        return ans;
    }
};

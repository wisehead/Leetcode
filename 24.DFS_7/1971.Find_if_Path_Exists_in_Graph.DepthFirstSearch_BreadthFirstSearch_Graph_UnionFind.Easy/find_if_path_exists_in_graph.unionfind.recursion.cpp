/*******************************************************************************
 *      file name: find_if_path_exists_in_graph.cpp                                               
 *         author: Hui Chen. (c) 2021                             
 *           mail: alex.chenhui@gmail.com                                        
 *   created time: 2021/10/03-20:10:23                              
 *  modified time: 2021/10/03-20:10:23                              
 *******************************************************************************/
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int start, int end) {
       
        if ( start == end) return true;
        if (edges.empty()) return 0;
        vector<int> leads(n, 0);
        for (int i = 0; i < n; i++) { leads[i] = i; } 
        int groups = n;
        for (auto vec : edges) {
            int i = vec[0];
            int j = vec[1];
            int lead1 = find(i, leads);
            int lead2 = find(j, leads);
            if (lead1 != lead2) {// if 2 group belongs 2 different leads, merge 2 to 1
                leads[lead1] = lead2;
                groups--;
            }
            
        }
    
        int lead1 = find(start, leads);
        int lead2 = find(end, leads);
    
        return (lead1 == lead2);
        //return groups;        
    }
    
    int find(int x, vector<int>& parents) {
        return parents[x] == x ? x : find(parents[x], parents);
    }    
};
int main()
{}

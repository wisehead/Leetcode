/*******************************************************************************
 *      file name: find_center_of_start_graph.cpp                                               
 *         author: Hui Chen. (c) 2021                             
 *           mail: alex.chenhui@gmail.com                                        
 *   created time: 2021/08/07-18:28:34                              
 *  modified time: 2021/08/07-18:28:34                              
 *******************************************************************************/
#include <iostream>
#include <vector>
#include <map>
using namespace std;
class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        map<int, int> mm;
        //vector<int> v1 = edges[0];
        //vector<int> v2 = edges[1];
        for (auto e : edges[0]) {
            mm[e] = 0;
        }
        for (auto e : edges[1]) {
            if (mm.count(e)) return e;
        }        
        return 0;
    }
};
int main()
{}

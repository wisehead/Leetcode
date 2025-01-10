/*******************************************************************************
 *      file name: find_eventual_safe_states.cpp                                               
 *         author: hui chen. (c) 25                             
 *           mail: alex.chenhui@gmail.com                                        
 *   created time: 25/01/10- 1:01                                    
 * modified time: 25/01/10- 1:01                                    
 *******************************************************************************/
#include <iostream>
class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        set<int> term_nodes;
        for (int i = 0; i < graph.size(); i++) {
            if (graph[i].size() == 0) term_nodes.insert(i);
        }
        int cnt = -1;
        while (term_nodes.size() != cnt) {
            cnt = term_nodes.size();
            for (int i = 0; i < graph.size(); i++) {
                bool flag = true;
                for (auto node : graph[i]) {
                    if (!term_nodes.count(node)) {
                        flag = false;
                        break;
                    }
                }
                if (flag && !term_nodes.count(i)) term_nodes.insert(i);
            }
        }
        vector<int> res(term_nodes.begin(), term_nodes.end());
        return res;
    }
};

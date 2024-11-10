/*******************************************************************************
 *      file name: verify_preorder_serialization_of_a_binary_tree.cpp                                               
 *         author: hui chen. (c) 24                             
 *           mail: alex.chenhui@gmail.com                                        
 *   created time: 24/11/10-11:11                                    
 * modified time: 24/11/10-11:11                                    
 *******************************************************************************/
#include <iostream>
class Solution {
public:
    struct Node {
        string id;
        int cnt;
    };
    bool isValidSerialization(string preorder) {
        stack<Node> stk;
        bool init = true;
        if (preorder.length() == 1 && preorder[0] == '#') return true;
        for (int i = 0; i < preorder.length(); i++) {
            char c = preorder[i];
            if (c != '#' && c!= ',') {
                string str;
                while (c != '#' && c!= ',' && i < preorder.length()) {
                    str += c;
                    i++;
                    c = preorder[i];
                }
                Node node(str,2);
                if (stk.empty()) {
                    if (!init) return false;
                    init = false;
                }
                stk.push(node);
            } else if (c == '#') {
                if (stk.empty()) return false;
                Node node;
                do {
                    node = stk.top();
                    stk.pop();
                    node.cnt--;
                } while (node.cnt == 0 && !stk.empty());
                if (node.cnt) stk.push(node);
            }
        }
        return stk.empty();
    }
};

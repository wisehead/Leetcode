/*******************************************************************************
 *      file name: remove_nodes_from_linked_list.cpp                                               
 *         author: hui chen. (c) 24                             
 *           mail: alex.chenhui@gmail.com                                        
 *   created time: 24/11/20-11:11                                    
 * modified time: 24/11/20-11:11                                    
 *******************************************************************************/
#include <iostream>
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* removeNodes(ListNode* head) {
        vector<int> vec;
        ListNode* p = head;
        while (p) {
            vec.push_back(p->val);
            p = p->next;
        }
        int n = vec.size();
        int max_v = 0;
        vector<int> vec2(n,0);
        for (int i = n-1; i >= 0; i--) {
            max_v = max(max_v, vec[i]);
            vec2[i] = max_v;
        }
        
        ListNode* pre = new ListNode(INT_MAX);
        pre->next = head;
        ListNode* new_head = pre;
        p = head;
        for (int i = 0; i < n-1; i++) {
            if (p->val < vec2[i+1]) {
                pre->next = p->next;
            } else {
                pre = p;
            }
            p = p->next;
        }
        return new_head->next;
    }
};

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
        stack<ListNode*> stk;
        ListNode* p = head;
        
        while (p) {
            while (!stk.empty() && p->val > stk.top()->val)  {
                stk.pop();
            }
            stk.push(p);
            p = p->next;
        }
        ListNode* phead = NULL;
        while (!stk.empty()) {
            p = stk.top();
            stk.pop();
            p->next = phead;
            phead = p;
        }
        return phead;
    }
};

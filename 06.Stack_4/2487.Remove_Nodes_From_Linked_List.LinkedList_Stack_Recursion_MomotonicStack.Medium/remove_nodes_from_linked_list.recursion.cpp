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
        if (!head) return NULL;
        ListNode* pnext = removeNodes(head->next);
        head->next = pnext;
        if (pnext && (pnext->val > head->val) )
            head = pnext;

        return head;
    }
};

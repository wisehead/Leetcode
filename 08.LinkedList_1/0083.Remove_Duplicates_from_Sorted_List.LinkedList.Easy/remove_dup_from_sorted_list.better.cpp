/*******************************************************************************
 *      file name: remove_dup_from_sorted_list.cpp                                               
 *         author: hui chen. (c) 17                             
 *           mail: chenhui13@baidu.com                                        
 *   created time: 17/11/05-11:11                                    
 * modified time: 17/11/05-11:11                                    
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
    ListNode* deleteDuplicates(ListNode* head) {
        if (!head) return head;
        ListNode *cur = head->next, *pre = head;
        while (cur) {
            if (cur->val == pre->val) {
                pre->next = cur->next;
            } else
                pre = cur;
            cur = cur->next;
        }
        return head;
    }
};

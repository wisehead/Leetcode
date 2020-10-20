/*******************************************************************************
 *      file name: convert_sorted_list_to_binary_search_tree.cpp                                               
 *         author: Hui Chen. (c) 2020                             
 *           mail: chenhui13@baidu.com                                        
 *   created time: 2020/10/20-09:07:35                              
 *  modified time: 2020/10/20-09:07:35                              
 *******************************************************************************/
#include <iostream>
#include <vector>
using namespace std;
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
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

/*
Recursively build tree.

find midpoint by fast/slow method, use middle node as root.
build left child by first half of the list
build right child by second half of the list (head is midpoint->next)
*/

class Solution {
public:
    TreeNode *sortedListToBST(ListNode *head) {
        if(!head) return NULL;
        if(!head->next) return new TreeNode(head->val);
        
        // fast/slow pointer to find the midpoint
        auto slow = head;
        auto fast = head;
        auto pre = head;
        while(fast && fast->next) {
            pre = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        pre->next = 0; // break two halves 
        
        // slow is the midpoint, use as root
        TreeNode* root = new TreeNode(slow->val);
        root->left = sortedListToBST(head);
        root->right = sortedListToBST(slow->next);
        
        return root;
    }
};
int main()
{}

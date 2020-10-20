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
class Solution {
public:    
    TreeNode* fun(ListNode* head, int size) {
        if (!head || size == 0) return NULL;
        int mid = size/2;
        ListNode* node = head;
        for (int i = 0; i < mid; i++) node = node->next;
        TreeNode* root = new TreeNode(node->val);
        //if (size == 1) return root;
        root->left = fun(head, mid);
        root->right = fun(node->next, size - mid - 1);
        return root;
            
    }
    TreeNode* sortedListToBST(ListNode* head) {
        int cnt = 0;
        ListNode* node = head;
        while (node) {
            cnt++;
            node = node->next;
        }
        return fun(head, cnt);
    }
};
int main()
{}

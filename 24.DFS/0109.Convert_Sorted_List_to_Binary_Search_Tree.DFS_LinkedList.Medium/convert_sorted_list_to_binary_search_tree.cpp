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
    TreeNode* fun(vector<int> vec) {
        //for (auto e : vec) cout<<"e:"<<e<<endl;
        cout<<endl;
        int size = vec.size();
        int mid = size/2;
        if (size == 0) return NULL;
        TreeNode* root = new TreeNode(vec[mid]);
        if (size == 1) return root;
        vector<int> vec_l(vec.begin(), vec.begin()+mid);
        root->left = fun(vec_l);
        vector<int> vec_r(vec.begin()+mid+1, vec.end());
        root->right = fun(vec_r);
        return root;
    }    
    TreeNode* sortedListToBST(ListNode* head) {
        vector<int> v;
        while (head) {
            v.push_back(head->val);
            head = head->next;
        }
        return fun(v);
    }
};
int main()
{}

/*******************************************************************************
 *      file name: convert_sorted_array_2_BST.cpp                                               
 *         author: hui chen. (c) 17                             
 *           mail: chenhui13@baidu.com                                        
 *   created time: 17/11/13-11:11                                    
 * modified time: 17/11/13-11:11                                    
 *******************************************************************************/
#include <iostream>
#include <vector>
using namespace std;
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
		int len =  nums.size();
		int mid = len/2;
		if (len == 0) {
			return NULL;
		}else if (len == 1) {
			TreeNode* root= new TreeNode(nums[0]);
			return root;
		} else{
			TreeNode* root = new TreeNode(nums[mid]);
			vector<int>::iterator it;
			it = nums.begin();
			vector<int> sub_left;
		  	sub_left.assign(it,it+mid);
			vector<int> sub_right; 
			sub_right.assign(it+mid+1, nums.end());
			root->left = sortedArrayToBST(sub_left);
			root->right = sortedArrayToBST(sub_right);
			return root;
		}
    }
};
int main()
{}

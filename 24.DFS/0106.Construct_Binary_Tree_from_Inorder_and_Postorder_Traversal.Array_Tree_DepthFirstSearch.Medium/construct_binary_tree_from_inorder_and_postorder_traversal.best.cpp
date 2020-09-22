/*******************************************************************************
 *      file name: construct_binary_tree_from_inorder_and_postorder_traversal.cpp                                               
 *         author: Hui Chen. (c) 2019                             
 *           mail: chenhui13@baidu.com                                        
 *   created time: 2019/04/01-10:07:03                              
 *  modified time: 2019/04/01-10:07:03                              
 *******************************************************************************/
#include <iostream>
#include <vector>
using namespace std;

//Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
	    return create(inorder, postorder, 0, inorder.size() - 1, 0, postorder.size() - 1);
	}
	
	TreeNode* create(vector<int> &inorder, vector<int> &postorder, int is, int ie, int ps, int pe){
	    if(ps > pe){
	        return nullptr;
	    }
	    TreeNode* node = new TreeNode(postorder[pe]);
	    int pos;
	    for(int i = is; i <= ie; i++){
	        if(inorder[i] == node->val){
	            pos = i;
	            break;
	        }
	    }
	    node->left = create(inorder, postorder, is, pos - 1, ps, ps + pos - is - 1);
	    node->right = create(inorder, postorder, pos + 1, ie, pe - ie + pos, pe - 1);
	    return node;
	}
};
int main()
{}

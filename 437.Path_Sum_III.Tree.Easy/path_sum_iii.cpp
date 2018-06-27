/*******************************************************************************
 *      file name: path_sum_iii.cpp                                               
 *         author: Hui Chen. (c) 18                             
 *           mail: chenhui13@baidu.com                                        
 *   created time: 18/06/27- 6:06                                    
 *  modified time: 18/06/27- 6:06                                    
 *******************************************************************************/
#include <iostream>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    int countPathSum(TreeNode* root, int sum) {
        int count = 0;
		if (root == NULL)
            return 0;
        if (root->val == sum)
            count++;
        return count + countPathSum(root->left, sum - root->val) + countPathSum(root->right, sum - root->val);
    }
    
    int pathSum(TreeNode* root, int sum) {
		if (root == NULL)
            return 0;
		int count = 0;
     
        count = countPathSum(root, sum);
		return count + pathSum(root->left, sum) + pathSum(root->right, sum);
    }
};

int main()
{}

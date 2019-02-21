/*******************************************************************************
 *      file name: cousins_in_binary_tree.cpp                                               
 *         author: Hui Chen. (c) 2019                             
 *           mail: chenhui13@baidu.com                                        
 *   created time: 2019/02/21-10:05:30                              
 *  modified time: 2019/02/21-10:05:30                              
 *******************************************************************************/
#include <iostream>
#include <queue>
#include <set>
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
private:
    void levelTraverse(TreeNode* p,int val,int level,TreeNode*& parent,int& l){
        if(p==NULL) return;
        if((p->left!=NULL&&p->left->val==val)||(p->right!=NULL&&p->right->val==val)){ 
            parent=p;
            l=level;
            return;
        }
        levelTraverse(p->left,val,level+1,parent,l);
        levelTraverse(p->right,val,level+1,parent,l);
    }
public:
    bool isCousins(TreeNode* root, int x, int y) {
        TreeNode* tx=root;
        TreeNode* xparent=NULL;
        TreeNode* ty=root;
        TreeNode* yparent=NULL;
        int xlevel=-1,ylevel=-1;
        levelTraverse(tx,x,0,xparent,xlevel);
        levelTraverse(ty,y,0,yparent,ylevel);
        if(yparent!=NULL&&xparent!=NULL&&xparent!=yparent&&xlevel!=-1&&ylevel!=-1&&xlevel==ylevel) return true;
        return false;
    }
};
int main()
{}

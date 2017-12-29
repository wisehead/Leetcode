/*******************************************************************************
 *      file name: lca_BST.cpp                                               
 *         author: Hui Chen. (c) 17                             
 *           mail: chenhui13@baidu.com                                        
 *   created time: 17/12/29-12:12                                    
 *  modified time: 17/12/29-12:12                                    
 *******************************************************************************/
#include <iostream>
#include <stack>
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
	void beh_traverse(TreeNode* pTree, TreeNode* x)  
	{  
		cout<<"start traverse!"<<endl;
		stack<TreeNode*> mstack;
		TreeNode* pCur;              //定义指针，指向当前节点  
		TreeNode* pPre = NULL;       //定义指针，指向上一各访问的节点  
	  
		//先将树的根节点入栈  
		mstack.push(pTree);
		//直到栈空时，结束循环  
		while(!mstack.empty())  
		{  
			//当前节点置为栈顶节点  
			pCur = mstack.top();
			if((pCur->left==NULL && pCur->right==NULL) ||   
				(pPre!=NULL && (pCur->left==pPre || pCur->right==pPre)))  
			{  
				//如果当前节点没有左右孩子，或者有左孩子或有孩子，但已经被访问输出，  
				//则直接输出该节点，将其出栈，将其设为上一个访问的节点  
				//printf("%c ", pCur->data);  
				if (pCur ==x)
				{
					_vec.clear();
					_vec.push_back(pCur);
					while( !mstack.empty())
					{
						pCur = mstack.top();
						mstack.pop();
						cout<<"path for x:"<<pCur->val<<endl;
						_vec.push_back(pCur);
					}
					return;
				}
				mstack.pop();
				pPre = pCur;  
			}  
			else  
			{  
				//如果不满足上面两种情况,则将其右孩子左孩子依次入栈  
				if(pCur->right != NULL)  
					mstack.push(pCur->right);
				if(pCur->left != NULL)  
					mstack.push(pCur->left);
			}  
		}  
	}  	
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (!root || !p || !q)
            return NULL;

		beh_traverse(root, p);
		vector<TreeNode*> vec_p(_vec);
		beh_traverse(root, q);
		vector<TreeNode*> vec_q(_vec);

		vector<TreeNode*>::iterator it_q;
		vector<TreeNode*>::iterator it_p;
		for (it_q = vec_q.begin(); it_q != vec_q.end(); it_q++)
		{
			for (it_p = vec_p.begin(); it_p != vec_p.end(); it_p++)
			{
				if (*it_p == *it_q)
					return *it_p;
			}
		}
		return root; 
    }
private:
	vector<TreeNode*> _vec;
};
int main()
{
	Solution sol;
	TreeNode node1(2);
	TreeNode node2(1);
	TreeNode node3(3);

	node1.left = &node2;
	node1.right = &node3;

	TreeNode* ret;
	ret = sol.lowestCommonAncestor(&node1, &node2, &node3);
	cout<<"ret is:"<<ret->val<<endl;
}


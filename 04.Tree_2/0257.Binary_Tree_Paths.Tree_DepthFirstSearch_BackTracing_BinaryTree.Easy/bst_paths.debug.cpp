/*******************************************************************************
 *      file name: bst_paths.cpp                                               
 *         author: Hui Chen. (c) 17                             
 *           mail: chenhui13@baidu.com                                        
 *   created time: 17/12/30-12:12                                    
 *  modified time: 17/12/30-12:12                                    
 *******************************************************************************/
#include <iostream>
#include <stack>
#include <vector>
#include <sstream> 
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
	TreeNode* getParent(TreeNode* root, TreeNode* x)
	{
		if (root == NULL)
			return NULL;
		if (root->left == x || root->right == x)
			return root;
		//return  (getParent(root->left, x) ||  getParent(root->left, x));
		TreeNode* ret_left =  getParent(root->left, x);
		if (ret_left)
			return ret_left;
		return  getParent(root->right, x);
	}

    vector<string> binaryTreePaths(TreeNode* root) {
		vector<string> ret;
		stack<TreeNode*> s;  //创建一个空栈  
		//stack<TreeNode*> s2;  //创建一个空栈  
		TreeNode* node_pop;                 //用来保存出栈节点  
		TreeNode* pCur = root;             //定义指向当前访问的节点的指针  
	  
		//直到当前节点pCur为NULL且栈空时，循环结束  
		while(pCur || !s.empty())  
		{  
			if(pCur->left)  
			{  
				//如果pCur的左孩子不为空，则将其入栈，并置其左孩子为当前节点  
				//push_stack(stack,pCur);  
				s.push(pCur);
				pCur = pCur->left;  
			}  
			else  
			{  
				//如果pCur的左孩子为空，则输出pCur节点，并将其右孩子设为当前节点，看其是否为空  
				//printf("%c ", pCur->data);  
				if (!pCur->left && !pCur->right)
				{
					stack<TreeNode*> s2;  //创建一个空栈  
					string str;
					TreeNode* parent = pCur;
					while (parent != root)
					{
						s2.push(parent);
						cout<<"path for p:"<<parent->val<<endl;
						parent = getParent(root, parent); 
					}
				    s2.push(root);

					stringstream stream;
					TreeNode* x = s2.top();
					cout<<"leaf: pCur->val"<<x->val<<endl;
					stream<<x->val;
					string temp;
					stream>>temp;
					str.append(temp);
					s2.pop();
					while (!s2.empty())
					{
						stringstream stream;
						TreeNode* x = s2.top();
						str.append("->");
						cout<<"leaf: pCur->val"<<x->val<<endl;
						stream<<x->val;
						string temp;
						stream>>temp;
						str.append(temp);
						s2.pop();
					}
					ret.push_back(str);
				}
				pCur = pCur->right;  
				//如果为空，且栈不空，则将栈顶节点出栈，并输出该节点，  
				//同时将它的右孩子设为当前节点，继续判断，直到当前节点不为空  
				while(!pCur && !s.empty())  
				{  
					pCur = s.top();  
					if (!pCur->left && !pCur->right)
					{
						stack<TreeNode*> s2;  //创建一个空栈  
						string str;
						TreeNode* parent = pCur;
						while (parent != root)
						{
							s2.push(parent);
							cout<<"path for p:"<<parent->val<<endl;
							parent = getParent(root, parent); 
						}
				        s2.push(root);

						stringstream stream;
						TreeNode* x = s2.top();
						cout<<"leaf: pCur->val"<<x->val<<endl;
						stream<<x->val;
						string temp;
						stream>>temp;
						str.append(temp);
						s2.pop();
						while (!s2.empty())
						{
							stringstream stream;
							TreeNode* x = s2.top();
							str.append("->");
							cout<<"leaf: pCur->val"<<x->val<<endl;
							stream<<x->val;
							string temp;
							stream>>temp;
							str.append(temp);
							s2.pop();
						}
						ret.push_back(str);
					}

					//printf("%c ",pCur->data);      
					s.pop();
					pCur = pCur->right;  
				}  
			}  
		}  
		return ret;
	}  
};

int main()
{
	Solution sol;
	TreeNode n1(1), n2(2), n3(3), n4(4), n5(5);
	n1.left = &n2;
	n1.right = &n3;
	n2.right = &n5;
	vector<string> ret;
	ret = sol.binaryTreePaths(&n1);
	vector<string>::iterator it;
	for(it = ret.begin(); it != ret.end(); it++)
	{
		cout<<"ret :"<<*it<<endl;
	}
}

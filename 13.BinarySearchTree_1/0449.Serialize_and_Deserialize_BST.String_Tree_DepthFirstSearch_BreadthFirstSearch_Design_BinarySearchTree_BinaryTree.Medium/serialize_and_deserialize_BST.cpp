/*******************************************************************************
 *      file name: serialize_and_deserialize_BST.cpp                                               
 *         author: Hui Chen. (c) 2022                             
 *           mail: alex.chenhui@gmail.com                                        
 *   created time: 2022/01/26-22:34:55                              
 *  modified time: 2022/01/26-22:34:55                              
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
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string res;
        if (!root) return res;
        res = pre_order(root) + ":" + in_order(root);
        //cout<<"res:"<<res<<endl;
        return res;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        int pos = data.find(":");
        if (pos == string::npos) return NULL;
        string pre = data.substr(0,pos-1);
        string in = data.substr(pos+1, data.length() - pos - 2);
        //cout<<"pre:"<<pre<<",in:"<<in<<endl;
        vector<string> v_pre = split(pre,",");
        vector<int> v1;
        for (auto e : v_pre) {
            //cout<<"e:"<<e<<endl;
            v1.push_back(stoi(e));
        }
        vector<string> v_in = split(in, ",");
        vector<int> v2;
        for (auto e : v_in) {
            //cout<<"f:"<<e<<endl;
             v2.push_back(stoi(e));
        }
        
        TreeNode* root =  dfs(v1, v2);
        return root;
    }
    
    TreeNode* dfs(vector<int> vp, vector<int> vi) {
        if (!vp.size()) return NULL;
        int x = vp[0];
        vector<int>::iterator it = find(vi.begin(), vi.end(), x);
        vector<int> vi1(vi.begin(), it);
 
        vector<int> vi2(it+1,vi.end());

        vector<int> vp1(vp.begin()+1,vp.begin()+1+vi1.size());

        vector<int> vp2(vp.begin()+1+vi1.size(), vp.end());

        TreeNode* root = new TreeNode(x);
        root->left = dfs(vp1,vi1);
        root->right = dfs(vp2, vi2);
        return root;
    }
    
    
    string pre_order(TreeNode* root) {
        if (!root) return "";
        string res;
        res += to_string(root->val);
        res += ",";
        res += pre_order(root->left);
        res += pre_order(root->right);
        return res;
    }
    
    string in_order(TreeNode* root) {
        if (!root) return "";
        string res;
        res += in_order(root->left);
        res += to_string(root->val);
        res += ",";
        res += in_order(root->right);
        return res;
    }   
   
std::vector<std::string> split(std::string str,std::string pattern)
{
  std::string::size_type pos;
  std::vector<std::string> result;
  str+=pattern;//扩展字符串以方便操作
  int size=str.size();

  for(int i=0; i<size; i++)
  {
    pos=str.find(pattern,i);
    if(pos<size)
    {
      std::string s=str.substr(i,pos-i);
      result.push_back(s);
      i=pos+pattern.size()-1;
    }
  }
  return result;
}
    
};

// Your Codec object will be instantiated and called as such:
// Codec* ser = new Codec();
// Codec* deser = new Codec();
// string tree = ser->serialize(root);
// TreeNode* ans = deser->deserialize(tree);
// return ans;
int main()
{}

/*******************************************************************************
 *      file name: trie_tree.cpp                                               
 *         author: Hui Chen. (c) 2018                             
 *           mail: chenhui13@baidu.com                                        
 *   created time: 2018/07/18-10:46:50                              
 *  modified time: 2018/07/18-10:46:50                              
 *******************************************************************************/
#include <iostream>
using namespace std;
struct TreeNode {
	bool leaf;
	TreeNode* dicts[26];
};

class Trie {
public:
    /** Initialize your data structure here. */
    Trie() {
       root = new TreeNode(); 
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
		TreeNode* p = root;
		for (int i = 0; i < word.length(); i++)
		{
			char x = word[i];
			if (p->dicts[x - 'a'] != NULL)
			{
				p = p->dicts[x - 'a'];
			}
			else //(p->dicts[x - 'a'] == NULL)
			{
				p->dicts[x - 'a'] = new TreeNode();
				p = p->dicts[x - 'a'];
			}
		}
		p->leaf = true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
		TreeNode* p = root;
		for (int i = 0; i < word.length(); i++)
		{
			char x = word[i];
			if (p->dicts[x - 'a'] != NULL)
			{
				p = p->dicts[x - 'a'];
			}
			else
				return false;
		}
		if (p && p->leaf )
			return true;
		return false;
		
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
		TreeNode* p = root;
		for (int i = 0; i < prefix.length(); i++)
		{
			char x = prefix[i];
			if (p->dicts[x - 'a'] != NULL)
			{
				p = p->dicts[x - 'a'];
			}
			else
				return false;
		}
		return true;
        
    }
private:
	TreeNode* root;
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie obj = new Trie();
 * obj.insert(word);
 * bool param_2 = obj.search(word);
 * bool param_3 = obj.startsWith(prefix);
 */

int main()
{
	Trie trie;

	bool ret = false;
	trie.insert("apple");
	ret = trie.search("apple");   // returns true
	cout<<"ret of search apple:"<<ret<<endl;
	ret = trie.search("app");     // returns false
	cout<<"ret of search app:"<<ret<<endl;
	ret = trie.startsWith("app"); // returns true
	cout<<"ret of startWith app:"<<ret<<endl;
	trie.insert("app");   
	ret = trie.search("app");     // returns true
	cout<<"ret of search app:"<<ret<<endl;
}

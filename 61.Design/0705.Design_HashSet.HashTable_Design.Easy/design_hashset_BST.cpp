/*******************************************************************************
 *      file name: design_hashset.cpp                                               
 *         author: Hui Chen. (c) 2018                             
 *           mail: chenhui13@baidu.com                                        
 *   created time: 2018/09/21-22:13:09                              
 *  modified time: 2018/09/21-22:13:09                              
 *******************************************************************************/
#include <iostream>
#include <map>
using namespace std;

struct Node {
	int val;
	Node* left;
	Node* right;
	Node(int x) {
		val = x;
		left = NULL;
        right = NULL;
	}
	Node() {
		val = 0;
		left = NULL;
        right = NULL;
	}
	~Node() {
		if (left) delete left;
		if (right) delete right;
	}
};

class BST {
public:
    BST() 
    {
        _root = NULL;
    }
    
    ~BST() {
        delete _root;
    }
	bool exist(int v) {
		if (!_root) return false;

		Node* p = _root;
		while (p)
		{
			if (v == p->val) 
            {
				return true;
            }
			else if (v < p->val)
				p = p->left;
			else
				p = p->right;
		}
		return false;
	}

	Node* find(int v, Node* parent) {
		parent = _root;
		if (!_root) NULL;
		Node* p = _root;

		while (p)
		{
			if (v == p->val)
				return p; 
			else if (v < p->val)
			{
				parent = p;
				p = p->left;
			}
			else
			{
				parent = p;
				p = p->right;
			}
		}
		return NULL;
	}

	int insert(int v) {
		if (!_root) {
			Node* node = new Node(v);
			_root = node;
			return 0;
		}
		if (exist(v)) return -1;

		Node* p = _root;
		Node* parent = NULL;
		while (p)
		{
			parent = p;
			if (v < p->val)
				p = p->left;
			else
				p = p->right;
		}

		Node* node = new Node(v);
		if (v < parent->val)
			parent->left = node;
		else
			parent->right = node;
		return 0;
	}
	
	bool remove(int v) {
		if (!_root) {
			return false;
		}
		if (!exist(v)) return false;

		Node* parent = NULL;
		Node* p = find(v, parent);
		if (p->left)
		{
			Node* q = p;
			p = p->left;
			Node* parent = p;
			while (p->right)
			{
				parent = p;
				p = p->right;
			}
			p->right = q->right;
			parent->right = p->left;
			p->left = q->left;
		}
		else if(p->right)
		{
			Node* q = p;
			p = p->right;
			Node* parent = p;
			while (p->left)
			{
				parent = p;
				p = p->left;
			}
			p->left = q->left;
			parent->left = p->right;
			p->right = q->right;
		}
		else
		{
            if (parent == NULL)
                return false;
			if (parent == p)//this is root node;
			{
				_root = NULL;
			}
			else if (p == parent->left)
			{
				parent->left = NULL;
			}
			else
			{
				parent->right = NULL;
			}
			delete p;
		}
		return true;
	}


private:
	Node* _root;
};

class MyHashSet {
public:
    /** Initialize your data structure here. */
    MyHashSet() {
    }
    
    void add(int key) {
		bst.insert(key);
    }
    
    void remove(int key) {
		bst.remove(key);
    }
    
    /** Returns true if this set contains the specified element */
    bool contains(int key) {
		return bst.exist(key);
    }
    
private:
	BST bst;
};



/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet obj = new MyHashSet();
 * obj.add(key);
 * obj.remove(key);
 * bool param_3 = obj.contains(key);
 */
int main()
{
	MyHashSet hashSet;
hashSet.add(1);         
hashSet.add(2);         
hashSet.contains(1);    // returns true
hashSet.contains(3);    // returns false (not found)
hashSet.add(2);          
hashSet.contains(2);    // returns true
hashSet.remove(2);          
hashSet.contains(2);    // returns false (already removed)
}

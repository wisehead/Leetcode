/*******************************************************************************
 *      file name: camelcase_matching.trie.cpp                                               
 *         author: hui chen. (c) 25                             
 *           mail: alex.chenhui@gmail.com                                        
 *   created time: 25/01/20- 1:01                                    
 * modified time: 25/01/20- 1:01                                    
 *******************************************************************************/
#include <iostream>

class TrieNode {
public:
    char data;
    TrieNode* children[58]; // Support for uppercase (A-Z) and lowercase (a-z)
    bool isTerminal;

    TrieNode(char ch) : data(ch), isTerminal(false) {
        for (int i = 0; i < 58; i++) children[i] = nullptr;
    }
};

class Trie {
    TrieNode* root;

    void insertUtil(TrieNode* root, string& word, int i) {
        if (i >= word.size()) {
            root->isTerminal = true;
            return;
        }
        int index = word[i] - 'A';
        if (!root->children[index]) {
            root->children[index] = new TrieNode(word[i]);
        }
        insertUtil(root->children[index], word, i + 1);
    }

    bool searchUtil(TrieNode* root, string& word, int i) {
        if (i >= word.size()) {
            return root->isTerminal;
        }
        int index = word[i] - 'A';
        if (root->children[index]) {
            return searchUtil(root->children[index], word, i + 1);
        } else if (islower(word[i])) {
            // Skip lowercase letters in the query
            return searchUtil(root, word, i + 1);
        }
        return false; // Uppercase mismatch
    }

public:
    Trie() {
        root = new TrieNode('\0');
    }

    void insert(string& word) {
        insertUtil(root, word, 0);
    }

    bool search(string& word) {
        return searchUtil(root, word, 0);
    }
};

class Solution {
public:
    vector<bool> camelMatch(vector<string>& queries, string pattern) {
        vector<bool> ans;
        Trie trie;

        // Insert the pattern into the Trie
        trie.insert(pattern);

        // Check each query against the pattern in the Trie
        for (auto query : queries) {
            ans.push_back(trie.search(query));
        }

        return ans;
    }
};

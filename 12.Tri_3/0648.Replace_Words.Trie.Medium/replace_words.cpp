/*******************************************************************************
 *      file name: replace_words.cpp                                               
 *         author: hui chen. (c) 25                             
 *           mail: alex.chenhui@gmail.com                                        
 *   created time: 25/01/15- 1:01                                    
 * modified time: 25/01/15- 1:01                                    
 *******************************************************************************/
#include <iostream>
struct Node {
    vector<Node*> nodes;
    Node() {
        nodes.resize(26, NULL);
    }
};

class Trie {
public:
    Trie(vector<string>& dict) {
        root = new Node();
        for (auto str : dict) {
            db.insert(str);
            Node* p = root;
            for (auto c : str) {
                if (!p->nodes[c - 'a']) {
                    p->nodes[c-'a'] = new Node();
                }
                p = p->nodes[c-'a'];
            }
        }
    }
    string query(string str) {
        Node* p = root;
        string s;
        for (int i = 0; i < str.length(); i++) {
            int idx = str[i] - 'a';
            if (!p->nodes[idx]) {
                s = str.substr(0,i);
                break;
            } else {
                s = str.substr(0,i+1);
                if (db.count(s)) break;
            }
            p = p->nodes[idx];
        }
        if (!p) s = str;
        if (db.count(s)) return s;
        return "";
    }
public:
    Node* root;
    set<string> db;
};

class Solution {
public:
    string replaceWords(vector<string>& dictionary, string sentence) {
        Trie trie(dictionary);
        stringstream ss(sentence);
        string word;
        string res;
        while (ss >> word) {
            string prefix = trie.query(word);
            if (prefix.length() > 0) {
                res += prefix + " ";
            } else {
                res += word + " ";
            }
        }
        res.pop_back();
        return res;
    }
};

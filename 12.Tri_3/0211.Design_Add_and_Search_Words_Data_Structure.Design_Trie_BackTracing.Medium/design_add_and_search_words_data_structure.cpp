/*******************************************************************************
 *      file name: design_add_and_search_words_data_structure.cpp                                               
 *         author: Hui Chen. (c) 2020                             
 *           mail: chenhui13@baidu.com                                        
 *   created time: 2020/10/07-21:16:58                              
 *  modified time: 2020/10/07-21:16:58                              
 *******************************************************************************/
#include <iostream>
using namespace std;
struct Node {
    char c;
    bool f;
    Node* array[26];
    Node(char x, bool b) {
        c = x; f = b; 
        for (int i = 0; i < 26; i++) array[i] = nullptr;
    }
};
class WordDictionary {
public:
    /** Initialize your data structure here. */
    WordDictionary() {
        _root = new Node(0, false);
    }
    
    /** Adds a word into the data structure. */
    void addWord(string word) {
        //cout<<"add word:"<<word<<endl;
        Node* p = _root;
        for (char e : word) {
            //if (e == '.') cout<<""
            if (!p->array[e - 'a']) {
                p->array[e - 'a'] = new Node(e, false);
            }
            p = p->array[e - 'a'];
        }
        p->f = true; 
    }
    
    
    /** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
    bool search(string word) {
        return search(word, _root);
    }
    bool search(string word, Node* root) {
        //cout<<"search word:"<<word<<"   root->c:"<<root->c<<endl;
        Node* p = root;
        if (!p) return false;
        for (int i = 0; i < word.length(); i++) {
            char e = word[i];
            if (e != '.') {
                if (!p->array[e - 'a']) return false;
                p = p->array[e - 'a'];
            } else {
                for (int j = 0; j < 26; j++) {
                    string sub = word.substr(i+1);
                    if (p->array[j]) {
                        if (search(sub, p->array[j])) return true;
                    } 
                }
                return false;
            }
        }
        
        if (!p->f) return false;
        return true;
    }
private:
    Node* _root;
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */
int main()
{}

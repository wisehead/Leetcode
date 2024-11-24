/*******************************************************************************
 *      file name: reverse_prefix_of_word.cpp                                               
 *         author: hui chen. (c) 24                             
 *           mail: alex.chenhui@gmail.com                                        
 *   created time: 24/09/25- 9:09                                    
 * modified time: 24/09/25- 9:09                                    
 *******************************************************************************/
#include <iostream>
class Solution {
public:
    string reversePrefix(string word, char ch) {
        stack<char> stk;
        string res;
        if (word.find(ch) == string::npos) return word;
        int i = 0;
        for (; i < word.length() && ch != word[i]; i++) {
            stk.push(word[i]);
        }
        res.append(1, ch);
        while (!stk.empty()) {
            char c = stk.top();
            stk.pop();
            res.append(1, c);
        }
        string remain = word.substr(i+1);
        cout<<"res:"<<res<<",remain:"<<remain<<endl;
        res += remain;
        return res;

    }
};

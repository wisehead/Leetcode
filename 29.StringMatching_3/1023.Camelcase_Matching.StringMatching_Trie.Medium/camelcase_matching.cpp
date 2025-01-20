/*******************************************************************************
 *      file name: camelcase_matching.cpp                                               
 *         author: hui chen. (c) 25                             
 *           mail: alex.chenhui@gmail.com                                        
 *   created time: 25/01/20- 1:01                                    
 * modified time: 25/01/20- 1:01                                    
 *******************************************************************************/
#include <iostream>
class Solution {
public:
    int hit(string str, int start, char c) {
        // cout<<"str:"<<str<<", start:"<<start<<",c:"<<c<<endl;
        for (int i = start; i < str.length(); i++) {
            if (str[i] == c) return i;
            if (isupper(str[i])) return -1;
        }
        return -1;
    }

    bool has_up(string str, int start) {
        for (int i = start; i < str.length(); i++) {
            if (isupper(str[i])) return true;
        }
        return false;
    }
    vector<bool> camelMatch(vector<string>& queries, string pattern) {
        int n = queries.size();
        vector<bool> res(n, true);
        for (int j = 0; j < n; j++) {
            string str = queries[j];
            int i = 0;
            for (auto c : pattern) {
                i = hit(str, i, c);
                if (i == -1) {
                    res[j] = false;
                    break;
                }
                i++;
            }
            if (has_up(str, i)) res[j] = false;
        }
        return res;
    }
};

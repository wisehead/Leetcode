/*******************************************************************************
 *      file name: check_if_a_string_contains_all_binary_codes_of_size_k.bruce.cpp                                               
 *         author: hui chen. (c) 25                             
 *           mail: alex.chenhui@gmail.com                                        
 *   created time: 25/01/21- 1:01                                    
 * modified time: 25/01/21- 1:01                                    
 *******************************************************************************/
#include <iostream>
class Solution {
public:
    bool hasAllCodes(string s, int k) {
        if (s.length() < (1<<k)+k-1) return false;
        unordered_set<string> my_set;
        int n = s.length();
        int power = 1<<k;
        string str = s.substr(0,k);
        my_set.insert(str);
        for (int i = 1; i <= n-k; i++) {
            str.erase(0, 1);
            str += s[i+k-1];
            // cout<<"i:"<<i<<",str:"<<str<<endl;
            // string str = s.substr(i,k);
            // for (int j = i; j < i+k; j++) {
            //     str += s[j];
            // }
            my_set.insert(str);
            if (my_set.size() == power) return true;
        }
        // int power = 1<<k;
        return false;
    }
};

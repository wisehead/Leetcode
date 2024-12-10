/*******************************************************************************
 *      file name: kth_distinct_string_in_an_array.cpp                                               
 *         author: hui chen. (c) 24                             
 *           mail: alex.chenhui@gmail.com                                        
 *   created time: 24/11/29-11:11                                    
 * modified time: 24/11/29-11:11                                    
 *******************************************************************************/
#include <iostream>
class Solution {
public:
    string kthDistinct(vector<string>& arr, int k) {
        vector<string> res;
        unordered_map<string, int> ht;
        for (auto str : arr) {
            ht[str]++;
        }
        for (auto str : arr) {
            if (ht[str] == 1) res.push_back(str);
        }
        if (k <= res.size())
            return res[k-1];
        return "";
    }
};

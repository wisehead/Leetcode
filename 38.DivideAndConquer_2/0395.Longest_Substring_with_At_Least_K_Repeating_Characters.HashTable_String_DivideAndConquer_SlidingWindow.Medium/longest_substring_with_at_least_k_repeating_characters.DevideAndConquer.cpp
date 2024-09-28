/*******************************************************************************
 *      file name: longest_substring_with_at_least_k_repeating_characters.cpp                                               
 *         author: Hui Chen. (c) 2021                             
 *           mail: alex.chenhui@gmail.com                                        
 *   created time: 2021/12/05-20:31:12                              
 *  modified time: 2021/12/05-20:31:12                              
 *******************************************************************************/
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
class Solution {
public:
    int longestSubstring(string s, int k) {
        if(s.size() == 0 || k > s.size())   return 0;
        if(k == 0)  return s.size();

        unordered_map<char,int> Map;
        for(int i = 0; i < s.size(); i++){
            Map[s[i]]++;
        }

        int idx =0;
        while(idx <s.size() && Map[s[idx]] >= k)    idx++;
        if(idx == s.size()) return s.size();

        int left = longestSubstring(s.substr(0 , idx) , k);
        int right = longestSubstring(s.substr(idx+1) , k);

        return max(left, right);

    }
};
int main()
{}

/*******************************************************************************
 *      file name: longest_substring_with_at_least_k_repeating_characters.cpp                                               
 *         author: Hui Chen. (c) 2021                             
 *           mail: alex.chenhui@gmail.com                                        
 *   created time: 2021/12/05-20:31:12                              
 *  modified time: 2021/12/05-20:31:12                              
 *******************************************************************************/
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int longestSubstring(string s, int k) {
        //vector<int> cnt(26, 0);
        int N = s.length();
        int max1 = 0;
        for (int i = 0; i < N; i++) {
            vector<int> cnt(26, 0);
            //cnt[s[i]-'a']++;
            for (int j = i; j < N; j++) {
                cnt[s[j]-'a']++;
                if (valid(cnt,k)) {
                    if (j-i+1 > max1) max1 = j-i+1;
                }
            }
        } 
        return max1;
        
    }
    
    bool valid(vector<int> &cnt, int k) {
        for (auto e : cnt) {
            if (e && e < k) return false;
        }
        return true;
    }
};
int main()
{}

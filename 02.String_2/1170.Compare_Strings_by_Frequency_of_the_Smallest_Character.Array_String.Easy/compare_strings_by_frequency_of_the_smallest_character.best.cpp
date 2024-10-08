/*******************************************************************************
 *      file name: compare_strings_by_frequency_of_the_smallest_character.cpp                                               
 *         author: Hui Chen. (c) 2020                             
 *           mail: chenhui13@baidu.com                                        
 *   created time: 2020/01/22-11:39:11                              
 *  modified time: 2020/01/22-11:39:11                              
 *******************************************************************************/
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    vector<int> numSmallerByFrequency(vector<string>& queries, vector<string>& words) {
        vector<int> fr(12, 0);
        int f;
        vector<int> q;
        for(int i = 0; i < words.size(); i++){
            f = getF(words[i]);
            fr[f]++;
        }
		//Find cumulative frequency i.e. ith item will have sum of i..end.
        for(int i = 9; i >= 0; i--){
            fr[i] = fr[i] + fr[i+1];
        }
        
        for(int i = 0; i < queries.size(); i++){
            f = getF(queries[i]);
            q.push_back(fr[f+1]);
        }
        return q;
    }
    /*Helper function to calculate frequency of smallest element*/
    int getF(string &s){
        int a[26] = {0,};
        for(int i = 0; i < s.size(); i++){
            a[s[i]-'a']++;
        }
        
        for(int i = 0; i < 26; i++){
            if(a[i] != 0) return a[i];
        }
        return 0;
    }
};
int main()
{}

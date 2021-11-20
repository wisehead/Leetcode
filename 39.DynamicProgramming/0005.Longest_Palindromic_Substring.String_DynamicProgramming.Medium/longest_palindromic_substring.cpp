/*******************************************************************************
 *      file name: longest_palindromic_substring.cpp                                               
 *         author: Hui Chen. (c) 2021                             
 *           mail: alex.chenhui@gmail.com                                        
 *   created time: 2021/11/20-18:18:41                              
 *  modified time: 2021/11/20-18:18:41                              
 *******************************************************************************/
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    string longestPalindrome(string s) {
        int N = s.length();
        string temp;
        vector<vector<int>> vec(N, vector<int>(N,0));
        for (int i = 0; i < N; i++) {
            vec[0][i] = 1;
            //temp = s.substr(i,1);
        }
        for (int i = 0; i < N-1; i++) {
            if (s[i+1] == s[i]) {
                vec[1][i] = 2;
                //temp = s.substr(i,2);
            }
            else 
                vec[1][i] = 1;
        }
        
        for (int level = 2; level < N; level++) {
            for (int i = 0; i < N-level; i++) {
                if (s[i+level] == s[i]) {
                    if (vec[level-2][i+1] == level-1) {
                        vec[level][i] = level+1;
                        //temp = s.substr(i,level+1);
                        //cout<<"temp:"<<temp<<endl;
                    }
                    else
                        vec[level][i] = max(vec[level-1][i], vec[level-1][i+1]);
                } else {
                    vec[level][i] = max(vec[level-1][i], vec[level-1][i+1]);
                }
            }
        }
        
        int x = vec[N-1][0];
        int level = x-1;
        for (int i = 0; i < N-level; i++) {
            if (vec[level][i] == level+1)
                temp = s.substr(i, level+1);
        }
        
        return temp;
    }
};
int main()
{}

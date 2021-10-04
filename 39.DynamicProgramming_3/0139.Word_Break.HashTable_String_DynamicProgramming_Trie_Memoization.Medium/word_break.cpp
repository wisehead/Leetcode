/*******************************************************************************
 *      file name: word_break.cpp                                               
 *         author: Hui Chen. (c) 2021                             
 *           mail: alex.chenhui@gmail.com                                        
 *   created time: 2021/08/07-21:31:02                              
 *  modified time: 2021/08/07-21:31:02                              
 *******************************************************************************/
#include <iostream>
#include <vector>
#include <set>
using namespace std;
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        vector<vector<int>> vv;
        set<string> ss;
        for (auto e : wordDict) {
            ss.insert(e);
        }
        int N = s.length();
        vector<int> vec(N, 0);
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N-i; j++) {
                string tmp = s.substr(j,i+1);
                vec[j] = 0;//reset each time.
                if (ss.count(tmp)) {
                    vec[j] = 1;
                    continue;
                }
                for (int x = 0; x < i; x++) {
                    vec[j] = (vv[x][j] && vv[i-1-x][j+x+1]);
                    if (vec[j]) break;
                }
            }
            vv.push_back(vec);
        }
        return vv[N-1][0];
    }
};
int main()
{}

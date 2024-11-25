/*******************************************************************************
 *      file name: matchsticks_to_square.cpp                                               
 *         author: Hui Chen. (c) 2021                             
 *           mail: alex.chenhui@gmail.com                                        
 *   created time: 2021/11/22-11:30:07                              
 *  modified time: 2021/11/22-11:30:07                              
 *******************************************************************************/
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    bool makesquare(vector<int>& matchsticks) {
        int N = matchsticks.size();
        unsigned long long sum = 0;
        int small = INT_MAX;
        for (auto e : matchsticks) {
            sum += e;
            if (e < small) small = e;
        }
        if (sum % 4) return false;
        int ave = sum/4;
        sort(matchsticks.begin(), matchsticks.end());
        reverse(matchsticks.begin(), matchsticks.end());
        bool ret;
        int curlen = 0;
        
        vector<bool> visited(N, false);
         bt(matchsticks, visited, ave, curlen, ret);
        return ret;
    }
    
    void bt(vector<int>& matchsticks, vector<bool>& visited, int ave, int curlen, bool& ret) {
        bool all = true;
        for (auto e : visited) {
            //cout<<","<<e;
            if (!e) {
                all = false;
            }
        }
        //cout<<endl;
        if (all)
            cout<<"curlen:"<<curlen<<endl;
        if (all & !curlen) {
            ret = true;
            return;
        }
        int N = matchsticks.size();
        int i = 0;
        for (i = 0; i < N; i++) {
            if (!visited[i]) {
                if (curlen + matchsticks[i] == ave) {
                    visited[i] = true;
                    curlen = 0;
                    int old_curlen = curlen;
                    bool ret2;
                    bt(matchsticks, visited, ave, curlen, ret2);
                    if (ret2) {
                        ret = true;
                        return;
                    }
                    visited[i] = false;
                    curlen = old_curlen;
                    continue;
                } else if (curlen + matchsticks[i] > ave) {
                    visited[i] = false;
                } else {
                    visited[i] = true;
                    curlen += matchsticks[i];
                    bool ret2;
                    bt(matchsticks, visited, ave, curlen, ret2);
                    if (ret2) {
                        ret = true;
                        return;
                    }
                    if (i == 0) {
                        ret = false;
                        return;
                    }
                    visited[i] = false;
                    curlen -= matchsticks[i];
                    continue;                    
                }
            }
        }
        /*
        for (auto e : visited) {
            cout<<","<<e;
        }
        cout<<"end."<<endl;    
        */
        ret = false;
        return;
    }
};
int main()
{}

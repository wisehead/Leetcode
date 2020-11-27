/*******************************************************************************
 *      file name: friend_circles.cpp                                               
 *         author: Hui Chen. (c) 2020                             
 *           mail: chenhui13@baidu.com                                        
 *   created time: 2020/11/27-15:17:44                              
 *  modified time: 2020/11/27-15:17:44                              
 *******************************************************************************/
#include <iostream>
#include <vector>
#include <set>
#include <map>
using namespace std;
class Solution {
public:
    int findCircleNum(vector<vector<int>>& M) {
        int N = M.size();
        vector<int> vec(N, 0);
        //set<int> s;
        map<int, set<int>> ht;
        int max_set_id = 0;
        for (int i = 0; i < N; i++) {
            for (int j = i; j < N; j++) {
                if (M[i][j]) {
                    //cout<<"vec["<<i<<"]:"<<vec[i]<<"  vec["<<j<<"]:"<<vec[j]<<endl;
                    int set_id = 0;
                    if (vec[i] || vec[j]) {
                        if (vec[i] && vec[j]) {
                            set_id = vec[i];
                            set<int> s = ht[vec[j]];
                            if (vec[i] != vec[j]) ht.erase(vec[j]);
                            set<int>::iterator it;
                            for (it = s.begin(); it != s.end(); it++) {
                                vec[*it] = set_id;
                                ht[vec[i]].insert(*it);
                            }
                        } else { //有一个是0
                            set_id = max(vec[i], vec[j]);
                            //cout<<"set_id:"<<set_id<<"ht.count(set_id):"<<ht.count(set_id)<<endl;
                            if (!vec[i]) {
                                ht[set_id].insert(i);
                                vec[i] = set_id;
                            } else {
                                ht[set_id].insert(j);
                                vec[j] = set_id;                                
                            }                          
                        }

                    } else {//if (vec[i] || vec[j]) 
                        set_id = ++max_set_id;
                        set<int> s;
                        s.insert(i);
                        s.insert(j);
                        ht[set_id] = s;
                        vec[i] = set_id;
                        vec[j] = set_id;                   
                    }
                    //cout<<"vec["<<i<<"]:"<<vec[i]<<"  vec["<<j<<"]:"<<vec[j]<<endl;
                    //cout<<"ht.size():"<<ht.size()<<endl;
                    //cout<<"===="<<endl;
                }//if (M[i][j])
            }
        }

        //cout<<"ht.size():"<<ht.size()<<endl;
        return ht.size();
    }
};
int main()
{}

/*******************************************************************************
 *      file name: friend_circles.cpp                                               
 *         author: Hui Chen. (c) 2020                             
 *           mail: chenhui13@baidu.com                                        
 *   created time: 2020/11/27-15:17:44                              
 *  modified time: 2020/11/27-15:17:44                              
 *******************************************************************************/
#include <iostream>
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
                    //cout<<"i:"<<i<<"    j:"<<j<<endl;
                    cout<<"vec["<<i<<"]:"<<vec[i]<<"  vec["<<j<<"]:"<<vec[j]<<endl;
                    int set_id = 0;
                    if (vec[i] || vec[j]) {
                        if (vec[i] && vec[j]) {
                            set_id = max(vec[i], vec[j]);
                            if (vec[i] > vec[j]) {
                                set<int> s = ht[vec[j]];
                                set<int>::iterator it;
                                for (it = s.begin(); it != s.end(); it++) {
                                    vec[*it] = set_id;
                                    ht[vec[i]].insert(*it);
                                }
                                ht.erase(vec[j]);
                            } else if  (vec[i] < vec[j]) {
                                set<int> s = ht[vec[i]];
                                set<int>::iterator it;
                                for (it = s.begin(); it != s.end(); it++) {
                                    vec[*it] = set_id;
                                    ht[vec[j]].insert(*it);
                                }
                                ht.erase(vec[i]);                                
                            }
                        } else { //有一个是0
                            set_id = max(vec[i], vec[j]);
                            if (!vec[i]) {
                                ht[vec[j]].insert(i);
                                vec[i] = set_id;
                            } else {
                                ht[vec[i]].insert(j);
                                vec[j] = set_id;                                
                            }
                            //cout<<"s.size():"<<s.size()<<endl;                            
                        }

                    } else {
                        set_id = ++max_set_id;
                        set<int> s;
                        s.insert(i);
                        s.insert(j);
                        ht[set_id] = s;
                        vec[i] = set_id;
                        vec[j] = set_id;                   
                    }
                    //cout<<"set_id:"<<set_id<<endl;
                    cout<<"vec["<<i<<"]:"<<vec[i]<<"  vec["<<j<<"]:"<<vec[j]<<endl;
                    cout<<"===="<<endl;
                }
            }
        }
        /*
        int cnt = 0;
        for (auto e : vec) {
            if (e == 0) {
                ++max_set_id;
                cnt++;
            }
        }
        */
        cout<<"ht.size():"<<ht.size()<<endl;
        //cout<<"cnt:"<<cnt<<endl;
        return ht.size();
    }
};
int main()
{}

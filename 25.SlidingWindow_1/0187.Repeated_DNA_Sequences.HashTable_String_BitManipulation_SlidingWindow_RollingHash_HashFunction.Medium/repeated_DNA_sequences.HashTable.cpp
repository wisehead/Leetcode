/*******************************************************************************
 *      file name: repeated_DNA_sequences.cpp                                               
 *         author: Hui Chen. (c) 2021                             
 *           mail: alex.chenhui@gmail.com                                        
 *   created time: 2021/10/11-09:14:46                              
 *  modified time: 2021/10/11-09:14:46                              
 *******************************************************************************/
#include <iostream>
#include <vector>
#include <set>
using namespace std;
class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        vector<string> res;
        set<string> st2;
        set<string> st;
        int N = s.length();
        for (int i = 0; i < N-9; i++) {
            //cout<<"i:"<<i<<endl;
            string tmp = s.substr(i,10);
            //cout<<"tmp:"<<tmp<<endl;
            if (st.count(tmp)) st2.insert(tmp);
            else st.insert(tmp);
        }
        res.assign(st2.begin(), st2.end());
        return res;
    }
};
int main()
{}

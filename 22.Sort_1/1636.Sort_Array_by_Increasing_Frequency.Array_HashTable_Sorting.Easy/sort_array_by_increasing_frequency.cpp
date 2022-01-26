/*******************************************************************************
 *      file name: sort_array_by_increasing_frequency.cpp                                               
 *         author: Hui Chen. (c) 2022                             
 *           mail: alex.chenhui@gmail.com                                        
 *   created time: 2022/01/26-10:18:57                              
 *  modified time: 2022/01/26-10:18:57                              
 *******************************************************************************/
#include <iostream>
#include <vector>
#include <map>
using namespace std;
class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        map<int, int> m1;
        map<int, vector<int>> m2;
        vector<int> res;
        for (auto e : nums) m1[e]++;
        
        map<int, int>::iterator it;
        for (it = m1.begin(); it != m1.end(); it++) {
            m2[it->second].push_back(it->first); 
        }
        
        map<int, vector<int>>::iterator it2;
        for (it2 = m2.begin(); it2 != m2.end(); it2++) {
            int N = it2->second.size();
            for (int i = N-1; i >=0 ; i--) {
                int e = it2->second[i];
                res.insert(res.end(), it2->first, e);
            }
        }
        return res;
    }
};
int main()
{}

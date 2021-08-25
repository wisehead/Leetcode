/*******************************************************************************
 *      file name: sort_integers_by_the_number_of_1_bits.cpp                                               
 *         author: Hui Chen. (c) 2021                             
 *           mail: alex.chenhui@gmail.com                                        
 *   created time: 2021/08/25-09:22:54                              
 *  modified time: 2021/08/25-09:22:54                              
 *******************************************************************************/
#include <iostream>
#include <vector>
#include <set>
using namespace std;
class Solution {
public:
    int get_bits(int n) {
        int mask = 1;
        int cnt = 0;
        for (int i = 0; i < 15; i++) {
            if (n&mask) cnt++;
            mask = mask<<1;
        }
        return cnt;
    }
    vector<int> sortByBits(vector<int>& arr) {
        vector<multiset<int>> vec(15);
        vector<int> res;
        for (auto e : arr) {
            int cnt = get_bits(e);
            vec[cnt].insert(e);
        }
        
        for (auto st : vec) {
            vector<int> v(st.begin(), st.end());
            res.insert(res.end(), v.begin(), v.end());
        }
        return res;
    }
};
int main()
{}

/*******************************************************************************
 *      file name: check_if_N_and_its_double_exist.cpp                                               
 *         author: Hui Chen. (c) 2021                             
 *           mail: alex.chenhui@gmail.com                                        
 *   created time: 2021/08/23-20:02:27                              
 *  modified time: 2021/08/23-20:02:27                              
 *******************************************************************************/
#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;
class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        unordered_set<int> st;
        for (auto e : arr) {
            if (st.count(e*2)) return true;
            if (e % 2 == 0 && st.count(e/2)) return true;
            st.insert(e);
        }
        return false;
    }
};
int main()
{}

/*******************************************************************************
 *      file name: rank_transform_of_an_array.cpp                                               
 *         author: Hui Chen. (c) 2021                             
 *           mail: alex.chenhui@gmail.com                                        
 *   created time: 2021/07/31-17:22:30                              
 *  modified time: 2021/07/31-17:22:30                              
 *******************************************************************************/
#include <iostream>
#include <vector>
#include <map>
using namespace std;
class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        vector<int> res;
        map<int, int> mm;
        vector<int> vec(arr.begin(), arr.end());
        sort(vec.begin(), vec.end());
        int dup = 0;
        for (int i = 0; i < vec.size(); i++) {
            if (!mm.count(vec[i]))
                mm[vec[i]] = i+1-dup;
            else
                dup++;   
        }
        for (auto e : arr) 
            res.push_back(mm[e]);      
        return res;
    }
};
int main()
{}

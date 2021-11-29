/*******************************************************************************
 *      file name: number_of_good_pairs.cpp                                               
 *         author: Hui Chen. (c) 2021                             
 *           mail: alex.chenhui@gmail.com                                        
 *   created time: 2021/11/29-10:07:16                              
 *  modified time: 2021/11/29-10:07:16                              
 *******************************************************************************/
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int C(int n) {
        int sum = 0;
        for (int i = 0; i < n; i++) {
            sum += i;
        }
        return sum;
    }
    int numIdenticalPairs(vector<int>& nums) {
        vector<vector<int>> vec(101);
        int N = nums.size();
        for (int i = 0; i < N; i++) {
            int e = nums[i];
            vec[e].push_back(i);
        }
        
        int res = 0;  
        for (auto v : vec) {
            int size = v.size();
            
            res += C(size);
            //cout<<"size:"<<size<<", res:"<<res<<endl;
        }
        return res;
    }
};
int main()
{}

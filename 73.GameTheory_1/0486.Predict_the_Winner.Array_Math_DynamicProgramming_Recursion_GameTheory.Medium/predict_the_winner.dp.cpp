/*******************************************************************************
 *      file name: predict_the_winner.cpp                                               
 *         author: Hui Chen. (c) 2021                             
 *           mail: alex.chenhui@gmail.com                                        
 *   created time: 2021/09/30-11:06:52                              
 *  modified time: 2021/09/30-11:06:52                              
 *******************************************************************************/
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    bool PredictTheWinner(vector<int>& nums) {
        int N = nums.size();
        vector<int> vec1(nums);
        vector<int> vec2(N,0);
        vector<int> vec(nums);
        for (int step = 1; step < N; step++) {
            if (step == 1) {
                for (int i = N-2; i >= 0; i--) vec2[i] = max(vec1[i], vec1[i+1]);
                vec.assign(vec2.begin(), vec2.end());
                continue;
            }

            for (int i = N - 1 - step; i >= 0; i--) {
                int v1 = min(nums[i] + vec1[i+1], nums[i] + vec1[i+2]);
                int v2 = min(nums[i+step] + vec1[i+1], nums[i+step] + vec1[i]);
                vec[i] = max(v1,v2);
            }
            vec1.assign(vec2.begin(), vec2.end());
            vec2.assign(vec.begin(), vec.end());
        }
        bool ret = false;
        int sum = 0;
        for (auto e : nums) sum += e;
        int v1 = vec[0];
        if (v1 >= sum - v1) ret = true;
        return ret;
    }

};
int main()
{}

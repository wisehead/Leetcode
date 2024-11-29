/*******************************************************************************
 *      file name: check_if_all_1s_are_at_least_places.cpp                                               
 *         author: Hui Chen. (c) 2021                             
 *           mail: alex.chenhui@gmail.com                                        
 *   created time: 2021/11/20-10:22:38                              
 *  modified time: 2021/11/20-10:22:38                              
 *******************************************************************************/
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    bool kLengthApart(vector<int>& nums, int k) {
        int N = nums.size();
        for (int i = N-1; i >= 0; i--) {
            if (!nums[i]) {
                N--;
            } else
                break;
        }
        for (int i = 0; i < N-1; i++) {
            if (!nums[i]) continue;
            int cnt = 0;
            for (int j = i+1; j < N; j++) {
                if (nums[j]) break;
                cnt++;
            }
            //cout<<"cnt:"<<cnt<<endl;
            if (cnt < k) return false;
        }
        return true;
    }
};
int main()
{}

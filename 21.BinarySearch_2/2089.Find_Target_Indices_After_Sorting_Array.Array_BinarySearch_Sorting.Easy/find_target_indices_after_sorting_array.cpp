/*******************************************************************************
 *      file name: find_target_indices_after_sorting_array.cpp                                               
 *         author: hui chen. (c) 24                             
 *           mail: alex.chenhui@gmail.com                                        
 *   created time: 24/09/27- 9:09                                    
 * modified time: 24/09/27- 9:09                                    
 *******************************************************************************/
#include <iostream>
class Solution {
public:
    vector<int> targetIndices(vector<int>& nums, int target) {
        vector<int> res;
        sort(nums.begin(), nums.end());
        int left = 0, right = nums.size()-1;
        int mid = (left+right)/2;
        while (left < right) {
            cout<<"left:"<<left<<",right:"<<right<<",mid:"<<mid<<endl;
            if (nums[mid] == target) break;
            else if (nums[mid] > target) {
                right = mid;
            } else left = mid+1;
            mid = (left+right)/2;
            cout<<"2 left:"<<left<<",right:"<<right<<",mid:"<<mid<<endl;

        }
        if (mid > nums.size()-1 || nums[mid] != target) return res;
        int i = mid, j = mid;
        while (i>=0 && nums[i] == target) {
            i--;
        }
        i++;
        while (j <= nums.size()-1&&nums[j] == target) j++;
        j--;
        for (int k = i; k <= j; k++) res.push_back(k);
        return res;
    }
};

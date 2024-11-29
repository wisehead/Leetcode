/*******************************************************************************
 *      file name: remove_one_element_to_make_the_array_strictly_increasing.cpp                                               
 *         author: hui chen. (c) 24                             
 *           mail: alex.chenhui@gmail.com                                        
 *   created time: 24/09/22- 9:09                                    
 * modified time: 24/09/22- 9:09                                    
 *******************************************************************************/
#include <iostream>
class Solution {
public:
    bool canBeIncreasing(vector<int>& nums) {

        // check for singular or zero discountinuity from both sides of given array
        int ct1=0,ct2=0;
        int maxi = nums[0];
        int mini = nums[nums.size()-1];
        //check from front
        for(int i=1;i<nums.size();i++){
            if(maxi>=nums[i]) ct1++;
            maxi = max(maxi,nums[i]);
        }
        //check from back
        for(int i=nums.size()-2;i>=0;i--){
            if(mini<=nums[i]) ct2++;
            mini = min(mini,nums[i]);
        }

        //if any side traversal have only one or zero discontinuity then return true
        //because after removing singular discontinuity array can be made strictly      increasing
        cout<<"ct1:"<<ct1<<",ct2:"<<ct2<<endl;
        if(ct1==1||ct1==0||ct2==1||ct2==0) return true;

        return false;
    }
};

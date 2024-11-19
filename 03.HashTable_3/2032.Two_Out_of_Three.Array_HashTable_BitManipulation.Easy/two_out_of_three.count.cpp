/*******************************************************************************
 *      file name: two_out_of_three.cpp                                               
 *         author: hui chen. (c) 24                             
 *           mail: alex.chenhui@gmail.com                                        
 *   created time: 24/09/26- 9:09                                    
 * modified time: 24/09/26- 9:09                                    
 *******************************************************************************/
#include <iostream>
class Solution {
public:
    vector<int> twoOutOfThree(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3) {

        int arr1[101]={0};
        int arr2[101]={0};
        int arr3[101]={0};
        for(int i=0;i<nums1.size();i++)
        {
            arr1[nums1[i]]++;
        }
         for(int i=0;i<nums2.size();i++)
        {
            arr2[nums2[i]]++;
        }
         for(int i=0;i<nums3.size();i++)
        {
            arr3[nums3[i]]++;
        }
int count=0;
vector<int>vec;
        for(int i=1;i<101;i++)
        {
            if((arr1[i]>0&&arr2[i]>0)||(arr2[i]>0&&arr3[i]>0)||(arr1[i]>0&&arr3[i]>0))
            {   count++;
            vec.push_back(i);}

        }

        return vec;


    }
};

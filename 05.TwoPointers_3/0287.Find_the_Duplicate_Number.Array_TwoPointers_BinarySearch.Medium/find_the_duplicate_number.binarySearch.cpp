/*******************************************************************************
 *      file name: find_the_duplicate_number.cpp                                               
 *         author: Hui Chen. (c) 2019                             
 *           mail: chenhui13@baidu.com                                        
 *   created time: 2019/04/16-11:05:30                              
 *  modified time: 2019/04/16-11:05:30                              
 *******************************************************************************/
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
	int findDuplicate(vector<int>& nums) {
	    int n=nums.size()-1;
	    int low=1;
	    int high=n;
	    int mid;
	    while(low<high){
	        mid=(low+high)/2;
	        int count=0;
	        for(int num:nums){
	            if(num<=mid) count++;
	        }
	        if(count>mid) high=mid;
	        else low=mid+1; 
	    }
	    return low;
	}
};

int main()
{}

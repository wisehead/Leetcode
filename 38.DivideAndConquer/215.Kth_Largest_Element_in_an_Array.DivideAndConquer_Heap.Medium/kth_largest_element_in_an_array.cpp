/*******************************************************************************
 *      file name: kth_largest_element_in_an_array.cpp                                               
 *         author: Hui Chen. (c) 2020                             
 *           mail: chenhui13@baidu.com                                        
 *   created time: 2020/10/15-10:35:54                              
 *  modified time: 2020/10/15-10:35:54                              
 *******************************************************************************/
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int partition(vector<int>& nums, int k) {
        int mid = nums.size()/2;
        int pivot = nums[mid];
        nums[mid] = nums[0];
        nums[0] = pivot;
        int i = 0, j = nums.size()-1;
        bool flag = false;
        while (i < j) {
            if (!flag) {
                while (i < j && nums[j] >= pivot) j--;
                if (i < j) {
                    nums[i] = nums[j];
                    nums[j] = pivot;
                    flag = true;
                }
            } else {
                while (i < j && nums[i] < pivot) i++;
                if (i < j) {
                    nums[j] = nums[i];
                    nums[i] = pivot;
                    flag = false;
                }                
            }
        }
        if (i==0 && i+1 < nums.size()) return i+1;
        return i;
    }
    int f(vector<int>& nums, int k) {
        if (nums.size() == 0)return 0;
        int index = partition(nums, k);        
        if (index == k) return nums[k];
        if (index > k) {
            vector<int> vec(nums.begin(), nums.begin() + index);
            return f(vec, k);
        }
        vector<int> vec(nums.begin()+index, nums.end());
        return f(vec, k-index);
    }
    
    int findKthLargest(vector<int>& nums, int k) {
        k = nums.size() - k;
        int i = f(nums, k);
        return i;
    }
};

int main()
{
	Solution sol;
	/*
	int arr[] = {3,2,1,5,6,4};
	vector<int> vec(arr, arr+6);
	int arr[] = {3,2,3,1,2,4,5,5,6};
	vector<int> vec(arr, arr+9);
	*/
	int arr[] = {99,99};
	vector<int> vec(arr, arr+2);
	int n = sol.findKthLargest(vec, 1);
	cout<<"output:"<<n<<endl;
}



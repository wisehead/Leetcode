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
    int partition(vector<int>& nums, int start, int end, int k) {
		cout<<"partition(): start:"<<start<<"    end:"<<end<<"	k:"<<k<<endl;
        //if (end - start + 1 < k) return start;
		int mid = (start+end)/2;
        int pivot = nums[mid];
		nums[mid] = nums[start];
		nums[start] = pivot;
        int i = start, j = end;
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
        return i;
    }
    int f(vector<int>& nums, int start, int end, int k) {
        cout<<"f() "<< " start:"<<start<<"	end:"<<end<<"	k:"<<k<<endl;
		if (k == 1) return start;
        int index = partition(nums, start, end, k);
        cout<<"f() "<< " nums["<<index<<"]:"<<nums[index]<<endl;
		for (auto e : nums) {
			cout<<":"<<e;
		}
		cout<<endl;
        if (index == k) return nums[k];
        if (index > k) {
            return f(nums, start, index, k);
        }
        return f(nums, index, end, k-index+start);
    }
    
    int findKthLargest(vector<int>& nums, int k) {
		k = nums.size() - k;
        int i = f(nums, 0, nums.size()-1, k);
        return nums[i];
    }
};
int main()
{
	Solution sol;
	/*
	int arr[] = {3,2,1,5,6,4};
	vector<int> vec(arr, arr+6);
	*/
	int arr[] = {3,2,3,1,2,4,5,5,6};
	vector<int> vec(arr, arr+9);
	int n = sol.findKthLargest(vec, 4);
	cout<<"output:"<<n<<endl;
}



/*******************************************************************************
 *      file name: kth_largest_element_in_an_array.cpp                                               
 *         author: Hui Chen. (c) 2020                             
 *           mail: chenhui13@baidu.com                                        
 *   created time: 2020/10/15-10:35:54                              
 *  modified time: 2020/10/15-10:35:54                              
 *******************************************************************************/
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int> > pq;
        for (auto e : nums) {
            pq.push(e);
            if (pq.size() > k) pq.pop(); 
        }
        return pq.top();
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



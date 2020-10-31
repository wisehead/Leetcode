/*******************************************************************************
 *      file name: kth_largest_element_in_a_stream.cpp                                               
 *         author: Hui Chen. (c) 2018                             
 *           mail: chenhui13@baidu.com                                        
 *   created time: 2018/09/21-18:33:19                              
 *  modified time: 2018/09/21-18:33:19                              
 *******************************************************************************/
#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <queue>
using namespace std;
class KthLargest {
public:
    KthLargest(int k, vector<int> nums) {
        size = k;
        for (auto e : nums) {
            add(e);
        }
    }
    
    int add(int val) {
            if (heap.size() < size)
                heap.push(val);
            else
            {
                int x = heap.top();
                if (val > x) 
                {
                    heap.pop();
                    heap.push(val);
                }
            }   
        return heap.top();
    }
private:
	priority_queue<int, vector<int>, greater<int> > heap;
	int size;
};
/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest obj = new KthLargest(k, nums);
 * int param_1 = obj.add(val);
 */
int main()
{
	int k = 3;
	int arr[4] = {4,5,8,2};
	vector<int> vec(arr, arr+4);
	//KthLargest* kthLargest = new KthLargest(3, vec);
	KthLargest obj(3, vec);
	obj.add(3);   // returns 4
	/*
	kthLargest.add(5);   // returns 5
	kthLargest.add(10);  // returns 5
	kthLargest.add(9);   // returns 8
	kthLargest.add(4);   // returns 8
	*/
}

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
using namespace std;
class KthLargest {
public:
    KthLargest(int k, vector<int> nums) {
		//_vec.insert(_vec.end(), nums.begin(), nums.end());
		_vec = nums;
        sort(_vec.begin(), _vec.end());
		_k = k;
    }
    
    int add(int val) {
        //cout<<"----------"<<endl;
        //cout<<"val:"<<val<<endl;
		vector<int>::iterator it;
		for (it = _vec.begin(); it != _vec.end(); it++)
		{
            //cout<<"*it:"<<*it<<endl;
			if (val > *it)
				continue;
			_vec.insert(it, val);
            break;
		}
        if (it == _vec.end())
			_vec.insert(it, val);
		return _vec[_vec.size() - _k];
    }
private:
	vector<int> _vec;
	int _k;
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

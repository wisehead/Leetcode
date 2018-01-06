/*******************************************************************************
 *      file name: range_sum_query.cpp                                               
 *         author: Hui Chen. (c) 18                             
 *           mail: chenhui13@baidu.com                                        
 *   created time: 18/01/06- 1:01                                    
 *  modified time: 18/01/06- 1:01                                    
 *******************************************************************************/
#include <iostream>
#include <vector>
using namespace std;
class NumArray {
public:
    NumArray(vector<int> nums) {
		int size = nums.size();
		_sum.push_back(0);
		for (int i=0; i<size; i++)
		{
			_sum.push_back(_sum.back()+ nums[i]);
		}
    }
    
    int sumRange(int i, int j) {
		return (_sum[j+1] - _sum[i]);
    }
private:
	vector<int> _sum;
};
int main()
{
	int arr[] = {-2, 0, 3, -5, 2, -1};
	vector<int> nums(arr, arr+6);
	NumArray* obj = new NumArray(nums);
	int i = 0, j=0;
	int param_1 = 0;
	i =0; j=2;
	param_1 = obj->sumRange(i,j);
	cout<<"sum for i:"<<i<<" and j:"<<j<<" 	is:"<<param_1<<endl;
	i =2; j=5;
	param_1 = obj->sumRange(i,j);
	cout<<"sum for i:"<<i<<" and j:"<<j<<" 	is:"<<param_1<<endl;
	i =0; j=5;
	param_1 = obj->sumRange(i,j);
	cout<<"sum for i:"<<i<<" and j:"<<j<<" 	is:"<<param_1<<endl;

}

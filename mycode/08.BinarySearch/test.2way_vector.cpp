/*******************************************************************************
 *      file name: quit_sort.cpp                                               
 *         author: Hui Chen. (c) 2020                             
 *           mail: chenhui13@baidu.com                                        
 *   created time: 2020/09/12-07:55:33                              
 *  modified time: 2020/09/12-07:55:33                              
 *******************************************************************************/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int bs(vector<int> &vec, int n) {
	sort(vec.begin(), vec.end());
	int l = 0, r = vec.size();
	int mid = 0;
	while (l < r) {
		mid = (l+r)/2;
		if (vec[mid] == n) return mid;
		if (n > vec[mid]) {
			l = mid + 1;
		} else {
			r = mid;
		}
	}
	
    for (int i = 0; i < vec.size(); i++)
        cout<<vec[i]<<" ";
    cout<<endl;
	return l;
}

int main()
{
	int arr[] = {5,9,2,8,1,3,4,7,6};
	vector<int> vec(arr, arr+9);
	int pos = bs(vec, 7);
	cout<<"pos:"<<pos<<endl;
}

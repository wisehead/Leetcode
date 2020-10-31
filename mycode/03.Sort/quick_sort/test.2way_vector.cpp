/*******************************************************************************
 *      file name: quit_sort.cpp                                               
 *         author: Hui Chen. (c) 2020                             
 *           mail: chenhui13@baidu.com                                        
 *   created time: 2020/09/12-07:55:33                              
 *  modified time: 2020/09/12-07:55:33                              
 *******************************************************************************/
#include <iostream>
#include <vector>
using namespace std;

void qsort(vector<int> &vec, int start, int end) {
	if (end - start < 1) return; 
	int pivot = vec[start];
	int l = start+1, r = end;
	while (l < r) {
		while (vec[r] > pivot) r--;
		while (vec[l] <= pivot) l++;
		if (l < r) swap(vec[l], vec[r]);
	}
	swap(vec[start], vec[r]);
	qsort(vec, start, r-1);
	qsort(vec, r+1, end);
	
    for (int i = start; i <= end; i++)
        cout<<vec[i]<<" ";
    cout<<endl;
}

int main()
{
	int arr[] = {5,9,2,8,1,3,4,7,6};
	vector<int> vec(arr, arr+9);
	qsort(vec, 0, 8);
}

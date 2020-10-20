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

int qsort(int vec[], int len) {
	if (len <= 1) return 0;
	int mark = 0;
	int mid = vec[0];
	for (int i = 1;i <  len; ++i) {
		if (vec[i] > mid) continue;
		++mark;
		swap(vec[mark], vec[i]);
	}
	swap(vec[0], vec[mark]);

	int piv = mark;
	qsort(&vec[0], piv);
	qsort(&vec[piv+1],len - piv- 1);
    for (int i = 0; i < len; i++)
        cout<<vec[i]<<" ";
    cout<<endl;
}

int main()
{
	int arr[] = {5,9,2,8,1,3,4,7,6};
	//vector<int> vec(arr, arr+9);
	qsort(arr, 9);
}

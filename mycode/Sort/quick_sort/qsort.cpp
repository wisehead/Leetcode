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
	int piv = 0;
	int mid = vec[piv];
	int l = 0, r = len - 1;
	bool L_R = false;
	while (l <  r) {
		if (L_R) {//L
			if (vec[l] > mid) {
				swap(vec[l], vec[piv]);
				piv = l;
				L_R = false;
			}
            else
                l++;
		} else {//R
			if (vec[r] < mid) {
				swap(vec[r], vec[piv]);
				piv = r;
				L_R = true;
			} else {
                r--;
            }


		}
		
	}
	qsort(&vec[0], piv);
	qsort(&vec[piv+1],len - piv - 1);
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

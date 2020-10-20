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

int partition(int vec[], int start, int end) {
	if (end - start <= 0) return start;
	int piv = start;
	int mid = vec[piv];
	int l = start, r = end;
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
	return l;
}

void qsort(int vec[], int start, int end) {
	if (end - start <= 0) return;
	int piv = partition(vec, start, end);
	qsort(vec, start, piv-1);
	qsort(vec, piv+1, end);
    for (int i = start; i < end; i++)
        cout<<vec[i]<<" ";
    cout<<endl;
}

int main()
{
	int arr[] = {5,9,2,8,1,3,4,7,6};
	//vector<int> vec(arr, arr+9);
	qsort(arr, 0, 8);
}

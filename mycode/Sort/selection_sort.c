/*******************************************************************************
 *      file name: selection_sort.c                                               
 *         author: Hui Chen. (c) 2018                             
 *           mail: chenhui13@baidu.com                                        
 *   created time: 2018/12/22-16:06:48                              
 *  modified time: 2018/12/22-16:06:48                              
 *******************************************************************************/
#include <stdio.h>
void swap(int *a,int *b) //交換兩個變數
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
void selection_sort(int arr[], int len) 
{
	for (int i=0; i<len; i++)
	{
		int minv = arr[i];
		int pos = i;
		for(int j=i; j<len; j++)
		{
			if (arr[j] < minv)
			{
				minv = arr[j];
				pos = j;
			}
		}
		swap(&arr[i], &arr[pos]);
	}
}

int main()
{
    int arr[] = { 22, 34, 3, 32, 82, 55, 89, 50, 37, 5, 64, 35, 9, 70 };
    int len = (int) sizeof(arr) / sizeof(*arr);
    selection_sort(arr, len);
    int i;
    for (i = 0; i < len; i++)
        printf("%d ", arr[i]);
    return 0;
}

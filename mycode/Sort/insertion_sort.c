/*******************************************************************************
 *      file name: insertion_sort.c                                               
 *         author: Hui Chen. (c) 2018                             
 *           mail: chenhui13@baidu.com                                        
 *   created time: 2018/12/22-15:54:19                              
 *  modified time: 2018/12/22-15:54:19                              
 *******************************************************************************/
#include <stdio.h>
void insertion_sort(int arr[], int len) {
	for (int i=0; i<len; i++)
	{
		int x = arr[len-1];
		printf("i is:%d,	x is:%d\n",i,x);
		for (int j=len-1; j>i;j--)
		{
			arr[j] = arr[j-1];
		}
		for (int k = 0; k < len; k++)
			printf("%d ", arr[k]);
		printf("\n");

		int j = i-1;
		for (;j>=0;j--)
		{
			if (arr[j] > x)
				arr[j+1] = arr[j];
			else
			{
				j++;
				break;
			}
		}
		if (j < 0) j = 0;
		arr[j] = x;
		for (int k = 0; k < len; k++)
			printf("%d ", arr[k]);
		printf("\n");
		printf("\n");

	}
}

int main() {
    int arr[] = { 22, 34, 3, 32, 82, 55, 89, 50, 37, 5, 64, 35, 9, 70 };
    int len = (int) sizeof(arr) / sizeof(*arr);
    insertion_sort(arr, len);
    int i;
    for (i = 0; i < len; i++)
        printf("%d ", arr[i]);
    return 0;
}

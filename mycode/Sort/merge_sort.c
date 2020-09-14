/*******************************************************************************
 *      file name: bubble_sort.c                                               
 *         author: Hui Chen. (c) 2018                             
 *           mail: chenhui13@baidu.com                                        
 *   created time: 2018/12/22-15:54:19                              
 *  modified time: 2018/12/22-15:54:19                              
 *******************************************************************************/
#include <stdio.h>
void merge_sort(int arr[], int len) {

}

int main() {
    int arr[] = { 22, 34, 3, 32, 82, 55, 89, 50, 37, 5, 64, 35, 9, 70 };
    int len = (int) sizeof(arr) / sizeof(*arr);
    merge_sort(arr, len);
    int i;
    for (i = 0; i < len; i++)
        printf("%d ", arr[i]);
    return 0;
}

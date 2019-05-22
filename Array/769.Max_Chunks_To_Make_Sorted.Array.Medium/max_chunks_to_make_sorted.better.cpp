/*******************************************************************************
 *      file name: max_chunks_to_make_sorted.cpp                                               
 *         author: Hui Chen. (c) 2019                             
 *           mail: chenhui13@baidu.com                                        
 *   created time: 2019/05/22-09:44:01                              
 *  modified time: 2019/05/22-09:44:01                              
 *******************************************************************************/
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int check(vector<int>& arr, int s, int e) {
        for (int i = s; i <= e; i++)
        {
            if(arr[i] < s) return -1;
            if (arr[i] > e) e = arr[i];
        }
        return (e-s);
    }
    int maxChunksToSorted(vector<int>& arr) {
        int count = 0;
        for (int i = 0; i < arr.size(); i++)
        {
            if (arr[i] - i == 0) count++;
            else if (arr[i] - i > 0)
            {
                int r = check(arr, i, arr[i]);
                if (r > 0)
                {
                    i += r;
                    count++;
                }
                else return 1;
            }
        }
        return count;
    }
};
int main()
{}

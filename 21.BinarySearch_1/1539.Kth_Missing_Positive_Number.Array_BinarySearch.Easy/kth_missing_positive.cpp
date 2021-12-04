/*******************************************************************************
 *      file name: kth_missing_positive.cpp                                               
 *         author: Hui Chen. (c) 2021                             
 *           mail: alex.chenhui@gmail.com                                        
 *   created time: 2021/10/02-19:46:44                              
 *  modified time: 2021/10/02-19:46:44                              
 *******************************************************************************/
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int mid = 0;
        int l = 0;
        int r = arr.size();
        /*
        if (arr[r] - r - 1 < k) {
            return (k+arr.size());
        }
        */
        
        
        while (l < r) {
            mid = (l+r)/2;
            int delta = arr[mid] - mid - 1;
            if (delta < k) {
                l = mid+1;
            }
            else {
                r = mid;
            }
        }
        return (k+l);
    }
};
int main()
{}

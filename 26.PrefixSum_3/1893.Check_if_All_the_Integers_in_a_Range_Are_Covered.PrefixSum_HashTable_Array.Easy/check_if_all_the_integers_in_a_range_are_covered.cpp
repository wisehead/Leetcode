/*******************************************************************************
 *      file name: check_if_all_the_integers_in_a_range_are_covered.cpp                                               
 *         author: hui chen. (c) 24                             
 *           mail: alex.chenhui@gmail.com                                        
 *   created time: 24/09/12- 9:09                                    
 * modified time: 24/09/12- 9:09                                    
 *******************************************************************************/
#include <iostream>
class Solution {
public:
    bool isCovered(vector<vector<int>>& ranges, int left, int right) {
        sort(ranges.begin(), ranges.end());

        map<int, int> ht2;

        //map<int,int>::iterator it = ht.begin();
        int start = ranges[0][0];
        int end = ranges[0][1];

        for (auto vec : ranges) {
            if (vec[0] > end + 1) {
                ht2[start] = end;
                start = vec[0];
                end = vec[1];
            } else {
                end = max(end, vec[1]);
            }
        }
        ht2[start] = end;

        for (auto it = ht2.begin(); it != ht2.end(); it++) {
            cout<<"===first:"<<it->first<<",=======second:"<<it->second<<endl;
        }


        int y = left;
        for (; y >= 1; y--) {
            if (ht2.count(y)) break;
        }
        if (y == 0) return false;
        int x = ht2[y];
        int ret = x;

        for (; x <= right; ) {
            cout<<"---- x:"<<x<<endl;
            if (ht2.count(x)){
                if (ht2[x] == x) {
                    ret = x;
                    x++;
                }
                else {
                    x = ht2[x];
                    ret = x;
                }
            }
            else if (ht2.count(x+1)) {
                x = ht2[x+1];
                ret = x;
            }
            else break;
        }
        if (ret >= right) return true;
        return false;
    }
};

/*******************************************************************************
 *      file name: two_furthest_houses_with_different_colors.cpp                                               
 *         author: hui chen. (c) 24                             
 *           mail: alex.chenhui@gmail.com                                        
 *   created time: 24/12/11-12:12                                    
 * modified time: 24/12/11-12:12                                    
 *******************************************************************************/
#include <iostream>
class Solution {
public:
    int maxDistance(vector<int>& colors) {
        int n = colors.size();
        int ret = 0;
        for (int i = 0; i < n; i++) {
            for (int j = n-1; j > i; j--) {
                if (colors[j] != colors[i]) {
                    int len = j - i;
                    //cout<<"i:"<<i<<",j:"<<j<<",len:"<<len<<endl;
                    ret = max(len, ret);
                    break;
                }
            }
        }
        return ret;

    }
};

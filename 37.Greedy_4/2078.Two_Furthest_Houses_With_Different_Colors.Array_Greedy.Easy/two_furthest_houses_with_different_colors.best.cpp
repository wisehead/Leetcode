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
        int n=colors.size(),i=0, j=n-1;
        while(colors[j]==colors[0]) j--;
        while(colors[i]==colors[n-1]) i++;
        return max(j,n-1-i);
    }
};

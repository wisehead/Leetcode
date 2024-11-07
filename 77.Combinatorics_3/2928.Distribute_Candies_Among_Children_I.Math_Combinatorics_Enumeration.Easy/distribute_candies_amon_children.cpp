/*******************************************************************************
 *      file name: distribute_candies_amon_children.cpp                                               
 *         author: hui chen. (c) 24                             
 *           mail: alex.chenhui@gmail.com                                        
 *   created time: 24/11/07-11:11                                    
 * modified time: 24/11/07-11:11                                    
 *******************************************************************************/
#include <iostream>
class Solution {
public:
    int distributeCandies(int n, int limit) {
        int cnt = 0;
        for (int i = 0; i <= min(limit,n); i++) {
            for (int j = 0; j <= min(limit,n); j++) {
                int k = n - i - j;
                //cout<<"i:"<<i<<",j:"<<j<<",k:"<<k<<endl;
                if (k <= limit && k >= 0) cnt++;
            }
        }
        return cnt;
    }
};

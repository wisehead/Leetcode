/*******************************************************************************
 *      file name: count_square_sum_triples.cpp                                               
 *         author: hui chen. (c) 24                             
 *           mail: alex.chenhui@gmail.com                                        
 *   created time: 24/09/23- 9:09                                    
 * modified time: 24/09/23- 9:09                                    
 *******************************************************************************/
#include <iostream>
class Solution {
public:
    int countTriples(int n) {
        int c = 0;
        for(int i=1 ; i<=n ; i++){
            for(int j=i+1 ; j<=n ; j++){
                int sq = ( i * i) + ( j * j);
                int r = sqrt(sq);
                if( r*r == sq && r <= n )
                    c += 2;
            }
        }
        return c;
    }
};

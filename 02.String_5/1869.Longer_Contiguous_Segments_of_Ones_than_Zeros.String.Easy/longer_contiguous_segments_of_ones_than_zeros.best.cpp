/*******************************************************************************
 *      file name: longer_contiguous_segments_of_ones_than_zeros.cpp                                               
 *         author: hui chen. (c) 24                             
 *           mail: alex.chenhui@gmail.com                                        
 *   created time: 24/09/17- 9:09                                    
 * modified time: 24/09/17- 9:09                                    
 *******************************************************************************/
#include <iostream>
class Solution {
public:
    bool checkZeroOnes(string s) {
        int ctr=0,ctr1=0,max1=0,max2=0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='1'){
                ctr1++;ctr=0;
                max1=max(max1,ctr1);

            }
            else{
                ctr1=0; ctr++;
                max2=max(max2,ctr);
            }
        }
        return max1>max2;
    }
};

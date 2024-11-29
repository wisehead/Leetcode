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
        s = "x" + s;
        int max_1 = 0;
        int max_0 = 0;
        int cnt_0 = 0;
        int cnt_1 = 0;
        for (int i = 1; i < s.length(); i++) {
            if (s[i] != s[i-1]) {
                if (s[i] == '0') {
                    max_1 = max(max_1, cnt_1);
                    cnt_0 = 1;
                } else {
                    max_0 = max(max_0, cnt_0);
                    cnt_1 = 1;
                }
            } else {
                if (s[i] == '0') cnt_0++;
                else cnt_1++;
            }
        }
        if (s[s.length()-1] == '0') {
            max_0 = max(max_0, cnt_0);
        } else
            max_1 = max(max_1, cnt_1);
        //cout<<"max_1:"<<max_1<<",max_0:"<<max_0<<endl;
        return max_1 > max_0;
    }
};

/*******************************************************************************
 *      file name: minimum_number_of_operations_to_move_all_balls_to_each_box.cpp                                               
 *         author: hui chen. (c) 25                             
 *           mail: alex.chenhui@gmail.com                                        
 *   created time: 25/01/10- 1:01                                    
 * modified time: 25/01/10- 1:01                                    
 *******************************************************************************/
#include <iostream>
class Solution {
public:
    vector<int> minOperations(string boxes) {
        int n = boxes.length();
        vector<int> res(n,0);
        vector<int> sum_left(n+1, 0);
        vector<int> sum_right(n+1, 0);
        int left_ones = 0;
        for (int i = 1; i < n; i++) {
            if (boxes[i-1] == '1')
                left_ones++;
            sum_left[i] = left_ones + sum_left[i-1];
        }
        int right_ones = 0;
        string boxes2 = boxes;
        reverse(boxes2.begin(), boxes2.end());
        for (int i = 1; i < n; i++) {
            if (boxes2[i-1] == '1')
                right_ones++;
            sum_right[i] = right_ones + sum_right[i-1];
        }
        for (int i = 0; i < n; i++) {
            res[i] = sum_left[i] + sum_right[n-i-1];
        }
        return res;
    }
};

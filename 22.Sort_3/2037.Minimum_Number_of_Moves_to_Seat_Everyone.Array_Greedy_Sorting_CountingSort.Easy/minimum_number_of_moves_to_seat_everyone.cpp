/*******************************************************************************
 *      file name: minimum_number_of_moves_to_seat_everyone.cpp                                               
 *         author: hui chen. (c) 24                             
 *           mail: alex.chenhui@gmail.com                                        
 *   created time: 24/11/18-11:11                                    
 * modified time: 24/11/18-11:11                                    
 *******************************************************************************/
#include <iostream>
class Solution {
public:
    int minMovesToSeat(vector<int>& seats, vector<int>& students) {
        int n = seats.size();
        int cnt = 0;
        sort(seats.begin(), seats.end());
        sort(students.begin(), students.end());
        for (int i = 0; i < n; i++) {
            cnt += abs(seats[i] - students[i]);
        }
        return cnt;
    }
};

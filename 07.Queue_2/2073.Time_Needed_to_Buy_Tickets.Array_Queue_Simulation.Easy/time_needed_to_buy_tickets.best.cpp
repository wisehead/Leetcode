/*******************************************************************************
 *      file name: time_needed_to_buy_tickets.cpp                                               
 *         author: hui chen. (c) 24                             
 *           mail: alex.chenhui@gmail.com                                        
 *   created time: 24/09/26- 9:09                                    
 * modified time: 24/09/26- 9:09                                    
 *******************************************************************************/
#include <iostream>
class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        int count = 0; // Variable to store the time
        int index = 0; // Variable to iterate through the array

        // Run the loop until the value at the k index becomes zero
        while (tickets[k] != 0) {
            if (tickets[index] > 0) {
                count++;
                tickets[index]--;
                index = (index + 1) % tickets.size();
            } else if (tickets[index] == 0) {
                index = (index + 1) % tickets.size();
            }
        }

        return count;
    }
};

/*******************************************************************************
 *      file name: my_calendar_II.segmenttree.cpp                                               
 *         author: hui chen. (c) 24                             
 *           mail: alex.chenhui@gmail.com                                        
 *   created time: 24/12/18-12:12                                    
 * modified time: 24/12/18-12:12                                    
 *******************************************************************************/
#include <iostream>
class MyCalendarTwo {
    vector<pair<int, int>> single; // stores single booked intervals
    vector<pair<int, int>> double_booked; // stores double booked intervals

public:
    MyCalendarTwo() {}

    bool book(int start, int end) {
        // Check if the event would cause a triple booking by overlapping with any double booking
        for (const auto& [s, e] : double_booked) {
            if (max(start, s) < min(end, e)) {
                return false; // Triple booking found
            }
        }

        // Add overlapping parts to double bookings
        for (const auto& [s, e] : single) {
            if (max(start, s) < min(end, e)) {
                double_booked.push_back({max(start, s), min(end, e)});
            }
        }

        // Add the event to single bookings
        single.push_back({start, end});
        return true;
    }
};

/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo* obj = new MyCalendarTwo();
 * bool param_1 = obj->book(startTime,endTime);
 */

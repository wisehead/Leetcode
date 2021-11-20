/*******************************************************************************
 *      file name: number_of_students_doing_homework_at_a_given_time.cpp                                               
 *         author: Hui Chen. (c) 2021                             
 *           mail: alex.chenhui@gmail.com                                        
 *   created time: 2021/11/20-11:00:19                              
 *  modified time: 2021/11/20-11:00:19                              
 *******************************************************************************/
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int busyStudent(vector<int>& startTime, vector<int>& endTime, int queryTime) {
        int N = startTime.size();
        int cnt = 0;
        for (int i = 0; i < N; i++) {
            if (queryTime >= startTime[i] && queryTime <= endTime[i]) cnt++;
        }
        return cnt;
    }
};
int main()
{}

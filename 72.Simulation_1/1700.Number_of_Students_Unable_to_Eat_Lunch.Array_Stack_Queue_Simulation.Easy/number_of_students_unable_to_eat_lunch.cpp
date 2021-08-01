/*******************************************************************************
 *      file name: number_of_students_unable_to_eat_lunch.cpp                                               
 *         author: Hui Chen. (c) 2021                             
 *           mail: alex.chenhui@gmail.com                                        
 *   created time: 2021/08/01-09:14:59                              
 *  modified time: 2021/08/01-09:14:59                              
 *******************************************************************************/
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        int cnt[2] = {};
        for (auto e : students) {
            ++cnt[e];
        }
        for (auto e : sandwiches) {
            if (cnt[e]) --cnt[e];
            else return cnt[1-e];
        }
        return 0;
    }
};
int main()
{}

/*******************************************************************************
 *      file name: maximum_compatibility_score_sum.cpp                                               
 *         author: hui chen. (c) 25                             
 *           mail: alex.chenhui@gmail.com                                        
 *   created time: 25/01/09- 1:01                                    
 * modified time: 25/01/09- 1:01                                    
 *******************************************************************************/
#include <iostream>
class Solution {
public:
    int maxCompatibilitySum(vector<vector<int>>& students, vector<vector<int>>& mentors) {
        int m = students.size();
        vector<bool> seen(m, false);
        int score = bt(students, mentors, seen, 0);
        return score;
    }

    int bt(vector<vector<int>>& students, vector<vector<int>>& mentors, vector<bool>& seen, int x) {
        int max_score = 0;
        int m = students.size();
        if (x >= m) return max_score;
        for (int i = 0; i < m; i++) {
            if (!seen[i]) {
                seen[i] = true;
                int score = 0;
                for (int k = 0; k < students[x].size(); k++) {
                    if (students[x][k] == mentors[i][k]) score++;
                }
                score += bt(students, mentors, seen, x+1);
                max_score = max(max_score, score);
                seen[i] = false;
            }
        }
        return max_score;
    }
};

/*******************************************************************************
 *      file name: check_if_every_row_and_column_contains_all_numbers.cpp                                               
 *         author: hui chen. (c) 24                             
 *           mail: alex.chenhui@gmail.com                                        
 *   created time: 24/12/18-12:12                                    
 * modified time: 24/12/18-12:12                                    
 *******************************************************************************/
#include <iostream>
class Solution {
public:
    bool checkValid(vector<vector<int>>& matrix) {
        int n=matrix.size();
        unordered_set<int> s1, s2;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(s1.find(matrix[i][j])!=s1.end())
                    return false;
                else
                    s1.insert(matrix[i][j]);
                if(s2.find(matrix[j][i])!=s2.end())
                    return false;
                else
                    s2.insert(matrix[j][i]);
            }
            s1.clear();
            s2.clear();
        }
        return true;
    }
};

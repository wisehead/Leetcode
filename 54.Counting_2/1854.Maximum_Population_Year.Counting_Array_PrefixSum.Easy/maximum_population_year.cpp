/*******************************************************************************
 *      file name: maximum_population_year.cpp                                               
 *         author: hui chen. (c) 24                             
 *           mail: alex.chenhui@gmail.com                                        
 *   created time: 24/09/17- 9:09                                    
 * modified time: 24/09/17- 9:09                                    
 *******************************************************************************/
#include <iostream>
class Solution {
public:
    int maximumPopulation(vector<vector<int>>& logs) {
        map<int,int> mm;
        for (auto vec : logs) {
            for (int n = vec[0]; n < vec[1]; n++) {
                mm[n]++;
            }
        }
        int max_ret = 0;
        int max_year = 0;
        for (auto it = mm.begin(); it != mm.end(); it++) {
            //cout<<"year:"<<it->first<<",count:"<<it->second<<endl;
            if (it->second > max_ret) {
                max_ret = it->second;
                max_year = it->first;
            }
        }
        return max_year;
    }

};

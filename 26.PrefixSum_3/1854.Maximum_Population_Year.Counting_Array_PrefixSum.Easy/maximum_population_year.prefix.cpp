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
    int maximumPopulation(vector<vector<int>>& logs){
        vector<int>pref(2054);
        for(auto&x : logs){
            pref[x[0]]++;
            pref[x[1]]--;
        }
         int maxi = 0;
          int year = 0;
        pref[0] = 0;
        for(int i=1; i<pref.size(); i++){
            pref[i]+=pref[i-1];
        }
        for(int i=1950; i<=2050; i++){
            if(pref[i] > maxi){
                maxi = pref[i];
                year = i;
            }
        }
        return year;
    }
};

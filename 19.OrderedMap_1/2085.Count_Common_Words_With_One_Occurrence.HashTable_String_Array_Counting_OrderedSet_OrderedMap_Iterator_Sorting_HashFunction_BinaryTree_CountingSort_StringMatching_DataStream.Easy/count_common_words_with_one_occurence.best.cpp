/*******************************************************************************
 *      file name: count_common_words_with_one_occurence.cpp                                               
 *         author: hui chen. (c) 24                             
 *           mail: alex.chenhui@gmail.com                                        
 *   created time: 24/12/13-12:12                                    
 * modified time: 24/12/13-12:12                                    
 *******************************************************************************/
class Solution {
public:
    int countWords(vector<string>& words1, vector<string>& words2) {
        map<string, int> mp;
        for(auto str:words1){
            if(mp[str]==0) mp[str]=1;
            else if(mp[str]==1) mp[str]=-1; // condition failed
        }
        for(auto str:words2){
            if(mp[str]==1) mp[str]=2;
            else if(mp[str]==2) mp[str]=-1; // more than one occurence, condition failed
        }
        int count=0;
        for(auto x:mp){
            if(x.second==2) count++;
        }
        return count;
    }
};

/*******************************************************************************
 *      file name: camelcase_matching.best.cpp                                               
 *         author: hui chen. (c) 25                             
 *           mail: alex.chenhui@gmail.com                                        
 *   created time: 25/01/20- 1:01                                    
 * modified time: 25/01/20- 1:01                                    
 *******************************************************************************/
#include <iostream>

class Solution {
public:
    vector<bool> camelMatch(vector<string>& queries, string pattern) {
        vector<bool> results;
        for(auto& query : queries){
            int j = 0; // Pointer for pattern
            bool match = true;
            for(int i = 0; i < query.size(); i++){
                if(j < pattern.size() && query[i] == pattern[j]){
                    j++; // Move pattern pointer if there's a match
                }else if(isupper(query[i])) {
// pattern "FB" and the query "ForceFeedBack"
// i =0 ,j=0 ,query[0] = 'F', pattern[0] = 'F' , The characters match, so j is incremented to 1.
// i=1, j =1, query[1] = 'o', The characters do not match, so we incremnet i = i++,
// actual what i am trying to say it if current character is lowercase then i++ , if not it is UppercaseLetter then we check ,
// if B != F so the answer is false
                    // If the current character in query is uppercase and not matched, it's a mismatch
                    match = false;
                    break;
                }
            }
            // Check if all characters in pattern were matched
            if (j != pattern.size()) match = false;// means we couldnt able to iterate whole patter, basically there is mismatch uppercaseLetter so false
            results.push_back(match);
        }
        return results;
    }
};

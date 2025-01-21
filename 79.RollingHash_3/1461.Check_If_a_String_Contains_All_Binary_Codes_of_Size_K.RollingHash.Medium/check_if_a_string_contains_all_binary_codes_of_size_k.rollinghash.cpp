/*******************************************************************************
 *      file name: check_if_a_string_contains_all_binary_codes_of_size_k.cpp                                               
 *         author: hui chen. (c) 25                             
 *           mail: alex.chenhui@gmail.com                                        
 *   created time: 25/01/21- 1:01                                    
 * modified time: 25/01/21- 1:01                                    
 *******************************************************************************/
#include <iostream>

class Solution {
public:

    unordered_set<long long> rabin(string &yes,long long sz){
        long long h_s=0,h_p=0,p=256,p_p=1,i,j,m=1000000007;

        for(i=0;i<sz;i++){
            p_p=(p_p*p)%m;
        }
        unordered_set<long long>st;
        for(i=0;i<yes.size();i++){
            h_p=(h_p*p+(yes[i]+1))%m;
            if(i>=sz)h_p=(m+h_p-((yes[i-sz]+1)*p_p)%m)%m;
            if(i+1>=sz)
            st.insert(h_p);
        }
        return st;
    }
    bool hasAllCodes(string &s, int k) {
        long long h_s=0,h_p=0,p=256,p_p=1,i,j,m=1000000007;
        unordered_set<long long>st=rabin(s,k);
        //if(rabin(s,sz)==false)return false;
        for(i=0;i<(1<<k);i++){
            string ne="";
            for(j=0;j<k;j++){

                if(i&(1<<j)){
                    ne='1'+ne;
                }
                else ne='0'+ne;
            }
            h_s=0;
            for(j=0;j<k;j++){
                h_s=(h_s*p+(ne[j]+1)%m)%m;
            }
            if(st.find(h_s)==st.end())return false;

        }
        return true;
    }
};

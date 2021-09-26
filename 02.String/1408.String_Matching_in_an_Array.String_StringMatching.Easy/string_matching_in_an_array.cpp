/*******************************************************************************
 *      file name: string_matching_in_an_array.cpp                                               
 *         author: Hui Chen. (c) 2021                             
 *           mail: alex.chenhui@gmail.com                                        
 *   created time: 2021/09/26-09:43:59                              
 *  modified time: 2021/09/26-09:43:59                              
 *******************************************************************************/
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    vector<string> stringMatching(vector<string>& words) {
        vector<string> res;
        string big;
        for (auto e : words) {
            big += e + " ";
        }
        //cout<<"big:"<<big<<endl;
        for (auto s : words) {
            //cout<<"s:"<<s<<endl;
            int pos = big.find(s);
            if (pos == string::npos) continue;
            //cout<<"pos:"<<pos<<endl;
            int pos2 = big.rfind(s);
            if (pos2 == string::npos) continue;
            //cout<<"pos2:"<<pos2<<endl;
            if (pos != pos2) {
                res.push_back(s);
            }
        }
        return res;
    }
};
int main()
{}

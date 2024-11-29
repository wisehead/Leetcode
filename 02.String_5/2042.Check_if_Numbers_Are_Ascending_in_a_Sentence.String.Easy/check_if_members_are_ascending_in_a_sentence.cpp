/*******************************************************************************
 *      file name: check_if_members_are_ascending_in_a_sentence.cpp                                               
 *         author: hui chen. (c) 24                             
 *           mail: alex.chenhui@gmail.com                                        
 *   created time: 24/11/24-11:11                                    
 * modified time: 24/11/24-11:11                                    
 *******************************************************************************/
#include <iostream>
class Solution {
public:
    bool areNumbersAscending(string s) {
        vector<string> tokens = split(s);
        vector<int> vec;
        for (auto str : tokens) {
            //cout<<"str:"<<str<<endl;
            int num = std::stoi(str);
            if (!vec.empty() && num <= vec.back()) return false;
            vec.push_back(num);
        }
        return true;
    }
    vector<string> split(string s) {
        vector<string> res;
        stringstream ss(s);
        string token;
        while (ss >> token) {
            if (token[0] >= '0' && token[0] <= '9')
                res.push_back(token);
        }
        return res;
    }
};

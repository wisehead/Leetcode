/*******************************************************************************
 *      file name: generate_a_string_with_characters_that_have_odd_counts.cpp                                               
 *         author: Hui Chen. (c) 2021                             
 *           mail: alex.chenhui@gmail.com                                        
 *   created time: 2021/09/04-10:14:02                              
 *  modified time: 2021/09/04-10:14:02                              
 *******************************************************************************/
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    string generateTheString(int n) {
        if (n % 2 == 1) {
            string str(n, 'a');
            return str;
        }
        string str(n-1, 'a');
        str += "b";
        return str;
    }
};
int main()
{}

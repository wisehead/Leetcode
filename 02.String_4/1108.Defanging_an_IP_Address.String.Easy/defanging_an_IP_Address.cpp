/*******************************************************************************
 *      file name: defanging_an_IP_Address.cpp                                               
 *         author: Hui Chen. (c) 2020                             
 *           mail: chenhui13@baidu.com                                        
 *   created time: 2020/10/12-09:35:52                              
 *  modified time: 2020/10/12-09:35:52                              
 *******************************************************************************/
#include <iostream>
using namespace std;
class Solution {
public:
    string defangIPaddr(string address) {
        int pos = 0;
        while (pos != string::npos) {
            pos = address.find(".", pos);
            if (pos != string::npos) {
                address.replace(pos,1,"[.]");
                pos += 2;
            }
        }
        return address;
    }
};
int main()
{}

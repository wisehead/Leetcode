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
        for (int i = address.size() - 1; i >= 0; i--)
            if (address[i] == '.')
                address = address.substr(0, i) + "[.]" + address.substr(i + 1);
        return address;
    }
};
int main()
{}

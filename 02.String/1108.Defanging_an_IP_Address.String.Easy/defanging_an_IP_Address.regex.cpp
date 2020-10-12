/*******************************************************************************
 *      file name: defanging_an_IP_Address.cpp                                               
 *         author: Hui Chen. (c) 2020                             
 *           mail: chenhui13@baidu.com                                        
 *   created time: 2020/10/12-09:35:52                              
 *  modified time: 2020/10/12-09:35:52                              
 *******************************************************************************/
#include <iostream>
#include <boost/regex.hpp>
using namespace std;
class Solution {
public:
string defangIPaddr(string address) {
  return boost::regex_replace(address, boost::regex("[.]"), "[.]");
}
};
int main()
{}

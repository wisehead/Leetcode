/*******************************************************************************
 *      file name: n_repeated_element_in_size_2n_array.cpp                                               
 *         author: Hui Chen. (c) 2019                             
 *           mail: chenhui13@baidu.com                                        
 *   created time: 2019/02/04-11:39:37                              
 *  modified time: 2019/02/04-11:39:37                              
 *******************************************************************************/
#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;
    int repeatedNTimes2(vector<int>& A) {
        unordered_set<int> seen;
        for (int a: A) {
            if (seen.count(a))
                return a;
            seen.insert(a);
        }
    }
int main()
{}

/*******************************************************************************
 *      file name: occurrences_after_bigram.cpp                                               
 *         author: Hui Chen. (c) 2020                             
 *           mail: chenhui13@baidu.com                                        
 *   created time: 2020/10/08-22:01:05                              
 *  modified time: 2020/10/08-22:01:05                              
 *******************************************************************************/
#include <iostream>
#include <vector>
#include<sstream>
using namespace std;
class Solution {
public:
    vector<string> findOcurrences(string text, string first, string second) {
        //cout<<"text length:"<<text.length()<<endl;
        vector<string> vec;
        vector<string> res;    
        //暂存从word中读取的字符串 
        string str;
        //将字符串读到input中 
        stringstream input(text);
        //依次输出到result中，并存入res中 
        while(input>>str)
            vec.push_back(str);
        int size = vec.size();
        for (int i = 0; i < size; i++)
        {
            if (vec[i].compare(first) == 0)
            {
                if(i+1 < size && vec[i+1].compare(second) == 0){
                    if (i+2 < size) res.push_back(vec[i+2]);
                }
            }
        }
        return res;
    }
};
int main()
{}

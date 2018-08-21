/*******************************************************************************
 *      file name: base_7.cpp                                               
 *         author: Hui Chen. (c) 2018                             
 *           mail: chenhui13@baidu.com                                        
 *   created time: 2018/08/21-16:39:28                              
 *  modified time: 2018/08/21-16:39:28                              
 *******************************************************************************/
#include <iostream>
#include <sstream>
using namespace std;
class Solution {
public:
    string int2str(const int &int_temp)
    {
        stringstream stream;
        stream<<int_temp;
        string string_temp=stream.str();   //此处也可以用 stream>>string_temp
        return string_temp;
    }

    string convertToBase7(int num) {
		string res;
        if (num == 0)
            return string("0");
		int num2 = abs(num);
		while (num2)
		{
			int mod = num2 % 7;
			res = int2str(mod) + res;
			//cout<<"res is:"<<res<<endl;
			num2 = num2/7;
		}
		if (num < 0)
			res = "-" + res;
		return res;
    }
};
int main()
{}

/*******************************************************************************
 *      file name: convert_int_2_hex.cpp                                               
 *         author: Hui Chen. (c) 18                             
 *           mail: chenhui13@baidu.com                                        
 *   created time: 18/03/01- 3:03                                    
 *  modified time: 18/03/01- 3:03                                    
 *******************************************************************************/
#include <iostream>
using namespace std;
class Solution {
public:
	string getDigit(int num) {
		char arr[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'a', 'b', 'c', 'd', 'e', 'f'};
		string ret = "a";
		ret[0] = arr[num];
		return ret;
	}

    string toHex(int num) {
		string ret;
		unsigned int in = num;
		for (int i = 0; i < 8; i++)
		{
			unsigned int mask = 0xf0000000;//0x0f 
			in = num << (i*4);
			in = in & mask;
			in = in >> 28;
			//cout<<"in is:"<<in<<endl;
			if (ret.length() == 0 && in == 0 && i != 7)
				continue;
			ret = ret + getDigit(in);
			cout<<"ret is:"<<ret<<endl;
		}
		return ret;
    }
};
int main()
{
	Solution sol;
	string ret;
	//ret = sol.toHex(26);
	//ret = sol.toHex(-1);
	ret = sol.toHex(0);
}

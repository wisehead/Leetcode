/*******************************************************************************
 *      file name: add_binary.cpp                                               
 *         author: hui chen. (c) 17                             
 *           mail: chenhui13@baidu.com                                        
 *   created time: 17/10/31-10:10                                    
 * modified time: 17/10/31-10:10                                    
 *******************************************************************************/
#include <iostream>
#include <string>
using namespace std;
class Solution {
public:
    string addBinary(string a, string b) {
		int len_a = a.length(); 
		int len_b = b.length(); 
		int len_out = 0;
		int carry_flag = 0;
		string out;
		if (len_a > len_b)
		{
			out = a;
			len_out = len_a;
		}
		else
		{
			out = b;
			len_out = len_b;
		}
		cout<<"out1:"<<out<<endl;
		int i=len_a-1, j = len_b-1, k=len_out-1;
		for (; i>=0 && j >= 0; i--, j--, k--)
		{
			cout<<i<<":"<<a[i]<<"	"<<j<<":"<<b[j]<<endl;
			out[k] = a[i] + b[j] + carry_flag - 48;
			cout<<"out["<<k<<"]"<<out[k]<<endl;
			carry_flag = 0;
			if (out[k] > '1')
			{
				carry_flag = 1;
				out[k] -= 2;
			}
		}
		//if (len_a > len_b)
		{
			while(k >= 0)
			{
				out[k] = out[k] + carry_flag;
				carry_flag = 0;
				if (out[k] > '1')
				{
					carry_flag = 1;
					out[k] -= 2;
				}
				cout<<"out["<<k<<"]"<<out[k]<<endl;
				k--;
			}
		}
		if (carry_flag > 0)
		{
			out = string("1")+out;
		}
			
		cout<<"out:"<<out<<endl;
		return out;
    }
};

int main()
{
	Solution sol;
	//sol.addBinary("11","101");
	sol.addBinary("","101");
}

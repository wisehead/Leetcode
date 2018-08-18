/*******************************************************************************
 *      file name: license_key_formatting.cpp                                               
 *         author: Hui Chen. (c) 2018                             
 *           mail: chenhui13@baidu.com                                        
 *   created time: 2018/08/18-10:14:51                              
 *  modified time: 2018/08/18-10:14:51                              
 *******************************************************************************/
#include <iostream>
using namespace std;
class Solution {
public:
	int toupper(int c)
	{
		if ((c >= 'a') && (c <= 'z'))
			return c + ('A' - 'a');
		return c;
	}

    string licenseKeyFormatting(string S, int K) {
        //cout<<"S is:"<<S<<endl;
		reverse(S.begin(), S.end());
        //cout<<"S is:"<<S<<endl;
		int len = S.length();
        //cout<<"len is:"<<len<<endl;
		string res;
        int i = 0;
		while (i < len)
		{
            //cout<<"i0 is:"<<i<<endl;
			int k = 0;
			while(k < K & i < len)
			{
                //cout<<"i is:"<<i<<endl;
				if (S[i] != '-')
				{
					res += toupper(S[i]);
					//cout<<"res is:"<<res<<endl;
					k++;
					//cout<<"k is:"<<k<<endl;
				}
				i++;
				//cout<<"i is:"<<i<<endl;

			}
			if (k == K && i < len)
				res += "-";
            //cout<<"i2 is:"<<i<<endl;
		}
        
        if (res[res.length() - 1] == '-')
            res = res.substr(0,res.length()-1);
        //cout<<"res is:"<<res<<endl;
		reverse(res.begin(), res.end());
		return res;
    }
};
int main()
{
	Solution sol;
	//string s = "5F3Z-2e-9-w";
	//int k = 4;
	//string s = "2-5g-3-J";
	string s = "2-5g-3-J";
	int k = 2;
	string d;
	d = sol.licenseKeyFormatting(s, k);
	cout<<"S is:"<<s<<"		D is:"<<d<<endl;
}

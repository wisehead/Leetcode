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
		reverse(S.begin(), S.end());
		int len = S.length();
		string D;
		for (int i = 0; i < len; i++)
		{
			int k = 0;
			while(k < K )
			{
				//K.append(S[i]);
				if (S[i] != '-')
				{
					D += toupper(S[i]);
					cout<<"D is:"<<D<<endl;
					k++;
					cout<<"k is:"<<k<<endl;
				}
				i++;
				cout<<"i is:"<<i<<endl;

			}
			if (k == K && i< len)
				D += '-';
		}
		reverse(D.begin(), D.end());
		//transform(D.begin(),D.end(),D.begin(),::toupper);
		return D;
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

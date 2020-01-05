/*******************************************************************************
 *      file name: bulls_and_cows.cpp                                               
 *         author: Hui Chen. (c) 2020                             
 *           mail: chenhui13@baidu.com                                        
 *   created time: 2020/01/05-13:13:59                              
 *  modified time: 2020/01/05-13:13:59                              
 *******************************************************************************/
#include <iostream>
#include <unordered_map>
using namespace std;
class Solution {
public:
    string getHint(string secret, string guess) {
		int bulls = 0, cows = 0;
		string res;
		for (int i = 0; i < secret.size(); i++)
		{
			if (secret[i] == guess[i])
			{
				bulls++;
				secret.erase(secret.begin()+i);
				guess.erase(guess.begin()+i);
				i--;
			}
		}

		cout<<"middle secret:"<<secret<<"	guess:"<<guess<<endl;
		unordered_map<char, int> m1;
		for (auto e : secret)
		{
			if (m1.count(e)) m1[e]++;
			else m1[e] = 1; 
		}

		for (auto e : guess)
		{
			if (m1.count(e) && m1[e] > 0)
			{
				m1[e]--;
				cows++;
			}
		}

		res = to_string(bulls) + "A" + to_string(cows) + "B";
		return res;
    }
};
int main()
{
	Solution sol;
	sol.getHint("1807","7810");
}

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
		unordered_map<char, int> m1;
		for (int i = 0; i < secret.size(); i++)
		{
			auto e = secret[i];
            if (m1.count(e)) m1[e]++;
			else m1[e] = 1; 
            if (guess[i] == e)
            {
                bulls++;
				m1[e]--;
                guess.erase(guess.begin() + i);
                secret.erase(secret.begin() + i);
                i--;
			}
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

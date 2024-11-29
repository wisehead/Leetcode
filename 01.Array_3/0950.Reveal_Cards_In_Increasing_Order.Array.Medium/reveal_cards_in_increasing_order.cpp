/*******************************************************************************
 *      file name: reveal_cards_in_increasing_order.cpp                                               
 *         author: Hui Chen. (c) 2019                             
 *           mail: chenhui13@baidu.com                                        
 *   created time: 2019/07/05-11:17:06                              
 *  modified time: 2019/07/05-11:17:06                              
 *******************************************************************************/
#include <iostream>
#include <vector>
#include <queue>
using namespace std;
class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
		int n = deck.size();
		queue<int> q;
		bool pick = true;
		vector<int> vec;
		vector<int> ret(n,0);
		for (int i = 0; i < n; i++)
			q.push(i);

		while (!q.empty())
		{
			int x = q.front();
			q.pop();
			if (pick)
            {
				vec.push_back(x);
                pick = false;
            }
			else
            {
				q.push(x);
                pick = true;
            }
		}
		sort(deck.begin(), deck.end());
		for (int i = 0; i < n; i++)
		{
			int pos = vec[i];
			int val = deck[i];
			//cout<<"pos:"<<pos<<"	val:"<<val<<endl;
			ret[pos] = val;
		}
		return ret;
    }
};
int main()
{}

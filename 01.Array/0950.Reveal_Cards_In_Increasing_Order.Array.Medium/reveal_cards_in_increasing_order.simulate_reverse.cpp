/*******************************************************************************
 *      file name: reveal_cards_in_increasing_order.cpp                                               
 *         author: Hui Chen. (c) 2019                             
 *           mail: chenhui13@baidu.com                                        
 *   created time: 2019/07/05-11:17:06                              
 *  modified time: 2019/07/05-11:17:06                              
 *******************************************************************************/
#include <iostream>
#include <vector>
#include <deque>
using namespace std;
/*
We simulate the reversed process.
Initial an empty list or deque or queue,
each time rotate the last element to the first,
and append a the next biggest number to the left.

Time complexity:
O(NlogN) to sort,
O(N) to construct using deque or queue.
 */
class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        sort(deck.rbegin(), deck.rend());
        deque<int> d;
        d.push_back(deck[0]);
        for (int i = 1; i < deck.size(); i++) {
            d.push_front(d.back());
            d.pop_back();
            d.push_front(deck[i]);
        }
        vector<int> res(d.begin(), d.end());
        return res;
    }
};
int main()
{}

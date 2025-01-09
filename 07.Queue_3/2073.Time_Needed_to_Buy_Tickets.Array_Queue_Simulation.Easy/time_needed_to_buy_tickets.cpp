/*******************************************************************************
 *      file name: time_needed_to_buy_tickets.cpp                                               
 *         author: hui chen. (c) 24                             
 *           mail: alex.chenhui@gmail.com                                        
 *   created time: 24/09/26- 9:09                                    
 * modified time: 24/09/26- 9:09                                    
 *******************************************************************************/
#include <iostream>
class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        int cnt = 0;
        struct Node {
            int id;
            int ticks;
            Node(int a, int b) {
                id = a;
                ticks = b;
            }
        };

        queue<Node> q;
        for (int i = 0; i < tickets.size(); i++) {
            Node node(i, tickets[i]);
            q.push(node);
        }

        while (!q.empty()) {
            Node node = q.front();
            q.pop();
            cnt++;
            if (--node.ticks > 0) {
                q.push(node);
            } else {
                if (node.id == k) return cnt;
            }
        }
        return cnt;

    }
};

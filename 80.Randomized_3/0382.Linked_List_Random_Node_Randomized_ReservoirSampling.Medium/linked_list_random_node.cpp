/*******************************************************************************
 *      file name: linked_list_random_node.cpp                                               
 *         author: hui chen. (c) 25                             
 *           mail: alex.chenhui@gmail.com                                        
 *   created time: 25/01/22- 1:01                                    
 * modified time: 25/01/22- 1:01                                    
 *******************************************************************************/
#include <iostream>
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* my_head;
    vector<int> vec;
    int mod;
    std::default_random_engine engine;
    std::uniform_int_distribution<int> dist;
public:
    Solution(ListNode* head) {
        std::default_random_engine my_engine(std::chrono::system_clock::now().time_since_epoch().count());
        engine = my_engine;
        std::uniform_int_distribution<int> my_dist(0, INT_MAX);
        dist = my_dist;
        my_head = head;
        ListNode* p = head;
        while (p != NULL) {
            vec.push_back(p->val);
            p = p->next;
        }
        mod = vec.size();
    }

    int getRandom() {
        int i = dist(engine)%mod;
        return vec[i];
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(head);
 * int param_1 = obj->getRandom();
 */

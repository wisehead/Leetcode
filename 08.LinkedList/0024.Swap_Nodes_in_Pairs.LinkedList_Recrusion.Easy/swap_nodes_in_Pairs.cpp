/*******************************************************************************
 *      file name: swap_nodes_in_Pairs.cpp                                               
 *         author: Hui Chen. (c) 2021                             
 *           mail: alex.chenhui@gmail.com                                        
 *   created time: 2021/08/01-18:10:52                              
 *  modified time: 2021/08/01-18:10:52                              
 *******************************************************************************/
#include <iostream>
#include <vector>
using namespace std;
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
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        ListNode* p = head;
        bool init_flag = true;
        //if (p && p->next) head = head->next;
        
        ListNode* pre = head;
        while (p && p->next) {                
            ListNode* next = p->next;
            p->next = next->next;
            next->next = p;
            
            if (init_flag) {
                head = next;
                init_flag = false;
            } else {
                pre->next = next;
            }               
            pre = p;  
            p = p->next;
        }//while
        return head;
    }
};
int main()
{}

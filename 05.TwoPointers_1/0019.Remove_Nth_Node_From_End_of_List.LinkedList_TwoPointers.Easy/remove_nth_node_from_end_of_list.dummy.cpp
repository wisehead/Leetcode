/*******************************************************************************
 *      file name: remove_nth_node_from_end_of_list.cpp                                               
 *         author: Hui Chen. (c) 2020                             
 *           mail: chenhui13@baidu.com                                        
 *   created time: 2020/10/30-09:16:13                              
 *  modified time: 2020/10/30-09:16:13                              
 *******************************************************************************/
#include <iostream>
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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int cnt = 0;
        ListNode* p = head;
        while (p) {
            ++cnt;
            p = p->next;
        }
        //cout<<"cnt:"<<cnt<<endl;
        if (cnt == n) {
            head = head->next;
            return head;
        }
        ListNode* pre = head;
        p = head;
        int i = 0;
        while (i < cnt-n) {
            pre = p;
            p = p->next;
            i++;
        }
        //cout<<"pre val:"<<pre->val<<endl;
        //cout<<"p->val:"<<p->val<<endl;

        if (cnt > 1)
            pre->next = p->next;
        else head = nullptr;
        //delete p;
        //return head;
        return head;
    }
};
int main()
{}

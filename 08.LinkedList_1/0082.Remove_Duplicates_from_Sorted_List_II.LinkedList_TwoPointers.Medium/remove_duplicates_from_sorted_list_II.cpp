/*******************************************************************************
 *      file name: remove_duplicates_from_sorted_list_II.cpp                                               
 *         author: Hui Chen. (c) 2021                             
 *           mail: alex.chenhui@gmail.com                                        
 *   created time: 2021/12/18-11:34:08                              
 *  modified time: 2021/12/18-11:34:08                              
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
    ListNode* deleteDuplicates(ListNode* head) {
        if (!head) return NULL;
        ListNode *dummy = new ListNode(INT_MIN, head);
        ListNode* pcur, *pnext, *ppre;
        pcur = dummy->next;
        ppre= dummy;
        while (pcur && pcur->next) {
            pnext = pcur->next;
            while (pnext && pnext->val == pcur->val) {
                pnext = pnext->next;
                //if (!pnext) break;
            }
            if (pnext == pcur->next) {
                ppre = pcur;
                pcur = pnext;
            } else {
                ppre->next = pnext;
                pcur = pnext;
            }
        }
        return dummy->next;
    }
};
int main()
{}

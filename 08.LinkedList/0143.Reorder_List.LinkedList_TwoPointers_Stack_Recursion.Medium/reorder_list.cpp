/*******************************************************************************
 *      file name: reorder_list.cpp                                               
 *         author: Hui Chen. (c) 2021                             
 *           mail: alex.chenhui@gmail.com                                        
 *   created time: 2021/09/29-19:23:33                              
 *  modified time: 2021/09/29-19:23:33                              
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
    void reorderList(ListNode* head) {
        vector<ListNode*> vec;
        for (ListNode* ptr = head; ptr; ptr = ptr->next) 
            vec.push_back(ptr);
        int N = vec.size();
        ListNode* tail = head;
        for (int i = 0; i <= N/2; i++) {
            if (i != 0) {
                tail->next = vec[i];
                tail = tail->next;
            }
            
            if (N - 1 - i > i) {
                tail->next = vec[N-1-i];
                tail = tail->next;                
            }

        }
        tail->next = NULL;
    }
};
int main()
{}

/*******************************************************************************
 *      file name: reorder_list.cpp                                               
 *         author: Hui Chen. (c) 2021                             
 *           mail: alex.chenhui@gmail.com                                        
 *   created time: 2021/09/29-19:23:33                              
 *  modified time: 2021/09/29-19:23:33                              
 *******************************************************************************/
#include <iostream>
#include <vector>
#include <stack>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
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
    void reorderList(ListNode* head) {
        stack<ListNode*> st;
        for (ListNode* ptr = head; ptr; ptr = ptr->next)
            st.push(ptr);

        ListNode* ptr = head;
        ListNode* tail = ptr;
        ptr = ptr->next;
        int N = st.size();
        while (ptr) {
            if (N % 2 == 0) {
                if (!st.empty() && st.top() == ptr) {
                    tail->next = st.top();
                    tail = tail->next;
                    st.pop();
                    break;
                }
            } else {
                if (st.size() <= N/2+1) break;
            }

            //add the node from stack
            if (!st.empty()) {
                tail->next = st.top();
                tail = tail->next;
                st.pop();
            }
            //add the node from link
            tail->next = ptr;
            tail = tail->next;
            ptr = ptr->next;
        }
        tail->next = NULL;
    }
};
int main()
{}

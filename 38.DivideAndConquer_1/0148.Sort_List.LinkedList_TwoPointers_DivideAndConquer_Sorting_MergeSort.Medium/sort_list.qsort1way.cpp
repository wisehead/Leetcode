/*******************************************************************************
 *      file name: sort_list.cpp                                               
 *         author: Hui Chen. (c) 2021                             
 *           mail: alex.chenhui@gmail.com                                        
 *   created time: 2021/10/07-22:09:52                              
 *  modified time: 2021/10/07-22:09:52                              
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
    ListNode* sortList(ListNode* head) {
        qsort(head, NULL);
        return head;
    }
    void qsort(ListNode* head, ListNode* tail) {
        if (head == tail) return;
        ListNode* mark = head;
        int mid = mark->val;
        for (ListNode* node = head->next; node != tail; node = node->next) {
            if (node->val > mid) continue;
            mark = mark->next;
            /*
            int temp = mark->val;
            mark->val = node->val;
            node->val = temp;*/
            swap(mark->val, node->val);
        }

        //head->val = mark->val;
        //mark->val = mid;
        swap(head->val, mark->val);

        ListNode* piv = mark;
        qsort(head, piv);
        qsort(piv->next, NULL);
        /*
        for (int i = 0; i < len; i++)
            cout<<vec[i]<<" ";
        cout<<endl;
        */
    }
};
int main()
{}

/*******************************************************************************
 *      file name: convert_binary_number_in_a_linked_list_to_integer.cpp                                               
 *         author: Hui Chen. (c) 2020                             
 *           mail: chenhui13@baidu.com                                        
 *   created time: 2020/10/29-16:18:07                              
 *  modified time: 2020/10/29-16:18:07                              
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
class Solution {
public:
    int getDecimalValue(ListNode* head) {
        int sum = 0;
        while (head) {
            sum = sum<<1;
            sum +=  head->val;
            head = head->next;
        }
        return sum;
    }
};
int main()
{}

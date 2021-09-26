/*******************************************************************************
 *      file name: reverse_linked_list.cpp                                               
 *         author: Hui Chen. (c) 17                             
 *           mail: chenhui13@baidu.com                                        
 *   created time: 17/12/24-12:12                                    
 *  modified time: 17/12/24-12:12                                    
 *******************************************************************************/
#include <iostream>
using namespace std;
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
		ListNode* ptr = head;
		ListNode* p_temp = NULL;
		ListNode* p_new_head = NULL;
		while(ptr)
		{
			p_temp = ptr;
			ptr = ptr->next;
			p_temp->next = p_new_head;
			p_new_head = p_temp;
		}
		return p_new_head;
    }
};
int main()
{}

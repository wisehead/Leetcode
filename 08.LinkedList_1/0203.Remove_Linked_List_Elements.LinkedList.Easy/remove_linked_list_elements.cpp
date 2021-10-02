/*******************************************************************************
 *      file name: remove_linked_list_elements.cpp                                               
 *         author: Hui Chen. (c) 17                             
 *           mail: chenhui13@baidu.com                                        
 *   created time: 17/12/17-12:12                                    
 *  modified time: 17/12/17-12:12                                    
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
    ListNode* removeElements(ListNode* head, int val) {
		if (!head)
			return head;
		ListNode* ptr = head;
		ListNode* temp = NULL;
		while(ptr->next)
		{
			if (ptr->next->val == val)
			{
				temp = ptr->next; 
				ptr->next = temp->next;
				free(temp);
			}
			else
			{
				ptr = ptr->next;
			}
		}
		if (head->val == val)
		{
			temp = head;
			head = head->next;
			free(temp);
		}
		return head;
    }
};
int main()
{}

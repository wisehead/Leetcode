/*******************************************************************************
 *      file name: linked_list_cycle.cpp                                               
 *         author: hui chen. (c) 17                             
 *           mail: chenhui13@baidu.com                                        
 *   created time: 17/11/23-11:11                                    
 * modified time: 17/11/23-11:11                                    
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
    bool hasCycle(ListNode *head) {
		ListNode *p1 = head;
		ListNode *p2 = head;
		if(head == NULL)
			return false;
		while(p1 != NULL && p2 != NULL)
		{
			p2 = p2->next;
			if (p2 == NULL)
				break;
			p2 = p2->next;
			p1 = p1->next;
			if (p1 == p2)
				return true;
		}
		return false;

    }
};
int main()
{}

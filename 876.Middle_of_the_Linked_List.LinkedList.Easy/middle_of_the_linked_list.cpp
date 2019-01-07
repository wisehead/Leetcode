/*******************************************************************************
 *      file name: middle_of_the_linked_list.cpp                                               
 *         author: Hui Chen. (c) 2019                             
 *           mail: chenhui13@baidu.com                                        
 *   created time: 2019/01/07-15:56:26                              
 *  modified time: 2019/01/07-15:56:26                              
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
    ListNode* middleNode(ListNode* head) {
		ListNode* p = head;
		int count = 0;
		while (p)
		{
			p = p->next;
			count++;
		}
		count = count/2;
		p = head;
		int i = 0;
		while (p && i < count)
		{
			p = p->next;
			i++;
		}
		return p;
    }
};
int main()
{}

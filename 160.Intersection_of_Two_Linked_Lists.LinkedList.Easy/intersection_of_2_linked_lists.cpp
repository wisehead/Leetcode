/*******************************************************************************
 *      file name: intersection_of_2_linked_lists.cpp                                               
 *         author: hui chen. (c) 17                             
 *           mail: chenhui13@baidu.com                                        
 *   created time: 17/11/25-11:11                                    
 * modified time: 17/11/25-11:11                                    
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
	void print_list(ListNode* p_print)
	{
		ListNode* ptr = p_print;
		while(ptr)
		{
			cout<<ptr->val;
			ptr = ptr->next;
		}
		cout<<endl;
	}

	ListNode* init_chain(int count)
	{
		ListNode* p_head = NULL;
		ListNode* ptr = NULL;
		ListNode* p_tail = NULL;
		for (int i=0; i<count; i++)
		{
			ptr = new ListNode(0);
			if (ptr == NULL)
			{
				cout<<"memory alloc error!"<<endl;
				exit(1);
			}
			if (p_head == NULL || p_tail == NULL)
			{
				p_head = ptr;
				p_tail = ptr;
			}
			else
			{
				p_tail->next = ptr;
				p_tail = ptr;
			}
			//cout<<"ptr "<<input[i].next<<endl;
		}
		return p_head;
	}

	ListNode* init_input(unsigned int num)
	{
		unsigned int temp = 0;
		unsigned int digit = 0;
		ListNode* p_head = NULL;
		ListNode* p_tail = NULL;
		ListNode* ptr = NULL;
		digit = num % 10;
		temp = num / 10;
		int length = 0;
		if (num == 0)
			length = 1;
		else
		{
			while (temp > 0 || digit > 0)
			{
				++length;
				digit = temp % 10;
				temp = temp / 10;
			}
		}
		p_head = init_chain(length);
		ptr = p_head;
		digit = num % 10;
		temp = num / 10;
		if (num == 0)
		{
			ptr->val = 0;
		}
		else
		{
			while (temp > 0 || digit > 0)
			{
				ptr->val = digit;
				ptr = ptr->next;
				digit = temp % 10;
				temp = temp / 10;
			}
		}
		return p_head;
	}
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
		ListNode* pa = headA;
		ListNode* pb = headB;
		int count_a =0;
		int count_b = 0;
		bool has_intersection = false;
		if (pa == NULL || pb == NULL)
			return NULL;
		while(pa)
		{
			pa = pa->next;
			count_a++;
		}
		while(pb)
		{
			pb = pb->next;
			count_b++;
		}
		if (count_b > count_a)
		{
			pa = headB;
			pb = headA;
		}
		else
		{
			pa = headA;
			pb = headB;
		}

		int delta = (count_a > count_b)? (count_a - count_b):(count_b - count_a);
		while (delta > 0)
		{
			pa = pa->next;
			delta--;
		}
		while(pa)
		{
			if (pa==pb)
				return pa;
			pa = pa->next;
			pb = pb->next;
		}
		return NULL;
    }
};
int main()
{
	Solution solution;
	ListNode* input_1 = solution.init_input(13579);
	solution.print_list(input_1);
	ListNode* input_2 = solution.init_input(2);
	solution.print_list(input_2);
	ListNode* ret_node = solution.getIntersectionNode(input_1, input_2);
	solution.print_list(ret_node);
}

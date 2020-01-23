/*******************************************************************************
 *      file name: remove_dup_from_sorted_list.cpp                                               
 *         author: hui chen. (c) 17                             
 *           mail: chenhui13@baidu.com                                        
 *   created time: 17/11/05-11:11                                    
 * modified time: 17/11/05-11:11                                    
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
	void free_list(ListNode** pp_clean)
	{
		ListNode* ptr = NULL;
		while(*pp_clean)
		{
			ptr = (*pp_clean)->next;
			delete (*pp_clean);
			(*pp_clean) = ptr;
		}
	}
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
    ListNode* deleteDuplicates(ListNode* head) {
		if (head == NULL)
			return NULL;
		ListNode *p_pre = head, *p_cur = NULL, *p_temp = NULL;
		if (head->next)
			p_cur = p_pre->next;
		else
			return head;
		while(p_cur)
		{
			if (p_cur->val == p_pre->val)
			{
				p_temp = p_cur;
				p_pre->next = p_cur->next;
				p_cur = p_cur->next; 
				delete p_temp;
				p_temp = NULL;
			}
			else
			{
				p_pre = p_cur;
				p_cur = p_cur->next;
			}
		}
		return head;
    }
};

int main()
{
	Solution sol;
	ListNode* input_1 = sol.init_input(332211);
	ListNode* input_2 = sol.init_input(33);
	ListNode* input_3 = sol.init_input(3);
	ListNode* input_4 = sol.init_input(3);
	ListNode *out = NULL;
	out = sol.deleteDuplicates(input_1);
	sol.print_list(out);
	out = sol.deleteDuplicates(input_2);
	sol.print_list(out);
	out = sol.deleteDuplicates(input_3);
	sol.print_list(out);
	out = sol.deleteDuplicates(input_4);
	sol.print_list(out);
	sol.free_list(&input_1);
	sol.free_list(&input_2);
	sol.free_list(&input_3);
	sol.free_list(&input_4);
}

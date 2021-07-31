/*******************************************************************************
 *      File Name: add_two_numbers.cpp                                               
 *         Author: Hui Chen. (c) 2017                             
 *           Mail: chenhui13@baidu.com                                        
 *   Created Time: 2017/09/13-09:29                                    
 * Modified Time: 2017/09/13-09:29                                    
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
	Solution(): output(NULL) {}
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
	~Solution()
	{
		free_list(&output);
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

	int checkInput(ListNode* input)
	{
		if (input == NULL)
			return 1;
		ListNode* ptr = NULL;
		int i = 0;
		for(ptr = input, i=0 ; ptr != NULL; ptr=ptr->next, i++)
		{
			if (ptr->val < 0 || ptr->val > 9)
			{
				cout<<"the input number is invalid!"<<endl;
				return 1;
			}
		}
		return 0;
	}

    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
		if (l1 == NULL || l2 == NULL)
			return NULL;
		if (checkInput(l1) || checkInput(l2))
		{
			cout<<"the input is invalid!"<<endl;
			return NULL;
		}
		if (output)
			free_list(&output);
		ListNode* ptr1 = l1;
		ListNode* ptr2 = l2;
		ListNode* ptr = NULL;
		ListNode* p_tail = NULL;
		int carry_bit = 0;
		while (ptr1 && ptr2)
		{
			ptr = new ListNode(0);
			ptr->val = ptr1->val + ptr2->val + carry_bit;
			carry_bit = 0;
			if (ptr->val > 9)
			{
				ptr->val = ptr->val - 10;
				carry_bit = 1;
			}
			if (output == NULL)
			{
				output = ptr;
				p_tail = ptr;
			}
			else
			{
				p_tail->next = ptr;
				p_tail = ptr;
			}
			ptr1 = ptr1->next;
			ptr2 = ptr2->next;
		}

		if (ptr2)
			ptr1 = ptr2;

		while (ptr1 || carry_bit)
		{
			ptr = new ListNode(0);
			if (ptr1)
			{
				ptr->val = ptr1->val + carry_bit;
				carry_bit = 0;
				if (ptr->val > 9)
				{
					ptr->val = ptr->val - 10;
					carry_bit = 1;
				}
				ptr1 = ptr1->next;
			}
			else
			{
				ptr->val = carry_bit;
				carry_bit = 0;
			}
			p_tail->next = ptr;
			p_tail = ptr;
		}
		cout<<"input 1: ";
		print_list(l1);
		cout<<"input 2: ";
		print_list(l2);
		cout<<"output: ";
		print_list(output);
		
		return output;
    }
private:
	ListNode* output;
};

int main()
{
	Solution solution;
	ListNode* input_1 = solution.init_input(777);
	ListNode* input_2 = solution.init_input(111);
	ListNode* input_3 = solution.init_input(999);
	ListNode* input_4 = solution.init_input(900);
	ListNode* input_5 = solution.init_input(0);
	ListNode* input_6 = solution.init_input(123456);
	ListNode* input_7 = solution.init_input(81);

	ListNode *out = solution.addTwoNumbers(input_1, input_2);
	out = solution.addTwoNumbers(input_1, input_3);
	out = solution.addTwoNumbers(input_1, input_4);
	out = solution.addTwoNumbers(input_4, input_5);
	out = solution.addTwoNumbers(input_4, input_5);
	out = solution.addTwoNumbers(input_5, input_7);

	solution.free_list(&input_1);
	solution.free_list(&input_2);
	solution.free_list(&input_3);
	solution.free_list(&input_4);
	solution.free_list(&input_5);
	solution.free_list(&input_6);
}


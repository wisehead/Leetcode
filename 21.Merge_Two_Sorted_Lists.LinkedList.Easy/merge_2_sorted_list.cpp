/*******************************************************************************
 *      File Name: merge_2_sorted_list.cpp                                               
 *         Author: Hui Chen. (c) 2017                             
 *           Mail: chenhui13@baidu.com                                        
 *   Created Time: 2017/10/13-19:06                                    
 * Modified Time: 2017/10/13-19:06                                    
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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
		ListNode* p_out = NULL;
		ListNode* p_out_tail = NULL;
		ListNode* p1 = l1;
		ListNode* p2 = l2;
		if (l1 == NULL)
		{
			p_out = l2;
			return p_out;
		}
		if (l2 == NULL)
		{
			p_out = l1;
			return p_out;
		}

		while (p1 && p2)
		{
			if (p1->val < p2->val)  
			{
				if (p_out == NULL)
				{
	 				p_out = p1;
					p_out_tail = p1;
				}
				else
				{
					p_out_tail->next = p1;
					p_out_tail = p_out_tail->next;
				}
				p1 = p1->next;
			}
			else
			{
				if (p_out == NULL)
				{
					p_out = p2;
					p_out_tail = p2;
				}
				else
				{
					p_out_tail->next = p2;
					p_out_tail =  p_out_tail->next;
				}
				p2 = p2->next;
			}
			
		}

		if (p1)
			p_out_tail->next = p1;
		if (p2)
			p_out_tail->next = p2;

		return p_out;
    }
};

class TestSolution {
public:
	TestSolution(): output(NULL) {}
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
	~TestSolution()
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
	TestSolution test_solution;
	/*
	ListNode* input_1 = test_solution.init_input(765);
	ListNode* input_2 = test_solution.init_input(111);
	ListNode* input_3 = test_solution.init_input(999);
	ListNode* input_4 = test_solution.init_input(900);
	ListNode* input_5 = test_solution.init_input(0);
	ListNode* input_6 = test_solution.init_input(654321);
	ListNode* input_7 = test_solution.init_input(81);
	*/

	Solution solution;	
	ListNode* input_1 = test_solution.init_input(765);
	ListNode* input_2 = test_solution.init_input(111);
	test_solution.print_list(input_1);
	test_solution.print_list(input_2);
	ListNode* output_1 = solution.mergeTwoLists(input_1, input_2);
	test_solution.print_list(output_1);

	ListNode* input_3 = test_solution.init_input(765);
	ListNode* input_4 = test_solution.init_input(0);
	test_solution.print_list(input_3);
	test_solution.print_list(input_4);
	ListNode* output_2 = solution.mergeTwoLists(input_3, input_4);
	test_solution.print_list(output_2);

	ListNode* input_5 = test_solution.init_input(765);
	ListNode* input_6 = NULL;
	test_solution.print_list(input_5);
	test_solution.print_list(input_6);
	ListNode* output_3 = solution.mergeTwoLists(input_5, input_6);
	test_solution.print_list(output_3);

}

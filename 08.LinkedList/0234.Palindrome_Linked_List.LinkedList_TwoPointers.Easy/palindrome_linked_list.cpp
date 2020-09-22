/*******************************************************************************
 *      file name: palindrome_linked_list.cpp                                               
 *         author: Hui Chen. (c) 17                             
 *           mail: chenhui13@baidu.com                                        
 *   created time: 17/12/28-12:12                                    
 *  modified time: 17/12/28-12:12                                    
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

    bool isPalindrome(ListNode* head) {
		ListNode* ptr = head;
		ListNode* p_head = NULL;
		ListNode* p_tail = NULL;
		ListNode* temp = NULL;
		ListNode* ptr2 = NULL;
		uint64_t count = 0;
		uint64_t middle = 0;
        bool odd = false;
		if (!head)
			return true;
		while (ptr)
		{
			ptr = ptr->next;
			count++;
		}
        if (count<2)
            return true;
		middle = count / 2;
		if (count % 2 == 1)
        {
			middle++;
            odd = true;
        }
		ptr = head;
		for (int i=0; i<middle; i++)
		{
			ptr = ptr->next;
		}
		//ptr = ptr->next;
		p_head = p_tail = ptr;
		if (ptr)
			ptr = ptr->next;
		while(ptr)
		{
			temp = ptr->next;
			ptr->next = p_head;
			p_head = ptr;
			ptr = temp;
		}
		p_tail->next = NULL;
		ptr = head;
		ptr2 = p_head;
		while(ptr2)
		{
			cout<<"ptr->val is:"<<ptr->val<<endl;
			cout<<"ptr2->val is:"<<ptr2->val<<endl;
			if (ptr->val != ptr2->val)
				return false;
            ptr2= ptr2->next;
            ptr = ptr->next;
		}
		return true;
    }
};
int main()
{
	Solution sol;
	ListNode* input_1 = sol.init_input(143341);
	//ListNode* input_1 = sol.init_input(1221);
	bool ret = false;
	ret = sol.isPalindrome(input_1);
	cout<<"ret is:"<<ret<<endl;
}

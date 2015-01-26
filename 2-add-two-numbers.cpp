#include <iostream>
 
 using namespace std;

 struct ListNode {
 	int val;
 	ListNode *next;
 	ListNode(int x) : val(x), next(NULL) {}
 };

class Solution {
public:
	ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
		ListNode *answer = NULL;
		ListNode *pointer;
		/*0: <10; 1: >=10*/
		int flag = 0;
		// deal with l1 bit and l2 bit
		while (l1 != NULL && l2 != NULL)
		{
			if (l1->val + l2->val + flag < 10)
			{
				if (answer == NULL)
				{
					answer = new ListNode(l1->val + l2->val + flag);
					pointer = answer;
					flag = 0;
				}
				else
				{
					ListNode *buf = new ListNode(l1->val + l2->val + flag);
					pointer->next = buf;
					pointer = buf;
					flag = 0;
				}
			}
			else
			{
				if (answer == NULL)
				{
					answer = new ListNode(l1->val + l2->val + flag - 10);
					pointer = answer;
					flag = 1;
				}
				else
				{
					ListNode *buf = new ListNode(l1->val + l2->val + flag - 10);
					pointer->next = buf;
					pointer = buf;
					flag = 1;
				}
			}
			l1 = l1->next;
			l2 = l2->next;
		}

		// now l1 is NULL or l2 is NULL
		if (l1 != NULL)
		{
			while (l1 != NULL)
			{
				// flag is 0, so the next bits are the rest
				if (flag == 0)
				{
					pointer->next = l1;
					break;
				}
				// deal with the situation that flag is 1
				else
				{
					if (l1->val + flag < 10)
					{
						ListNode *buf = new ListNode(l1->val + flag);
						pointer->next = buf;
						pointer = buf;
						flag = 0;
					}
					else
					{
						ListNode *buf = new ListNode(l1->val + flag - 10);
						pointer->next = buf;
						pointer = buf;
						flag = 1;
					}
				}
				l1 = l1->next;
			}
		}
		else if (l2 != NULL)
		{
			while (l2 != NULL)
			{
				if (flag == 0)
				{
					pointer->next = l2;
					break;
				}
				else
				{
					if (l2->val + flag < 10)
					{
						ListNode *buf = new ListNode(l2->val + flag);
						pointer->next = buf;
						pointer = buf;
						flag = 0;
					}
					else
					{
						ListNode *buf = new ListNode(l2->val + flag - 10);
						pointer->next = buf;
						pointer = buf;
						flag = 1;
					}
				}
				l2 = l2->next;
			}
		}

		// l1 and l2 are all NULL, but if flag is 1, need a new bit
		if (flag == 1)
		{
			pointer->next = new ListNode(1);
		}
		return answer;
	}

	// wrong!! becauce the result overflows
    ListNode *addTwoNumbersErr(ListNode *l1, ListNode *l2) {
        int leftVal = 0, rightVal = 0;

        // calculate the value that l1 represents
        int digit = 1;
        while (l1 != NULL)
        {
        	leftVal = leftVal + l1->val * digit;
        	digit = digit * 10;
        	l1 = l1->next;
        }

        // calculate the value that l2 represents
        digit = 1;
        while (l2 != NULL)
        {
        	rightVal = rightVal + l2->val * digit;
        	digit = digit * 10;
        	l2 = l2->next;
        }

        // calculate the result
        long long result = leftVal + rightVal;

        // calculate the numbers of the digits
        int mod = 1;
        while (result % power(mod) != result)
        {
        	mod++;
        }

        ListNode *answer = NULL;
        ListNode *pointer;

        // construct the answer list
        for (int i = 1; i <= mod; i++)
        {
        	int mypower = power(i);
        	int bit = result % 10;
        	result = result / 10;
        	ListNode *buf = new ListNode(bit);
        	if (answer == NULL)
        	{
        		answer = buf;
        		pointer = answer;
        	}
        	else
        	{
        		pointer->next = buf;
        		pointer = buf;
        	}
        }
        return answer;
    }

    int power(int n)
    {
    	int result = 1;
    	for (int i = 0; i < n; i++)
    		result *= 10;
    	return result;
    }
};

int main()
{
	ListNode *l1 = new ListNode(5);
	ListNode *l2 = new ListNode(5);
	Solution solution;
	ListNode *answer = solution.addTwoNumbers(l1, l2);
	cout << "Answer:\n";
	while (answer != NULL)
	{
		cout << answer->val << endl;
		answer = answer->next;
	}
}
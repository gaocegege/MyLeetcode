class Solution
{
public:
	ListNode *removeNthFromEnd(ListNode *head, int n)
	{
		ListNode *resPointer = head;
		ListNode *tailPointer = head;
		for (int i = 0; i < n; i++)
		{
			tailPointer = tailPointer->next;
		}
		if (tailPointer == NULL)
		{
			head = head->next;
			return head;
		}
		while (tailPointer->next != NULL)
		{
			tailPointer = tailPointer->next;
			resPointer = resPointer->next;
		}
		resPointer->next = resPointer->next->next;
		return head;
	}
};
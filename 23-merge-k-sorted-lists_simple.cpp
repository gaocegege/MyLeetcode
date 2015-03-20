class Solution
{
public:
	ListNode *mergeKLists(vector<ListNode *> &lists)
	{
		ListNode *res;
		int index = findMinElement(lists);
		if (index == -1)
			return NULL; 
		res = new ListNode(lists[index]->val);
		ListNode *workingNode = res;
		removeFirstElement(lists, index);
		index = findMinElement(lists);
		while (index != -1)
		{
			workingNode->next = new ListNode(lists[index]->val);
			workingNode = workingNode->next;
			removeFirstElement(lists, index);
			index = findMinElement(lists);
		}
		return res;
	}

private:
	// O(1)
	void removeFirstElement(vector<ListNode *> &lists, int index)
	{
		if (lists[index]->next != NULL)
		{
			lists[index] = lists[index]->next;
		}
		else
		{
			lists.erase(lists.begin() + index);
		}
	}
	// O(k)
	int findMinElement(vector<ListNode *> &lists)
	{
		int sz = lists.size();
		if (sz == 0)
			return -1;
		int index = 0;
		int min = numeric_limits<int>::max();
		for (int i = 0; i < sz; i++)
		{
			if (lists[i] != NULL && lists[i]->val < min)
			{
				min = lists[i]->val;
				index = i;
			}
		}
		if (min == numeric_limits<int>::max())
			return -1;
		return index;
	}
};
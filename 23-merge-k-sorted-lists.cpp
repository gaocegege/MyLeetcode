#include <iostream>
#include <vector>

using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
 };

struct Element
{
	int val;
	int index;
	Element(int val, int index):val(val), index(index) {}
};

class Heap
{
public:
	void buildHeap(vector<ListNode *> &lists)
	{
		int sz = lists.size();
		// useless
		heap.push_back(Element(-1, -1));

		for (int i = 0; i < sz; i++)
			if (lists[i] != NULL)
				heap.push_back(Element(lists[i]->val, i));
		for (int i = (sz - 1) / 2; i >= 1; i--)
		{
			keepProperty(i);
		}
		return;
	}

	void insertNewElement(int val, int index)
	{
		Element newEle(val, index);
		heap.push_back(newEle);
		int indexNew = heap.size() - 1;
		while (indexNew > 1)
		{
			int indexParent = indexNew >> 1;
			if (heap[indexParent].val < heap[indexNew].val)
				break;
			swap(indexParent, indexNew);
			indexNew = indexParent;
		}
	}

	int popMinElement()
	{
		// nothing to pop
		if (heap.size() == 1)
			return -1;
		// only one
		else if (heap.size() == 2)
		{
			Element res = heap[1];
			heap.pop_back();
			return res.index;
		}
		else
		{
			Element res = heap[1];
			heap[1] = heap[heap.size() - 1];
			heap.pop_back();
			keepProperty(1);
			return res.index;
		}
	}

private:
	vector<Element> heap;
	void keepProperty(int index)
	{
		if (index > (heap.size() - 1) / 2)
			return;

		if (heap[index].val < heap[index << 1].val && heap[index].val < heap[(index << 1) + 1].val)
		{
			return;
		}
		else if (heap[index << 1].val < heap[index].val && heap[index << 1].val < heap[(index << 1) + 1].val)
		{
			swap(index, index << 1);
			keepProperty(index << 1);
		}
		else
		{
			swap(index, (index << 1) + 1);
			keepProperty((index << 1) + 1);
		}
	}

	void swap(int i, int j)
	{
		Element buf = heap[i];
		heap[i] = heap[j];
		heap[j] = buf;
		return;
	}
};

class Solution
{
public:
	ListNode *mergeKLists(vector<ListNode *> &lists)
	{
		ListNode *res;
		heap.buildHeap(lists);
		int index = findMinElement(lists);
		if (index == -1)
			return NULL; 
		res = new ListNode(lists[index]->val);
		ListNode *workingNode = res;
		index = findMinElement(lists);
		while (index != -1)
		{
			workingNode->next = new ListNode(lists[index]->val);
			workingNode = workingNode->next;
			index = findMinElement(lists);
		}
		return res;
	}

private:
	Heap heap;

	void removeFirstElement(vector<ListNode *> &lists, int index)
	{
		if (lists[index]->next != NULL)
		{
			lists[index] = lists[index]->next;
		}
		else
		{
			lists[index] = new ListNode(numeric_limits<int>::max());
		}
	}

	int findMinElement(vector<ListNode *> &lists)
	{
		int index = heap.popMinElement();;
		if (index == -1)
			return -1;
		// cout << lists[index]->val << endl;
		removeFirstElement(lists, index);
		if (lists[index]->val != numeric_limits<int>::max())
			heap.insertNewElement(lists[index]->val, index);
		return index;
	}
};

int main()
{
	Solution s;
	vector<ListNode *> v;
	v.push_back(new ListNode(-10));
	v.push_back(NULL);
	v.push_back(new ListNode(-10));
	v.push_back(new ListNode(-10));
	v.push_back(new ListNode(4));
	v.push_back(new ListNode(-3));
	v.push_back(new ListNode(-8));

	v[0]->next = new ListNode(-6);
	v[2]->next = new ListNode(-7);
	v[3]->next = new ListNode(-9);
	v[5]->next = new ListNode(1);
	v[6]->next = new ListNode(-3);

	v[0]->next->next = new ListNode(-1);
	v[2]->next->next = new ListNode(-4);
	v[3]->next->next = new ListNode(4);
	v[6]->next->next = new ListNode(1);

	v[2]->next->next->next = new ListNode(-2);
	v[6]->next->next->next = new ListNode(3);

	v[2]->next->next->next->next = new ListNode(-2);
	v[2]->next->next->next->next->next = new ListNode(-1);
	ListNode *res = s.mergeKLists(v);
}
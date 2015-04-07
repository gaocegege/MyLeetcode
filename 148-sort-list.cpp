/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *sortList(ListNode *head) {
        this->head = head;
        int sz = size();
        quickSort(0, sz - 1);
        return this->head;
    }
    
private:
    ListNode *head;
    int size()
    {
        ListNode *workNode = head;
        int sz = 0;
        while (workNode != nullptr)
        {
            sz++;
            workNode = workNode->next;
        }
        return sz;
    }
    
    ListNode *get(int ith)
    {
        ListNode *workNode = head;
        for (int i = 0; i < ith; i++)
        {
            workNode = workNode->next;
        }
        return workNode;
    }
    
    int partition(int begin, int end)
    {
        ListNode *ithElement = get(begin);
        int jizhun = ithElement->val;
        ListNode *workNode = ithElement->next;
        ListNode *lastExchange = nullptr;
        int res = begin;
        for (int i = begin + 1; i <= end; i++)
        {
            if (workNode != nullptr && workNode->val < jizhun)
            {
                lastExchange = workNode;
                int buf = ithElement->val;
                ithElement->val = workNode->val;
                workNode->val = buf;
                ithElement = ithElement->next;
                workNode = workNode->next;
                res++;
            }
            else if (workNode != nullptr && workNode->val >= jizhun)
            {
                workNode = workNode->next;
            }
        }
        if (lastExchange != nullptr)
        {
            int buf = lastExchange->val;
            lastExchange->val = ithElement->val;
            ithElement->val = buf;
        }
        return res;
    }
    
    void quickSort(int begin, int end)
    {
        if (begin >= end)
            return;
        
        int median = partition(begin, end);
        quickSort(begin, median - 1);
        quickSort(median + 1, end);
    }
};
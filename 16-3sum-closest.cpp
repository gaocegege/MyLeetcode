#include <iostream>

using namespace std;

class Solution()
{
	int threeSumClosest(vector<int> &num, int target)
	{
		int sz = num.size();
		int front = 0;
		int rear = sz - 1;
		sort(num.begin(), num.end());
		int resSum = num[0] + num[1] + num[2];
		int res = abs(resSum - target);
		for (int i = 0; i < sz; i++)
		{
			front = i + 1;
			rear = sz - 1;
			if (res == 0)
				return target;
			while (front < rear)
			{
				int sum = num[i] + num[front] + num[rear];
				if (abs(sum - target) < res)
				{
					res = abs(sum - target);
					resSum = sum;
				}
				if (sum < target)
					front++;
				else if (sum > target)
					rear--;
				else
					break;
			}
		}
		return resSum;
	}
}
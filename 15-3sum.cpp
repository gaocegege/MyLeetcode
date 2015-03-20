#include <iostream>

using namespace std;

class Solution
{
public:
	vector<vector<int> > threeSum(vector<int> &num) {
		int pointerA = 0, pointerB = num.size() - 1;
		int sz = num.size();
		bool flag = false;
		vector<vector<int> > result;
		sort(num.begin(),num.end());
		for (int i = 0; i < sz; i++)
		{
			if (num[i] > 0)
				break;
			pointerA = i + 1;
			pointerB = sz - 1;
			while (pointerA < pointerB)
			{
				if (pointerA == i)
				{
					pointerA++;
					continue;
				}
				if (pointerB == i)
				{
					pointerB--;
					continue;
				}
				if (num[i] + num[pointerA] + num[pointerB] < 0)
				{
					pointerA++;
				}
				else if (num[i] + num[pointerA] + num[pointerB] > 0)
				{
					pointerB--;
				}
				else
				{
					vector<int> buf;
					buf.push_back(num[i]);
					buf.push_back(num[pointerA]);
					buf.push_back(num[pointerB]);
					result.push_back(buf);
					pointerA++;
					pointerB--;

					while (num[pointerA] == buf[1] && pointerA < pointerB)
						pointerA++;
					while (num[pointerB] == buf[2] && pointerA < pointerB)
						pointerB--;
				}
			}
			while (i + 1 < num.size() && num[i + 1] == num[i]) 
            	i++;
		}
		return result;
	}
};
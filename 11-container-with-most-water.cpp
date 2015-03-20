#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxArea(vector<int> &height) 
    {
    	int start = 0;
    	int end = height.size() - 1;
    	int maxArea = (end - start) * (min(height[start], height[end]));
    	while (start + 1 < end)
    	{
    		if (height[start] > height[end])
    		{
    			end--;
    			if (height[end] > height[end + 1])
    				maxArea = max(maxArea, (end - start) * min(height[start], height[end]));
    		}
    		else
    		{
    			start++;
    			if (height[start] > height[start - 1])
    				maxArea = max(maxArea, (end - start) * min(height[start], height[end]));
    		}
    	}
    	return maxArea;
    }

    int min(int a, int b)
    {
    	if (a > b)
    		return b;
    	else
    		return a;
    }

    int max(int a, int b)
    {
    	if (a > b)
    		return a;
    	else
    		return b;
    }
};

int main()
{
	vector<int> height;
	height.push_back(10);
	height.push_back(5);
	height.push_back(10);
	Solution s;
	cout << s.maxArea(height) << "\n";
}
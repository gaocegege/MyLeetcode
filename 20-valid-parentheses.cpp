#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution
{
public:
	bool isValid(string s)
	{
		vector<char> stack;
		int pos = -1;
		int sz = s.size();
		for (int i = 0; i < sz; i++)
		{
			if (pos == -1)
			{
				bool f = pushChar(stack, s[i]);
				if (f == false)
					return false;
				pos++;
			}
			else if (pos != -1 && stack[pos] != s[i])
			{
				bool f = pushChar(stack, s[i]);
				if (f == false)
					return false;
				pos++;
			}
			else
			{
				stack.pop_back();
				pos--;
			}
		}
		if (pos == -1)
			return true;
		else
			return false;
	}

	bool pushChar(vector<char> &stack, char c)
	{
		if (c == '(')
			stack.push_back(')');
		else if (c == '[')
			stack.push_back(']');
		else if (c == '{')
			stack.push_back('}');
		else
			return false;
		return true;
	}
};

int main()
{
	string s = "()";
	Solution so;
	cout << so.isValid(s) << "\n";
}
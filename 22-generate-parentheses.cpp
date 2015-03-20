#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution 
{
private:
	vector<string> res;
	int n; 
	void generateStr(int left, int right, string s, int rest)
	{
    	if (left == n && right == n)
    	{
	        res.push_back(s);
	        return; 
	    }
	    if (left != n) 
	        generateStr(left + 1, right, s + "(", rest + 1);
	    if (right != n && rest - 1 >= 0)
	        generateStr(left, right + 1, s + ")", rest - 1);
	    return;
	}

public:
	vector<string> generateParenthesis(int n) 
	{
	    this->n = n;
	    dfs(1, 0, "(", 1);
	    return res;
	}
};
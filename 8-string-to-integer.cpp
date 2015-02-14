#include <iostream>

using namespace std;

class Solution {
public:
    int atoi(string str) {
        bool flag = false;
        bool negative = false;
        bool fxxkTheSpace = false;
        int pos = 0;
        int result = 0;
        while (pos < str.size())
        {
        	if (str[pos] == '-' && flag == false)
        	{
        		flag = true;
        		fxxkTheSpace = true;
        		negative = true;
        	}
        	else if (str[pos] == '+' && flag == false)
        	{
        		flag = true;
        		fxxkTheSpace = true;
        	}
        	else if (str[pos] >= '0' && str[pos] <= '9')
        	{
        		fxxkTheSpace = true;
        		if (negative == true)
        		{
        			if (result > numeric_limits<int>::max() / 10 || (result == numeric_limits<int>::max() / 10 && (str[pos] - '0') > numeric_limits<int>::max() % 10 + 1))
		    		{
		    			return numeric_limits<int>::min();
		    		}
		    		result = result * 10 + (str[pos] - '0');
        		}
        		else
        		{
        			if (result > numeric_limits<int>::max() / 10 || (result == numeric_limits<int>::max() / 10 && (str[pos] - '0') > numeric_limits<int>::max() % 10))
		    		{
		    			return numeric_limits<int>::max();
		    		}
		    		result = result * 10 + (str[pos] - '0');
        		}
        	}
        	else if (str[pos] == '\t' || str[pos] == '\n' || str[pos] == '\r' || str[pos] == ' ')
        	{
        		if (fxxkTheSpace == false)
        		{
        			pos++;
        			continue;
        		}
        		else
        		{
        			break;
        		}
        	}
        	else
        		break;
        	pos++;
        }
        if (negative == true)
        	result = -result;
        return result;
    }
};

int main()
{
	string s = "      -11919730356x";
	Solution so;
	cout << so.atoi(s) << endl;
}
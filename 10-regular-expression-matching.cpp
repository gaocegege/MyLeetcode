#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    bool isMatch(const char *s, const char *p) {
        string source = s;
        string pattern = p;
        return match(source, pattern, 0, 0);
    }

    bool match(string s, string p, int posS, int posP)
    {
    	if (posP == p.size())
            return posS == s.size();

        if (posP + 1 == p.size() && p[posP + 1] != '*')
        {
            if (p[posP] == '.' || p[posP] == s[posS])
            {
                posS++;
                posP++;
                return match(s, p, posS, posP);
            }
            else
                return false;
        }
    	else if (p[posP + 1] != '*')
    	{
    		if (p[posP] == '.' || p[posP] == s[posS])
    		{
    			posS++;
    			posP++;
    			return match(s, p, posS, posP);
    		}
            else
                return false;
    	}
    	else
    	{
            while ((p[posP] == s[posS]) || (p[posP] == '.' && posS < s.size())) 
            {
                if (match(s, p, posS, posP + 2)) 
                    return true;
                posS++;
            }
            return match(s, p, posS, posP + 2);
    	}
    }
};

int main()
{
	Solution s;
	cout << s.isMatch("a", "ab*") << endl;
}
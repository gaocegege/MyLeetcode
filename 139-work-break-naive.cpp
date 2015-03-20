#include <iostream>
#include <unordered_set>

using namespace std;

class Solution {
public:
    bool wordBreak(string s, unordered_set<string> &dict) {
        return helper(s, dict, 0);
    }
    
private:
    bool helper(const string &s, unordered_set<string> &dict, int pos)
    {
        if (pos > s.size())
            return true;
        for (int i = pos; i < s.size(); i++)
        {
            string buf = s.substr(pos, i - pos + 1);
            if (dict.find(buf) != dict.end())
            {
                dict.erase(buf);
                if (helper(s, dict, i + 1) == true)
                    return true;
                else
                {
                    dict.insert(buf);
                }
            }
        }
        return false;
    }
};

int main()
{
	unordered_set<string> dict;
	dict.insert("a");
	dict.insert("b");
	Solution s;
	cout << s.wordBreak("bb", dict) << endl;
}
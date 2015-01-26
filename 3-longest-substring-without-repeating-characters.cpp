#include <iostream>
#include <map>
#include <string>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int i = 0;
        int j = 0;
        int length = s.size();
        int buf = 0;
        int result;
        map<char, bool> hashTable;
        while (i < length && j < length)
        {
        	if (hashTable.find(s[j]) != hashTable.end())
            {
                // cout << "Erase: " << i << endl;
                hashTable.erase(hashTable.find(s[i]));
                i++;
                buf--;
                continue;
            }
            else
            {
                while (hashTable.find(s[j]) == hashTable.end() && j < length)
                {
                    // cout << "Insert: " << j << endl;
                    hashTable.insert(pair<char, bool>(s[j], true));
                    buf++;
                    if (buf > result)
                        result = buf;
                    j++;
                }
            }
        }
        return result;
    }
};

int main()
{
    Solution s;
    cout << s.lengthOfLongestSubstring("b") << endl;

}
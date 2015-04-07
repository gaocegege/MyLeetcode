#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution
{
public:
  vector<string> findRepeatedDnaSequences(string s) {
    unordered_map<int, int> map;
    hash<string> hash_fn;
    vector<string> v;

    for(int i = 0 ; i + 9 < s.size(); i++)
    {
       string t = s.substr(i, 10);
       cout << t << endl;
       int h = hash_fn(t);

       if(map.find(h) == map.end())
       {
          map[h] = 1;
       }
       else
       {
           if (map[h] == 1)
           {
               v.insert (v.end(), t);
           }

            map[h]++;
       }
    }

    return v;
  }
};

int main(int argc, char const *argv[])
{
  Solution s;
  vector<string> v = s.findRepeatedDnaSequences("AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT");
  for (auto ele : v)
    cout << ele << endl;
  return 0;
}
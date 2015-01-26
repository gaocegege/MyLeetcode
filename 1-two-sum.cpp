#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

class Solution {
public:
    vector<int> twoSumHash(vector<int> &numbers, int target) {
        vector<int> answer;
        // map<int, int> hashTable;
        map<int, int> hashTable;
        int length = numbers.size();
        for (int i = length - 1; i >= 0; i--)
        {
            hashTable.insert(make_pair(numbers[i], i));
        }
        for (int i = 0; i < length; i++)
        {
            map<int, int>::iterator buf = hashTable.find(target - numbers[i]);
            if (buf != hashTable.end() && i != buf->second)
            {
                answer.push_back(i + 1);
                answer.push_back(buf->second + 1);
            }

        }
        // cout << answer[0] << "\t" << answer[1] << endl;
        return answer;
    }

    vector<int> twoSum(vector<int> &numbers, int target) {
        // save the data
        vector<int> buf = numbers;

        // the pointer define
        int i = 0;
        int j = numbers.size() - 1;
        sort(numbers.begin(),numbers.end());

        int sumTmp = numbers[i] + numbers[j];
        while (sumTmp != target)
        {
            if (sumTmp > target)
            {
                j--;
            }
            else if (sumTmp < target)
            {
                i++;
            }
            else
            {
                break;
            }
            sumTmp = numbers[i] + numbers[j];
        }
        vector<int> answer;
        int length = buf.size();
        for (int k = 0; k < length; k++)
        {
            if (buf[k] == numbers[i] || buf[k] == numbers[j])
            {
                answer.push_back(k + 1);
            }
        }
        cout << answer[0] << "\t" << answer[1] << endl;
        return answer;
    }
};

int main()
{
    vector<int> numbers;
    numbers.push_back(0);
    numbers.push_back(4);
    numbers.push_back(3);
    numbers.push_back(0);
    Solution solution;
    vector<int> answer = solution.twoSumHash(numbers, 0);
    cout << answer[0] << "\t" << answer[1] << endl;
}
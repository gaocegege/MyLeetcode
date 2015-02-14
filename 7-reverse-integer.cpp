#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution
{
public:
	int reverse(int x) 
    {
        int negative = (x < 0) ? -1 : 1;
        int result = 0;
        int temp = x * negative;
        while(temp > 0)
        {
            if (result > numeric_limits<int>::max() /10 )
                return 0;
            result = result * 10 + temp % 10;     
            temp /= 10;
        }

        return  negative * result;
    }
};

int main(int argc, char const *argv[])
{
	int x = 1009;
	Solution s;
	cout << s.reverse(x);
	return 0;
}
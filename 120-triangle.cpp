class Solution {
public:
    int minimumTotal(vector<vector<int> > &triangle) {
        vector<vector<int> > dp = triangle;
        for (int i = 1; i < triangle.size(); i++)
        {
        	dp[i][0] = dp[i - 1][0] + triangle[i][0];
        	for (int j = 1; j < i; j++)
        	{
        		dp[i][j] = min(dp[i - 1][j - 1], dp[i - 1][j]) + triangle[i][j];
        	}
        	dp[i][i] = dp[i - 1][i - 1] + triangle[i][i];
        }
        int res = numeric_limits<int>::max();
        int sz = triangle.size() - 1;
        for (int i = 0; i <= sz; i++)
        {
        	if (dp[sz][i] < res)
        		res = dp[sz][i];
        }
        return res;
    }

private:
	int min(int a, int b)
	{
		return (a > b? b: a);
	}
};
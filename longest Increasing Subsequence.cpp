int n = nums.size();
std::vector<int> dp(n, 1);

int lis = 1;
for (int i = n - 1; i >= 0; i--)
{
    for (int j = i + 1; j < n; j++)
    {
        if (nums[i] < nums[j])
        {
            dp[i] = max(dp[i], dp[j] + 1);
            lis = max(lis, dp[i]);
        }
    }
}

return lis;
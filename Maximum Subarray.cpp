class Solution
{
public:
    int maxSubArray(vector<int> &nums)
    {
        int len = nums.size();
        vector<int> dp(len);
        dp[0] = nums[0];
        int mxSum = nums[0];
        for (int i = 1; i < len; i++)
        {
            dp[i] = max(nums[i], dp[i - 1] + nums[i]);
            mxSum = max(mxSum, dp[i]);
        }
        return mxSum;
    }
};
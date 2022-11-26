class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int n = prices.size();
        int dp1[n], dp2[n];
        dp1[0] = prices[0];
        dp2[0] = prices[0];

        int best = 0;

        for (int i = 1; i < n; i++)
        {
            dp2[i] = max(dp2[i - 1], prices[i]);

            best = max(best, dp2[i] - dp1[i - 1]);

            if (prices[i] < dp1[i - 1])
            {
                dp1[i] = prices[i];
                dp2[i] = dp1[i];
            }
            else
                dp1[i] = dp1[i - 1];

            best = max(best, dp2[i] - dp1[i - 1]);
        }

        return best;
    }
};
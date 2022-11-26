class Solution
{
public:
    vector<vector<int>> dp;

    int findLCS(int p1, int p2, string &s1, string &s2)
    {
        if (p1 >= s1.size() || p2 >= s2.size())
            return 0;
        if (dp[p1][p2] != -1)
            return dp[p1][p2]; // already calculated
        int res = 0;
        if (s1[p1] == s2[p2])
            res = 1 + findLCS(p1 + 1, p2 + 1, s1, s2); // match found
        else
            res = max(findLCS(p1 + 1, p2, s1, s2), findLCS(p1, p2 + 1, s1, s2));
        dp[p1][p2] = res;
        return res;
    }

    int longestCommonSubsequence(string text1, string text2)
    {
        int len1 = text1.size(), len2 = text2.size();
        dp.resize(len1, vector<int>(len2, -1));

        return findLCS(0, 0, text1, text2);
    }
};
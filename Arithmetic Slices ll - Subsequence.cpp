#define ll long long int
class Solution {
public:
	int numberOfArithmeticSlices(vector<int>& nums) {
		int n = nums.size();
		ll total = 0;
		ll limit = 1e12;
		vector<map<ll, int>> dp(n);
		if (n >= 2) {
			for (int i = 1; i < n; i++) {
				for (int j = 0; j < i; j++) {
					ll diff = (ll) nums[i] - nums[j];
					total += dp[j][diff];
					dp[i][diff] += dp[j][diff] + 1;
				}
			}
		}
		return total;
	}
};
//1235. Maximum Profit in Job Scheduling

#define ff first
#define ss second
#define pb push_back
#define mp make_pair
int n = 0;
class Solution {

	int fun(int pos, vector<int>& startTime, vector<pair<int, pair<int, int>>>&v, vector<int> &dp ) {
		if (pos >= n) return 0;
		if (dp[pos] != -1) return dp[pos];
		int eTime = v[pos].ss.ff;
		int l = lower_bound(startTime.begin(), startTime.end(), eTime) - startTime.begin();

//if we use this interval then profit will add and statTime pos will l
		int takeValue = v[pos].ss.ss + fun(l, startTime, v, dp);
		int notTake = fun(pos + 1, startTime, v, dp);
		dp[pos] = max(takeValue, notTake);
		return dp[pos];
	}

public:
	int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
		n = startTime.size();
		vector<int>dp(n, -1);
		vector<pair<int, pair<int, int>>>v;
		for (int i = 0; i < n; i++) {
			v.pb(mp(startTime[i], mp(endTime[i], profit[i])));
		}
		sort(v.begin(), v.end());
		sort(startTime.begin(), startTime.end());
		int ans = fun(0, startTime, v, dp);

		return ans;




	}
};
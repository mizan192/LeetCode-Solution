class Solution {
public:
	int missingNumber(vector<int>& nums) {
		sort(nums.begin(), nums.end());
		int value = 0;
		for (auto x : nums) {
			if (x != value) return value;
			value++;
		}
		return value;
	}
};
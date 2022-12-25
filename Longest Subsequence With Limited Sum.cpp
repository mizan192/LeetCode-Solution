class Solution {
public:
    vector<int> answerQueries(vector<int>& nums, vector<int>& queries) {
        sort(nums.begin(),nums.end());
        int allSum=0;
        vector<int>preS;
        for(auto x : nums) {
            allSum+=x;
            preS.push_back(allSum);
        }
        vector<int>ans;
        for(auto x : queries){
            int l= lower_bound(preS.begin(),preS.end(),x)-preS.begin();
            if(l<preS.size() && preS[l]==x) l++;
            ans.push_back(l);
        }

        return ans;
    }
};
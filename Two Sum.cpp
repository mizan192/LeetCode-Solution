class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int,vector<int>>m;
        
        for(int i=0;i<nums.size();i++){
           m[nums[i]].push_back(i);
        }
        vector<int>ans;
      
        for(int i=0;i<nums.size();i++){
            int res=  target-nums[i];
            if(m[res].size()>=1){
              for(auto x : m[res]){         
                 if(x!=i){
                ans.push_back(i);
                ans.push_back(x);
                return ans;
                }
              }

            }
        }

//for(auto x : ans) cout<<x<<" ";

return ans;

    }
};
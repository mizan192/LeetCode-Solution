class Solution {
public:
    bool canJump(vector<int>& nums) {
        int lagbe=1;
        if(nums.size()==1){
             return 1;
        }

        for(int i=nums.size()-2;i>=0;i--){
            if(nums[i]>=lagbe && nums[i]!=0) lagbe=1;
            else lagbe++;
            // cout<<i<<" "<<lagbe<<endl;
        }
    int ans=0;
        if(lagbe<=nums[0] && nums[0]!=0) ans=1;
return ans;
    }
};
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        int major = n/2;
        if(n==1) return nums[0];

        sort(nums.begin(),nums.end());

        int cnt=1,ans=nums[0],pre=nums[0];
        for(int i=1;i<n;i++){
            if(nums[i]==pre) {
            cnt++;
                            if(cnt>major){
                    ans=pre;
                    break;
                }
                }
            else{
                if(cnt>major){
                    ans=pre;
                    break;
                }
                cnt=1;
                pre=nums[i];
            }
        }
        if(cnt>major){
                    ans=pre;
                }
return ans;

    }
};
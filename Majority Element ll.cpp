class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
    sort(nums.begin(),nums.end());
//accroding boyer-moore voting algo 
  vector<int>ans;
  int n =nums.size();
  int range=n/3;

  // cout<<range<<endl;
int last =-1;

  for(int i=0;i<nums.size();i++){
    if(i+range>=n) break;

    if(nums[i]==nums[i+range]) {
      //cout<<i<<" "<<i+range<<endl;
      if(ans.size()>=1){
        int last = ans[ans.size()-1];
        if(last!=nums[i]) ans.push_back(nums[i]);
      }
        else ans.push_back(nums[i]); 
         i =i+range;
      }
     
  }

  return ans;
    }
};
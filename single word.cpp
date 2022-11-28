class Solution {
public:
    int singleNumber(vector<int>& nums) {
        map<int,int>m;
        for(auto x : nums) m[x]++;
        int y;
        for(auto x : m){
            if(x.second==1) {
                y=x.first;
            }
        }
        return y;
    }
};
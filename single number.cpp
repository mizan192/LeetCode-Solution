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


/*
//alternative : 

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        //xor for total arry will single element
        //as res element are double 
        int xr=0;
        for(auto x : nums){
            xr =(xr^x);
        }
        return xr;
    }
};


*/
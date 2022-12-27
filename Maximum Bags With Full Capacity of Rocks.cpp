class Solution {
public:
    int maximumBags(vector<int>& capacity, vector<int>& rocks, int additionalRocks) {

        int maxBags=0;
        vector<int>res;
        for(int i=0;i<capacity.size();i++){
            int extrSpace=capacity[i]-rocks[i];
            if(extrSpace>=1) res.push_back(extrSpace);
            else maxBags++;
        }

        sort(res.begin(),res.end());
        int extrRocks=additionalRocks;
        for(auto x : res){
            if(extrRocks>=x) {
                maxBags++;
                extrRocks-=x;
            }
        }
return maxBags;




    }
};
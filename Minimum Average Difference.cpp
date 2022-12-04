class Solution {
public:

//TC : O(n), MC : O(1)
    int minimumAverageDifference(vector<int>& nums) {
        vector<long long>preSum;
        long long sum=0;
        for(auto x : nums){
            sum+=x;
            preSum.push_back(sum);
        }

//cout<<"total "<<sum<<endl;

        int minAvrgDiffIndex=0;
        long long minAvrgDiff=sum;
        int n = nums.size();
        for(int i=0;i<preSum.size();i++){
            long long leftAvrg=preSum[i]/(i+1);
            long long rigthAvrg = 0;
            
            if(i!=n-1)
             rigthAvrg= (sum-preSum[i])/(n-i-1);
            
            long long curentDiff = abs(rigthAvrg-leftAvrg);
            
           // cout<<i<<" "<<leftAvrg<< " "<<rigthAvrg<<" "<<curentDiff<<endl;

            if(curentDiff<minAvrgDiff) {
                minAvrgDiffIndex=i;
                minAvrgDiff = curentDiff;
            }
        }

    return minAvrgDiffIndex;

    }
};
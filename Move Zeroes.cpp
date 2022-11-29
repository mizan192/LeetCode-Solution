class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        for(int i=0;i<nums.size();i++){
            if(nums[i]==0){
                for(int j=i+1;j<nums.size();j++){
                    if(nums[j]!=0){
                      
                       // cout<<i<<" "<<j<<endl;

                        nums[i]=nums[j];
                        nums[j]=0;
                        break;
                    } 
                }
            }
        }

    }   
};


/*
tle : 59ms, beat : 43.29
mle : 19.4mb, beat : 14.97%

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int pos=0,nonZero=0;
        for(int i=0;i<nums.size();i++){
           if (nums[i]!=0){
                nums[pos]=nums[i];
                pos++;
                nonZero++;
            }
        }
        int zero = nums.size()-nonZero;
        pos=nums.size()-1;
        cout<<zero<<endl;
        while(zero){
            nums[pos]=0;
            zero--;
            pos--;
        }

    }   
};
*/
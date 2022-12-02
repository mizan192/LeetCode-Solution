class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {

if(nums2.size()==0) return;
int pre =nums2[0];
int j=1;
priority_queue<int>q;
for(int i=m;i<nums1.size();i++) nums1[i]=1e9+1;

              for(int i=0;i<nums1.size();i++){
                if(nums1[i]>pre){

               int tmp = nums1[i];
               nums1[i]=pre;
               q.push(-tmp);
               
               tmp = 1e9+1;

               if(q.size()>=1)
                 tmp = -q.top();

            int mn = 1e9+1;
            if(j<nums2.size()) mn=nums2[j];

               pre =min(tmp,mn);

                if(pre== tmp)  q.pop();
                else j++;
         
          }

       }
        






    }
};
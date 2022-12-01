class Solution {
public:
    bool halvesAreAlike(string s) {
        int n = s.size();
        int count=0;
    string need="aeiouAEIOU";
int ar[n+1];
        for(int i=0;i<n;i++){
            char x = s[i];
            for(auto y : need){
                if(y==x) {
                    count++;
                    break;
                }
            }
            ar[i+1]=count;
        }
       int len = n/2;

        //cout<<count<<endl;

        if(count%2==0) {
            if(ar[len]==count/2)  return 1;
            else return 0;
            }
        else return 0;
    }
};
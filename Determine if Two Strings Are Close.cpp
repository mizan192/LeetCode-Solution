#define ff first 
#define ss second
class Solution {
public:

    bool closeStrings(string word1, string word2) {
        if(word1.size()!=word2.size()) return false;
 map<char,int>m1,m2,vis;
 map<int,int>m11,m22;
       
        for(int i=0;i<word2.size();i++){
            m1[word1[i]]++;
            m2[word2[i]]++;
        }
int ok=0;
        for(auto x : m1){

            if(m2[x.ff]!=x.ss) ok=1;
        }
        if(!ok) return true;

        for(auto x : m1){
            m11[x.ss]++;
        }
        for(auto x : m2){
            m22[x.ss]++;
        }

        for(auto x : m22){
            int ace = m11[x.ff];
            if(ace!=x.ss){
                return false;
            }
        }

return true;

    }
};
class Solution {
public:
    string frequencySort(string s) {

        map<char,int>m;
        vector<pair<int,char>>v;
        for(auto x : s){
            m[x]++;
        }
        for(auto x : m){
            v.push_back(make_pair(x.second,x.first));
        }
        sort(v.rbegin(),v.rend());
        string ans="";
        for(auto x : v){
            int j=x.first;
            char c=x.second;
            for(int i=0;i<j;i++) ans+=c;
        }

return ans;


    }
};

/*
class Solution {
public:
    string frequencySort(string s) {

        map<char,int>m;
        priority_queue<pair<int,char>>q;

        for(auto x : s){
            m[x]++;
        }
        for(auto x : m){
            q.push(make_pair(x.second,x.first));
        }

        string ans="";
while(!q.empty()){
    auto it =q.top();
    q.pop();
            int j=it.first;
            char c=it.second;
            for(int i=0;i<j;i++) ans+=c;
        }

return ans;


    }
};
*/
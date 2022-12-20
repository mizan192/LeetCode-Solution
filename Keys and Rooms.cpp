class Solution {
public:
//TC :O(n2)



    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n=rooms.size();
        int keyVis[n];
        bool canVisit=true;
        for(int i=1;i<n;i++) keyVis[i]=0;
        keyVis[0]=1;

        stack<int>key;
        for(auto x : rooms[0]) key.push(x);

        while(!key.empty()){
            int f=key.top();
            key.pop();
            if(!keyVis[f]) {
                keyVis[f]=1;
                for(auto x : rooms[f]) {
                    if(!keyVis[x]) key.push(x);
                }
            }
        }

        for(int i=0;i<n;i++){
            if(keyVis[i]==0){
                canVisit=false;
                break;
            }
        }




        return canVisit;
    }
};
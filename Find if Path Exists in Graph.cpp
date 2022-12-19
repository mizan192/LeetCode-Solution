class Solution {
public:
 static const int MAX = 200003;
    vector<int>gr[MAX+2];
    bool vis[MAX+2];

    void dfs(vector<vector<int>>& edges, int source, int destination){
        vis[source]=1;
        if(source==destination) return;
        for(auto child : gr[source]){
            if(!vis[child]) dfs(edges,child,destination);
        }
    }

    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        for(int i=0;i<=MAX;i++) {
            vis[i]=0;
        }
        for(auto x : edges){
            int u=x[0],v=x[1];
            gr[u].push_back(v);
            gr[v].push_back(u);
        }

        dfs(edges,source,destination);

        if(vis[destination]) return 1;
        else return 0;


    }
};
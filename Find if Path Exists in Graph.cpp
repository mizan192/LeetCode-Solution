//dfs code will use more time and memeory than dsu
class Solution {
public:
 static const int MAX = 200003;
  int pr[MAX+2];
    int find_parent(int u) {
	if (u == pr[u]) return u;
	return pr[u] = find_parent(pr[u]);
    }

void union_set(int u, int v) {
	int pu = find_parent(u);
	int pv = find_parent(v);
	pr[pu] = pv;
}
  
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        for(int i=1;i<=n;i++) {
            pr[i]=i;
        }

        for(auto x : edges){
            int u=x[0],v=x[1];
            union_set(u,v);
        }

        int parentSource=find_parent(source);
        int parentDestination=find_parent(destination);

        if(parentSource==parentDestination) return 1;
        else return 0;
       

    }
};



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
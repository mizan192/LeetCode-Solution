class Solution {
public:
    int allEmpty=0;
    int sx=0,sy=0,ex=0,ey=0;
    int dx[4] = { +1, +0, +0, -1};
    int dy[4] = { +0, -1, +1, +0};

    int ans=0;
    void dfs(int x, int y, int n, int m, int cnt, vector<vector<bool>>& vis, vector<vector<int>>& grid){
        
        cnt++;
        if(grid[x][y]==2) {
            if(cnt==allEmpty){
                ans++;
            }
            return;
        }
        vis[x][y]=1;
        for(int i=0;i<4;i++){
            int xx=x+dx[i];
            int yy =y+dy[i];
            if(xx<n && xx>=0 && yy<m && yy>=0 && vis[xx][yy]==0 ) dfs(xx,yy,n,m,cnt,vis,grid);
        }


        vis[x][y]=0;

    }
    

    int uniquePathsIII(vector<vector<int>>& grid) {
        int n=grid.size();
        int m =grid[0].size();
        int obstacle=0;
        vector<vector<bool>> vis(n,vector<bool> (m,false));

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==-1) {
                    obstacle++;
                    vis[i][j]=1;
                }
                else allEmpty++;
                if(grid[i][j]==1){
                    sx=i,sy=j;
                }
            }
        }

        //allEmpty=(n*m)-obstacle;
       
        dfs(sx,sy,n,m,0,vis,grid);


    return ans;

    }
};

/*
1 starting square
2 ending square
0 empty square
-1 obstacles can't walk
*/
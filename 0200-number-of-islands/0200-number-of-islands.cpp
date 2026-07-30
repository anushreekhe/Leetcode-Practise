class Solution {
public:

    void bfs(int row, int col, vector<vector<int>>& vis, vector<vector<char>>& grid){
        vis[row][col]=1;
        int n=grid.size();
        int m=grid[0].size();
        queue<pair<int,int>> q;
        q.push({row, col});
        while(!q.empty()){
            int r=q.front().first;
            int c=q.front().second;
            q.pop();
            int dr[]={-1,1,0,0};
int dc[]={0,0,-1,1};
for(int k=0;k<4;k++){
    int nr=r+dr[k];
    int nc=c+dc[k];
    if(nr>=0 && nr<n && nc>=0 && nc<m && grid[nr][nc]=='1' && !vis[nr][nc]){
        vis[nr][nc]=1;          // mark karo yahi pe
        q.push({nr,nc});        // queue mein push karo
    }
}
    }}

    int numIslands(vector<vector<char>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int c=0;
        vector<vector<int>> vis(n,vector<int>(m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]=='1' && vis[i][j]==0){
                    bfs(i,j,vis,grid);
                    c++;
                }
            }
        }
        return c;
    }
};
class Solution {
public:

    void dfss(int i, int j, vector<vector<int>>& vis, vector<vector<char>>& board, int dr[], int dc[]){
        vis[i][j]=1;
        int n=board.size();
        int m=board[0].size();
        for(int k=0;k<4;k++){
            int nr=i+dr[k];
            int nc=j+dc[k];
            if(nr>=0 && nr<n && nc>=0 && nc<m && !vis[nr][nc] && board[nr][nc]=='O'){
                dfss(nr,nc,vis,board,dr,dc);
            }
        }
    }


    void solve(vector<vector<char>>& board) {
        int n=board.size();
        int m=board[0].size();;
        int dr[]={1,0,-1,0};
        int dc[]={0,1,0,-1};
        vector<vector<int>> vis(n,vector<int>(m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if((i==0 || i==n-1 || j==0 || j==m-1) && board[i][j]=='O' && vis[i][j]!=1){
                    dfss(i,j,vis,board,dr,dc);
                }
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(vis[i][j]==0 && board[i][j]=='O') board[i][j]='X';
            }
        }
    }
};
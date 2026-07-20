class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int n=grid[0].size();
        int m=grid.size();
        vector<vector<int>> a(m, vector<int>(n));
        k%= (m * n);
        if(k==0) return grid;
        while(k>0){
            for(int i=0;i<m;i++){
                for(int j=0;j<n;j++){
                    a[i][(j+1)%n]=grid[i][j];
                }
            }
            for(int i=0;i<m;i++){
                
                    a[(i+1)%m][0]=grid[i][n-1];
                
            }
            a[0][0]=grid[m-1][n-1];
            grid=a;
            k--;
        }
        return(a);
    }
};
class Solution {
public:
    int maximumSafenessFactor(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>> safe(n, vector<int>(n, -1));
        queue<pair<int,int>> q;

        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                if (grid[i][j]) safe[i][j] = 0, q.push({i, j});

        int dx[] = {0,0,1,-1}, dy[] = {1,-1,0,0};
        while (!q.empty()) {
            auto [x, y] = q.front(); q.pop();
            for (int d = 0; d < 4; d++) {
                int nx = x+dx[d], ny = y+dy[d];
                if (nx>=0 && nx<n && ny>=0 && ny<n && safe[nx][ny]==-1) {
                    safe[nx][ny] = safe[x][y]+1;
                    q.push({nx, ny});
                }
            }
        }

        priority_queue<pair<int,int>> pq;
        pq.push({safe[0][0], 0});
        vector<int> vis(n*n, 0);

        while (!pq.empty()) {
            auto [s, code] = pq.top(); pq.pop();
            int x = code/n, y = code%n;
            if (vis[code]) continue;
            vis[code] = 1;
            if (x==n-1 && y==n-1) return s;
            for (int d = 0; d < 4; d++) {
                int nx = x+dx[d], ny = y+dy[d];
                if (nx>=0 && nx<n && ny>=0 && ny<n && !vis[nx*n+ny])
                    pq.push({min(s, safe[nx][ny]), nx*n+ny});
            }
        }
        return -1;
    }
};
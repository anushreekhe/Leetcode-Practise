class Solution {
public:

    void dfss(int node, vector<int> adj[], vector<int>& vis){
    if(vis[node]==0){
        vis[node]=1;
        
        for(auto it : adj[node]){
            if(vis[it]==0){
                dfss(it, adj, vis);
            }
        }
    }
}

    int findCircleNum(vector<vector<int>>& isConnected) {
        int V=isConnected.size();
        vector<int> adj[V];
        for(int i=0;i<V;i++){
            for(int j=0;j<V;j++){
                if(isConnected[i][j]==1 && i!=j){
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }
        int c=0;
        vector<int> vis(V,0);
        for(int i=0; i<V;i++){
            if(vis[i]==0){
                c++;
                dfss(i,adj,vis);
            }
        }
        return c;
    }
};
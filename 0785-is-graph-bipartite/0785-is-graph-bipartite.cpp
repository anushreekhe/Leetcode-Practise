class Solution {
public:

    bool f(int i, int V, vector<vector<int>>& adj, int color[]){
        queue<int> q;
        q.push(i);
        color[i]=0;
        while(!q.empty()){
            int node=q.front();
            q.pop();
            for(auto it : adj[node]){
                if(color[it]==-1){
                    color[it]=!color[node];
                    q.push(it);
                }
                else if(color[it]==color[node]) return false;
            }
            
        }
        return true;
    }

    bool isBipartite(vector<vector<int>>& graph) {
         int n = graph.size();
    
    int color[n];
    for(int i=0;i<n;i++) color[i]=-1;
    for(int i=0;i<n;i++){
        if(color[i]==-1){
            if(f(i,n,graph,color)==false) return false;   // graph directly pass karo
        }
    }
    return true;
    }
};

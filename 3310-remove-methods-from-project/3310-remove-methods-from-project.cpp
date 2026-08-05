class Solution {
public:
    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {
        vector<vector<int>> adj(n);
        for(auto &inv : invocations){
            adj[inv[0]].push_back(inv[1]);
        }

        vector<int> sus(n,0);
        queue<int> q;
        sus[k]=1;
        q.push(k);
        while(!q.empty()){
            int node=q.front();
            q.pop();
            for(auto it : adj[node]){
                if(sus[it]==0){
                    q.push(it);
                    sus[it]=1;
                }
            }
        }
        for( auto& inv : invocations){
            int a=inv[0];
            int b=inv[1];
            if(sus[a]==0 && sus[b]==1){
                //return everything
                vector<int> ans(n,0);
                for(int i=0;i<n;i++) ans[i]=i;
                return ans;
                }
        }
        vector<int> ans;
        for(int i=0;i<n;i++){
            if(sus[i]==0) ans.push_back(i);
        }
        return ans;
    }
};
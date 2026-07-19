class Solution {
public:

    int f(vector<int>& heights) {
        stack<int> st;
        int maxi=0;
        int n=heights.size();
        for(int i=0; i<=n; i++){
            while(!st.empty() && (i==n || heights[st.top()] >=heights[i])){
                int h=heights[st.top()];
                st.pop();
                int width;
                if(st.empty()) width=i;
                else width=i-st.top()-1;
                maxi=max(maxi, width*h);
            }
            st.push(i);
        }
        return maxi;
    }

    int maximalRectangle(vector<vector<char>>& matrix) {
        int ans=0;
        int n=matrix.size();
        int m=matrix[0].size();
        vector<int> r(m,0);
        for(int i=0;i<n;i++){
            
            for(int j=0;j<m;j++){
                int x=matrix[i][j];
                if(x=='1') r[j]++;
                else r[j]=0;
            }
            ans=max(ans,f(r));
        }
        return ans;
    }
};
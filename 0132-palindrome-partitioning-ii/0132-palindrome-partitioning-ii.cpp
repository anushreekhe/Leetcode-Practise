class Solution {
public:

    bool isPal(int i, int j, string& s){
        
        while(i<j){
            if(s[i]!=s[j]) return false;
            i++;
            j--;
        }
        return true;
    }

    int f(int i, string& s, vector<int>& dp){
        if(i==s.size()) return 0;
        if(dp[i]!=-1) return dp[i];
        int minCost=INT_MAX;
        string temp="";
        for(int j=i;j<s.size();j++){
            temp+=s[j];
            if(isPal(i,j,s)){
                int cost=1+f(j+1,s,dp);
                minCost=min(minCost,cost);
            }
        } 
        return dp[i]=minCost;
    }

    int minCut(string s) {
        if(s.size()==1) return 0;
        vector<int> dp(s.size()+1,-1);
        return f(0, s, dp) -1 ;
    }
};